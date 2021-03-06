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

#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include <QApplication>
#include <QAudio>
#include <QIcon>
#include <QWidget>
#include <QtQuickWidgets/QQuickWidget>
#include <QtQml/QQmlContext>
#include <QtQuick/QQuickView>
#include <QtQml/QQmlEngine>
#include <QtCore/QDir>
#include "datasource.h"
#include "ui_mainwindow.h"
#include "graphfilterservice.h"
#include "graph.h"

class Engine;
class FrequencySpectrum;
class LevelMeter;
class ProgressBar;
class SettingsDialog;
class Spectrograph;
class Waveform;

namespace Ui {
class MainWindow;
}

QT_BEGIN_NAMESPACE
class QAudioFormat;
QT_END_NAMESPACE

/**
 * Main application widget, responsible for connecting the various UI
 * elements to the Engine.
 */
class MainWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

    // QObject
    void timerEvent(QTimerEvent *event);
signals:
    void modeChanged(int mode);
public slots:
    void stateChanged(QAudio::Mode mode, QAudio::State state);
    void formatChanged(const QAudioFormat &format);
    void spectrumChanged(qint64 position, qint64 length,
                         const FrequencySpectrum &spectrum);
    void errorMessage(const QString &heading, const QString &detail);
    void audioPositionChanged(qint64 position);
    void bufferLengthChanged(qint64 length);

public slots:
    void showFileDialog();
    void showSettingsDialog();
    void initializeRecord();
    void play_pause();
    bool isFullScreen();
    void stop();
    bool saveDump();
    double getDuration();
    double getTimePosition();
    void setTimePosition(double time);
    Graph* addPraph(QString name, int idView);
    QList<int> getPraphIds(int idView);
    Graph *getPraphById(int id, int idView);
    Q_INVOKABLE QStringList getTemplatesQML();
    Q_INVOKABLE bool subscribeToTemplate(Graph * graph, QXYSeries *set, int chanel);
    Q_INVOKABLE bool unSubscribeToTemplate(Graph * graph, QXYSeries *set, int chanel);
    Q_INVOKABLE void changePlayTemplate(QString name);

    /**
     * @brief switch to full screen mode
     */
    void switchFullScreen();
    /**
     * @brief create image from current tab
     */
    void getScreenShot();
protected:
    void keyReleaseEvent(QKeyEvent *event);
    void keyPressEvent(QKeyEvent *event);

protected slots:
    void aboutQt();
private:
    /**
     * @brief init custom UI
     */
    void createUi();
    /**
     * @brief createMenus
     * @deprecated
     */
    void createMenus();
    /**
     * @brief connect UI to event handels
     */
    void connectUi();
    /**
     * @brief reset UI
     */
    void reset();

    enum Mode {
        NoMode = 0,
        RecordMode = 1,
        LoadFileMode = 2
    };

    void setMode(Mode mode);

private:
    Mode                    m_mode;

    Engine*                 m_engine;

#ifndef DISABLE_WAVEFORM
    Waveform*               m_waveform;
#endif
    QQuickWidget viewer;


    SettingsDialog*         m_settingsDialog;
    QMap<int,QMap<int,Graph*>> graphs;
    Ui::MainWindow *ui;
    bool eventFilter(QObject *Object, QEvent *Event);
    /********************************************//**
     *  Not use, peleas ignore this variables!!!
     ***********************************************/
    WaveFormCustom *dataSource;
    ProgressBar*            m_progressBar;
    Spectrograph*           m_spectrograph;
    LevelMeter*             m_levelMeter;


};

#endif // MAINWIDGET_H
