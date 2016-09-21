#include "Worker.hpp"

#include <QDebug>

Worker::Worker()
{
    qDebug() << Q_FUNC_INFO;
}

Worker::~Worker()
{
    qDebug() << Q_FUNC_INFO;
}

void Worker::doWork()
{
    qDebug() << Q_FUNC_INFO;

    int i = 0;
    emit updateHighestScore(i, i);
    ++i;
    emit updateHighestScore(i, i);
    ++i;
    emit updateHighestScore(i, i);
    ++i;
    emit updateHighestScore(i, i);
    ++i;
    emit updateHighestScore(i, i);
    ++i;
}
