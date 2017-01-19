/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef SPECTROGRAPH_H
#define SPECTROGRAPH_H

#include "frequencyspectrum.h"
#include "spectrumanalyser.h"
#include <QAudioFormat>
#include <QWidget>
#include <QtCharts/QXYSeries>

/**
 * Service which displays a spectrograph showing the frequency spectrum
 * of the window of audio samples most recently analyzed by the Engine.
 */

QT_BEGIN_NAMESPACE
class QQuickWidget;
QT_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class Spectrograph : public QObject
{
    Q_OBJECT
    int                 m_spectrumBufferLength;
    QByteArray          m_spectrumBuffer;
    SpectrumAnalyser    m_spectrumAnalyser;
    qint64  m_spectrumPosition;
    QByteArray          m_buffer;
    QList<QXYSeries*> subscribtionList;

public:
    explicit Spectrograph(QObject *parent = 0);
    ~Spectrograph();

    void setParams(int numBars, qreal lowFreq, qreal highFreq);

    // QObject
    void timerEvent(QTimerEvent *event);

signals:
    void infoMessage(const QString &message, int intervalMs);

public slots:
    void reset();
    void spectrumChanged(const FrequencySpectrum &spectrum);

    void setWindowFunction(WindowFunction type);
    void calculateSpectrum(QByteArray &m_buffer, qint64 position);
    void setFormat(const QAudioFormat &format);
    void bufferChanged(qint64 position, qint64 length, const QByteArray &buffer);

    void subsctibeChart(QXYSeries *set);
    void unSubsctibeChart(QXYSeries *set);
    int getBarNumber();
private:
    int barIndex(qreal frequency) const;
    QPair<qreal, qreal> barRange(int barIndex) const;
    void updateBars();

    void selectBar(int index);

private:
    /**
     * @brief The Bar struct
     * use only for image scpectr
     */
    struct Bar {
        Bar() : value(0.0), clipped(false) { }
        qreal   value;
        bool    clipped;
    };

    QVector<Bar>        m_bars;
    int                 m_barSelected;
    int                 m_timerId;
    qreal               m_lowFreq;
    qreal               m_highFreq;
    FrequencySpectrum   m_spectrum;

    QAudioFormat m_format;
};

#endif // SPECTROGRAPH_H
