#include "clostpair.h"

#include <set>
#include <cmath>
#include <cfloat>
#include <chrono>
#include <cstdio>
#include <random>
#include <iostream>

#include <QProgressBar>

/* 默认点数量 */
const size_t ClostPair::DEFAULT_SZ = 107;

/* 默认坐标范围 */
const int ClostPair::DEFAULT_WIDTH = 307;
const int ClostPair::DEFAULT_HEIGHT = 207;

/* 随机数生成器校正参数 */
const int ClostPair::TIMES = 5381;
const double ClostPair::TIMES_DB = 5381.0;

//构造函数
ClostPair::ClostPair(QObject *parent) : QObject(parent) {
    RANGE_WIDTH_MIN = -ClostPair::DEFAULT_WIDTH;
    RANGE_WIDTH_MAX = ClostPair::DEFAULT_WIDTH;
    RANGE_HEIGHT_MIN = -ClostPair::DEFAULT_HEIGHT;
    RANGE_HEIGHT_MAX = ClostPair::DEFAULT_HEIGHT;
    int _size = ClostPair::DEFAULT_SZ;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    rd = random_engine(seed);
    std::set<std::pair<clost_pair_type, clost_pair_type> > vis;
    for (int i = 0; i < _size; ++i) {
        auto it = generate();
        /*
         * a simple way to reduce the posibility of generating multi same points.
         * remove the upper-bound times if needed a absolute single point set,
         * BUT BE CARE OF the case that NO MORE SPACE for new points!
         */
        for (int j = 0; vis.find(it) != vis.end() && j < 7; ++j) {
            it = generate();
        }
        vis.insert(it);
        points.emplace_back(it);
    }
    //best = std::make_pair(-1, -1);
}

//构造函数
ClostPair::ClostPair(size_t sz) {
    int _size = sz;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //依系统当前时钟周期数获得一个种子
    rd = random_engine(seed);
    for (int i = 0; i < _size; ++i) {
        points.emplace_back(generate());
    }
#ifdef DEBUG
    fputs("constructor:", stderr);
    print();
    fputs("", stderr);
#endif
    //best = std::make_pair(-1, -1);
}

//构造函数
ClostPair::ClostPair(double sz) : ClostPair((size_t)sz) {
}

//随机数生成器，返回一个以CLOST_PAIR_TYPE_INT/CLOST_PAIR_TYPE_DOUBLE为坐标类型的随机点
inline std::pair<clost_pair_type, clost_pair_type> ClostPair::generate() {
#ifdef CLOST_PAIR_TYPE_INT
    return std::make_pair(rd() % (RANGE_WIDTH_MAX - RANGE_WIDTH_MIN) + RANGE_WIDTH_MIN),
            rd() % (RANGE_HEIGHT_MAX - RANGE_HEIGHT_MIN) + RANGE_HEIGHT_MIN);
#elif defined CLOST_PAIR_TYPE_DBL
    return std::make_pair(rd() % ((RANGE_WIDTH_MAX - RANGE_WIDTH_MIN) * TIMES) / TIMES_DB + RANGE_WIDTH_MIN,
                          rd() % ((RANGE_HEIGHT_MAX - RANGE_HEIGHT_MIN) * TIMES) / TIMES_DB + RANGE_HEIGHT_MIN);
#endif
}

//清空点
void ClostPair::clear() {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    rd.seed(seed);
    points.clear();
    //best = std::make_pair(-1, -1);
}

//返回当前点数量
size_t ClostPair::size() {
    return points.size();
}

//生成点
void ClostPair::build(size_t sz, QProgressBar* pb, bool progressBarOn) {
    if (size() != 0U) {
#ifdef DEBUG
        fprintf(stderr, "ClostPair.build(%u) failed, my vector has not been cleared yet(with %d)!", sz, size());
#endif
        return;
    }
    int _size = sz;
    if (!points.empty()) {
        points.clear();
    }
    if (progressBarOn) {
        pb->setRange(0, _size);
        pb->setValue(0);
    }
    for (int i = 1; i <= _size; ++i) {
        points.emplace_back(generate());
        if (progressBarOn) {
            pb->setValue(i);
        }
    }
#ifdef DEBUG
    fprintf(stderr, "resize to %d:", sz);
    for (auto it: points) {
        fprintf(stderr, " (%d, %d)", it.first, it.second);
    }
    fputs("", stderr);
#endif
}

//重建点数据，清空&生成
void ClostPair::rebuild(size_t sz, QProgressBar* pb, bool progressBarOn) {
    clear();
    build(sz, pb, progressBarOn);
}

//比较函数，按点纵坐标为第一关键字比较
inline bool cmp(const std::pair<clost_pair_type, clost_pair_type>& pa,
                const std::pair<clost_pair_type, clost_pair_type>& pb) {
    return pa.second < pb.second;
}

//分治求解最近点对
double ClostPair::devideAndConquer(std::vector<std::pair<clost_pair_type, clost_pair_type> >::iterator a, int n, QProgressBar* pb, bool progressBarOn) {
    if (n <= 1) {
        if (progressBarOn) {
            pb->setValue(size() - (a - points.begin()));
        }
        return FLT_MAX;
    }
    int m = n >> 1;
    double x = (a + m)->first;
    double d = std::min(devideAndConquer(a, m, pb, progressBarOn), devideAndConquer(a + m, n - m, pb, progressBarOn));
    if (d < mindistance) {
        mindistance = d;
    }
    inplace_merge(a, a + m, a + n, cmp); //归并

    std::vector<std::pair<clost_pair_type, clost_pair_type> > b;
    for (int i = 0; i < n; ++i) {
        if (std::abs(a[i].first - x) >= d) {
            continue;
        }
        //从以检查点中纵坐标最大者开始检查
        for (int j = b.size() - 1; j >= 0; --j) {
            double dx = a[i].first - b[b.size() - j - 1].first;
            double dy = a[i].second - b[b.size() - j - 1].second;
            if (dy >= d) {
                break;
            }
            double tmp = sqrt(dx * dx + dy * dy);
            if (tmp < d) {
                d = tmp;
                //更新d,检查能否更新当前已求得的最近点对
                if (mindistance > d) {
                    mindistance = d;
                    best[0] = a[i];
                    best[1] = b[b.size() - j - 1];
                }
            }
        }
        b.push_back(a[i]);
    }
    return d;
}

//求解最近点对主函数
double ClostPair::work(QProgressBar* pb, bool progressBarOn) {
    //std::vector<std::pair<int, int> > gao(points);
    //std::sort(gao.begin(), gao.end());
    //greater比较器按横坐标为第一关键字，对点排序
    std::sort(points.begin(), points.end(),
              std::greater<std::pair<clost_pair_type, clost_pair_type> >());
    mindistance = DBL_MAX;
    if (progressBarOn) {
        pb->setValue(0);
    }
    devideAndConquer(points.begin(), size(), pb, progressBarOn);
    if (progressBarOn) {
        pb->setValue(size());
    }
#ifdef DEBUG
    fprintf(stderr, "\nClostPair::work -> %f\n", mindistance);
    return mindistance;
#else
    return mindistance;
#endif
}

//打印点，中间调试用
void ClostPair::print() {
    fprintf(stderr, "size = %d ", (int)points.size());
    for (auto it: points) {
        std::cerr << it.first << ", " << it.second << std::endl;
    }
    fputs("", stderr);
}

//返回最近点对
std::vector<std::pair<clost_pair_type, clost_pair_type> > ClostPair::getBest() const {
    std::vector<std::pair<clost_pair_type, clost_pair_type> > res;
    res.emplace_back(best[0]);
    res.emplace_back(best[1]);
    return res;
}
