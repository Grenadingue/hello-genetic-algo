#ifndef     CHART_HPP_
# define    CHART_HPP_

# include <QtCharts/QChart>
# include <QtWidgets/QMainWindow>

QT_CHARTS_USE_NAMESPACE

# include <QtCharts/QChartView>
# include <QtCharts/QLineSeries>
# include <QtCharts/QValueAxis>

class Chart : public QChart
{
    Q_OBJECT

private:
    QMainWindow *_window;
    QChartView *_chartView;
    QLineSeries _currentHightScoreSeries;
    QLineSeries _maximumScoresSeries;
    QValueAxis _axisX;
    QValueAxis _axisY;
    qreal _x;
    qreal _y;
    qreal _maximumScore;

public:
    Chart(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
    virtual ~Chart();

    void initWindow();

public slots:
    void setMaximumScore(int maximumScore);
    void updateHighestScore(int iteration, int highestScore);
};

#endif      // !CHART_HPP_
