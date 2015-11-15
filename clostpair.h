#ifndef CLOSTPAIR_H
#define CLOSTPAIR_H

#include <QObject>
#include <vector>
#include <random>
#include <utility>

#ifdef CLOST_PAIR_TYPE_DBL
typedef double clost_pair_type;
#else
typedef int clost_pair_type;
#endif

//typedef subtract_with_carry_engine<unsigned,24,10,24> random_engine;
typedef std::mt19937 random_engine; //随机数引擎，std::mt19937为19937位伪随机生成器，C++11/random

class MainWindow;
class QProgressBar;

class ClostPair : public QObject
{
    Q_OBJECT
public:
    /* 构造函数 */
    explicit ClostPair(QObject *parent = 0);
    ClostPair(size_t sz);
    ClostPair(double sz);

    size_t size(); //返回大小
    void print(); //打印所有点坐标
    std::vector<std::pair<clost_pair_type, clost_pair_type> > getBest() const; //返回最近点对
    friend class MainWindow;

    void clear(); //清空
    void build(size_t sz = 0, QProgressBar* pb = NULL, bool progressBarOn = false); //构造随机数据
    void rebuild(size_t sz = 0, QProgressBar* pb = NULL, bool progressBarOn = false); //重建点数据
    double work(QProgressBar* pb, bool progressBarOn = false); //计算最近点对
    //void setRange(int range); //点坐标范围控制接口
    static const size_t DEFAULT_SZ;
signals:

public slots:

private:
    /* functions */
    std::pair<clost_pair_type, clost_pair_type> generate(); //返回一个随机点
    double devideAndConquer(std::vector<std::pair<clost_pair_type, clost_pair_type> >::iterator a, int n, QProgressBar* pb, bool progressBarOn = false); //分治算法

    /* members */
    random_engine rd; //随机数引擎
    std::vector<std::pair<clost_pair_type, clost_pair_type> > points; //保存点坐标的数组
    std::pair<clost_pair_type, clost_pair_type> best[2]; //最近点对的两个点
    double mindistance; //最近点对间的距离
    int RANGE_WIDTH_MIN; //横坐标(x)范围，[RANGE_WIDTH_MIN, RANGE_WIDTH_MAX)
    int RANGE_WIDTH_MAX;
    int RANGE_HEIGHT_MIN; //纵坐标(y)范围，[RANGE_HEIGHT_MIN, RANGE_HEIGHT_MAX)
    int RANGE_HEIGHT_MAX;

    /* static members */
    static const int DEFAULT_WIDTH; //默认横坐标范围
    static const int DEFAULT_HEIGHT; //默认纵坐标范围
    /* 用于随机浮点数生成的辅助参数 */
    static const int TIMES;
    static const double TIMES_DB;
};

#endif // CLOSTPAIR_H
