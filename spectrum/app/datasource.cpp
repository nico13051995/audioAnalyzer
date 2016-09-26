/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "datasource.h"
#include <QtCharts/QXYSeries>
#include <QtCharts/QAreaSeries>
#include <QtQuick/QQuickView>
#include <QtQuick/QQuickItem>
#include <QtCore/QDebug>
#include <QtCore/QtMath>

QT_CHARTS_USE_NAMESPACE

Q_DECLARE_METATYPE(QAbstractSeries *)
Q_DECLARE_METATYPE(QAbstractAxis *)

WaveFormCustom::WaveFormCustom(QObject *parent) :
    QObject(parent),
    m_index(-1)
{
    qRegisterMetaType<QAbstractSeries*>();
    qRegisterMetaType<QAbstractAxis*>();
}

void WaveFormCustom::bufferChanged(qint64 position, qint64 length, const QByteArray &buffer)
{
    const qint16* base = reinterpret_cast<const qint16*>(buffer.constData());

    //  qDebug() << "length: " << length << "postition: " << position << "size: " << qFloor((length)/16);
    for(int j = 0; j < m_format.channelCount(); j++)
    {
        m_data[j].clear();
    }
    for(int i=0; i < qFloor((length)/m_format.sampleSize())/m_format.channelCount(); i++)
        for(int j = 0; j < m_format.channelCount(); j++)
        {
            m_data[j].append(QPointF(i, base[i*m_format.channelCount() +  j]));
        }

    for(int j = 0; j < subscriptionList.size(); j++)
    {
        SeriesChanel obj = subscriptionList.at(j);
        QXYSeries *xySeries = static_cast<QXYSeries *>(obj.series);
        xySeries->replace(m_data.at(obj.chanel));
    }



}
QAbstractSeries *WaveFormCustom::getSeries() const
{
    return series;
}

void WaveFormCustom::subscribeSeries(QAbstractSeries *value, int channelCount)
{
    if(value != NULL && channelCount >= 0 &&  channelCount < m_format.channelCount()  )
        subscriptionList.append(SeriesChanel(value, channelCount));
}

bool WaveFormCustom::unSubscribeSeries(QAbstractSeries *value, int channelCount)
{
    return subscriptionList.removeAll(SeriesChanel(value, channelCount));
}

QByteArray WaveFormCustom::buffer() const
{
    return m_buffer;
}

void WaveFormCustom::setBuffer(const QByteArray &buffer)
{
    m_buffer = buffer;
}

QAudioFormat WaveFormCustom::format() const
{
    return m_format;
}

void WaveFormCustom::setFormat(const QAudioFormat &format)
{
    m_format = format;
    m_data.clear();
    for(int i = 0; i < format.channelCount(); i++)
        m_data.append(QVector<QPointF>());
}


void WaveFormCustom::generateData(int type, int rowCount, int colCount)
{
    // Remove previous data
    foreach (QVector<QPointF> row, m_data)
        row.clear();
    m_data.clear();

    // Append the new data depending on the type
    for (int i(0); i < rowCount; i++) {
        QVector<QPointF> points;
        points.reserve(colCount);
        for (int j(0); j < colCount; j++) {
            qreal x(0);
            qreal y(0);
            switch (type) {
            case 0:
                // data with sin + random component
                y = qSin(3.14159265358979 / 50 * j) + 0.5;
                x = j;
                break;
            case 1:
                // linear data
                x = j;
                y = (qreal) i / 10;
                break;
            default:
                // unknown, do nothing
                break;
            }
            points.append(QPointF(x, y));
        }
        m_data.append(points);
    }
}
