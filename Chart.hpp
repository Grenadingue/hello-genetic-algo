#ifndef     CHART_HPP_
# define    CHART_HPP_

# include <QObject>

class Chart : public QObject
{
    Q_OBJECT

public:
    Chart();
    ~Chart();

public slots:
    void updateHighestScore(int iteration, int highestScore);
};

#endif      // !CHART_HPP_
