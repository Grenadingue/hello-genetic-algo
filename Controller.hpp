#ifndef     CONTROLLER_HPP_
# define    CONTROLLER_HPP_

# include <QThread>
# include "Worker.hpp"
# include "Chart.hpp"

class Controller : public QObject
{
    Q_OBJECT

private:
    QThread _workerThread;
    Worker *_geneticAlgo;
    Chart _view;

public:
    Controller();
    ~Controller();

    void start();

signals:
    void startAlgo();
};

#endif     // !CONTROLLER_HPP_
