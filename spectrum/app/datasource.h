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

#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QtCore/QObject>
#include <QtCharts/QAbstractSeries>
#include <QAudioFormat>

QT_BEGIN_NAMESPACE
class QQuickWidget;
QT_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

struct SeriesChanel{
    QAbstractSeries *series;
    int chanel;
    SeriesChanel(QAbstractSeries *series, int chanel){
        this->series = series;
        this->chanel = chanel;
    }
};

class WaveFormCustom : public QObject
{
    Q_OBJECT
public:
    explicit WaveFormCustom(QObject *parent = 0);

    QAudioFormat format() const;
    void setFormat(const QAudioFormat &format);

    QByteArray buffer() const;
    void setBuffer(const QByteArray &buffer);



Q_SIGNALS:

public slots:
    void generateData(int type, int rowCount, int colCount);
    void bufferChanged(qint64 position, qint64 length, const QByteArray &buffer);

    QAbstractSeries *getSeries() const;
    void subscribeSeries(QAbstractSeries *value, int chanel);

private:
    QAudioFormat        m_format;
    QByteArray              m_buffer;
    QAbstractSeries *series;
    QQuickWidget *m_appViewer;
    QList<QVector<QPointF>> m_data;

    QList<SeriesChanel> subscriptionList;

    int m_index;


};

#endif // DATASOURCE_H
