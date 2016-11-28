#ifndef CUSTOMFILTER_H
#define CUSTOMFILTER_H

#include <QObject>
#include "filter.h"
#include <QAudioFormat>
#include <QDebug>
#include <QtCore>

class CustomFilter : public Filter
{
    Q_OBJECT
    QList<float> parameters;
public:
    CustomFilter(QList<float> params, QObject *parent = 0);
    QByteArray doFilter(QAudioFormat format, QByteArray array);
signals:

public slots:
};

#endif // CUSTOMFILTER_H
