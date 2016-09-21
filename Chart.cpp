#include "Chart.hpp"

#include <QDebug>

Chart::Chart()
{
    qDebug() << Q_FUNC_INFO;
}

Chart::~Chart()
{
    qDebug() << Q_FUNC_INFO;
}

void Chart::updateHighestScore(int iteration, int highestScore)
{
    qDebug() << Q_FUNC_INFO << iteration << highestScore;
}
