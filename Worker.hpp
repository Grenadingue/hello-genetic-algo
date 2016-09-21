#ifndef     WORKER_HPP_
# define    WORKER_HPP_

# include <QObject>

class Worker : public QObject
{
    Q_OBJECT

public:
    Worker();
    ~Worker();

public slots:
    void doWork();

signals:
    void updateHighestScore(int iteration, int highestScore);
};

#endif      // !WORKER_HPP_
