#ifndef CUSTOMFILTER_H
#define CUSTOMFILTER_H

#include <QObject>
#include "filter.h"
#include <QAudioFormat>
#include <QDebug>
#include <QtCore>
/**
 * @brief  Simple filter type. which can use an array of input dividers for filtering
 *
 */
class CustomFilter : public Filter
{
    Q_OBJECT
    QList<float> parameters;
public:
    /**
     * @brief CustomFilter constuctor
     * @param params - array of divider which use for filtering
     * @param parent - parent object (only for CC)
     */
    CustomFilter(QList<float> params, QObject *parent = 0);
    /**
     * @brief doFilter
     * @param format - audio format
     * @param array - input data for filtering
     * @return well done filtered buffer
     */
    QByteArray doFilter(QAudioFormat format, QByteArray array);
signals:

public slots:
};

#endif // CUSTOMFILTER_H
