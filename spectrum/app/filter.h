#ifndef FILTER_H
#define FILTER_H

#include <QObject>

class Filter : public QObject
{
    Q_OBJECT
public:
    explicit Filter(QObject *parent = 0);

signals:

public slots:
};

#endif // FILTER_H
