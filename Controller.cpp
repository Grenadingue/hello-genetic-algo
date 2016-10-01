#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include "Controller.hpp"
#include "Chart.hpp"

#include <QDebug>

Controller::Controller()
    : _geneticAlgo(new Worker)
{
    qDebug() << Q_FUNC_INFO;

    _geneticAlgo->moveToThread(&_workerThread);

    connect(this, &Controller::startAlgo, _geneticAlgo, &Worker::doWork);
    connect(_geneticAlgo, &Worker::updateHighestScore, &_view, &Chart::updateHighestScore);
    connect(&_workerThread, &QThread::finished, _geneticAlgo, &QObject::deleteLater);
}

Controller::~Controller()
{
    qDebug() << Q_FUNC_INFO;

    _workerThread.quit();
    _workerThread.wait();
}

void Controller::start()
{
    qDebug() << Q_FUNC_INFO;

    _view.initWindow();
    _workerThread.start();
    emit startAlgo();
}
