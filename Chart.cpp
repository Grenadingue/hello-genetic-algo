#include "Chart.hpp"

#include <QDebug>

Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(parent, wFlags),
    _window(new QMainWindow),
    _chartView(new QChartView(this)),
    _currentHightScoreSeries(this),
    _maximumScoresSeries(this),
    _x(0),
    _y(0),
    _maximumScore(0)
{
    QPen redPen(Qt::red);
    QPen bluePen(Qt::blue);

    qDebug() << Q_FUNC_INFO;

    // Set pens width
    redPen.setWidth(2);
    bluePen.setWidth(2);

    // Set pens color
    _currentHightScoreSeries.setPen(redPen);
    _maximumScoresSeries.setPen(bluePen);

    // Set serie's name
    _currentHightScoreSeries.setName("Best individual score");
    _maximumScoresSeries.setName("Maximum individual score");

    // Set x axis legend
    _axisX.setTitleText("x = number of iterations");
    _axisX.setTitleVisible(true);

    // Set y axis legend
    _axisY.setTitleText("y = individual score");
    _axisY.setTitleVisible(true);

    // Init current hight score serie in axis
    addSeries(&_currentHightScoreSeries);
    setAxisX(&_axisX, &_currentHightScoreSeries);
    setAxisY(&_axisY, &_currentHightScoreSeries);

    // Init maximum scores serie in axis
    addSeries(&_maximumScoresSeries);
    setAxisX(&_axisX, &_maximumScoresSeries);
    setAxisY(&_axisY, &_maximumScoresSeries);

    // Init current hight score serie first point at (0; 0)
    _currentHightScoreSeries.append(_x, _y);
}

Chart::~Chart()
{
}

void Chart::initWindow()
{
    qDebug() << Q_FUNC_INFO;

    _chartView->setRenderHint(QPainter::Antialiasing);
    setTitle("Genetic algorithm string finder");
    _window->setCentralWidget(_chartView);
    _window->resize(800, 600);
    _window->show();
}

void Chart::updateHighestScore(int iteration, int highestScore)
{
    qDebug() << Q_FUNC_INFO << iteration << highestScore;

    _x = iteration;
    _y = highestScore;
    axisX()->setRange(0, _x + 10);
    axisY()->setRange(0, _y + 10);
    _currentHightScoreSeries.append(_x, _y);
}
