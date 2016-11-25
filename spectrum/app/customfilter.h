#ifndef CUSTOMFILTER_H
#define CUSTOMFILTER_H

#include <QObject>
#include "filter.h"
#include <QAudioFormat>

class CustomFilter : public Filter
{
    Q_OBJECT
    int size;
    float *parameters;
public:
    CustomFilter(QObject *parent = 0);
    QByteArray doFilter(QAudioFormat format, QByteArray array);
signals:

public slots:
};

#endif // CUSTOMFILTER_H
