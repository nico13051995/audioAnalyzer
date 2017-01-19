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

#include "engine.h"
#include "levelmeter.h"
#include "mainwidget.h"
#include "waveform.h"
#include "progressbar.h"
#include "settingsdialog.h"
#include "spectrograph.h"
#include "utils.h"

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStyle>
#include <QMenu>
#include <QFileDialog>
#include <QTimerEvent>
#include <QMessageBox>

const int NullTimerId = -1;

MainWidget::MainWidget(QWidget *parent)
    :   QMainWindow(parent)
    ,   m_mode(NoMode)
    ,   m_engine(new Engine(this))
    #ifndef DISABLE_WAVEFORM
    ,   m_waveform(new Waveform(this))
    #endif
    ,   m_progressBar(new ProgressBar(this))
    ,   m_spectrograph(new Spectrograph(this))
    ,   m_levelMeter(new LevelMeter(this))
    ,   ui(new Ui::MainWindow)
    ,   m_settingsDialog(new SettingsDialog(
                             m_engine->availableAudioInputDevices(),
                             m_engine->availableAudioOutputDevices(),
                             this))
{

    m_spectrograph->setParams(SpectrumNumBands, SpectrumLowFreq, SpectrumHighFreq);
   // QCoreApplication::instance()->installEventFilter(this);
    createUi();
    connectUi();
}

MainWidget::~MainWidget()
{

}


//-----------------------------------------------------------------------------
// Public slots
//-----------------------------------------------------------------------------

void MainWidget::stateChanged(QAudio::Mode mode, QAudio::State state)
{
    Q_UNUSED(mode);

    if (QAudio::ActiveState != state && QAudio::SuspendedState != state) {
        m_levelMeter->reset();
        m_spectrograph->reset();
    }
}

void MainWidget::formatChanged(const QAudioFormat &format)
{
    dataSource->setFormat(format);
    m_spectrograph->setFormat(format);
#ifndef DISABLE_WAVEFORM
    if (QAudioFormat() != format) {
        m_waveform->initialize(format, WaveformTileLength,
                               WaveformWindowDuration);
    }
#endif
}

void MainWidget::spectrumChanged(qint64 position, qint64 length,
                                 const FrequencySpectrum &spectrum)
{
    m_progressBar->windowChanged(position, length);
    // m_spectrograph->spectrumChanged(spectrum);
}

void MainWidget::errorMessage(const QString &heading, const QString &detail)
{
    QMessageBox::warning(this, heading, detail, QMessageBox::Close);
}

void MainWidget::timerEvent(QTimerEvent *event)
{

}

void MainWidget::audioPositionChanged(qint64 position)
{
#ifndef DISABLE_WAVEFORM
    m_waveform->audioPositionChanged(position);
#else
    Q_UNUSED(position)
#endif
}

void MainWidget::bufferLengthChanged(qint64 length)
{
    m_progressBar->bufferLengthChanged(length);
}


//-----------------------------------------------------------------------------
// Private slots
//-----------------------------------------------------------------------------

void MainWidget::showFileDialog()
{
    const QString dir;
    const QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open WAV file"), dir, "*.wav");
    if (fileNames.count() && QFile(fileNames.front()).exists()) {
        reset();
        setMode(LoadFileMode);
        m_engine->loadFile(fileNames.front());

    }
    m_engine->startPlayback();
    m_engine->suspend();
}

void MainWidget::aboutQt()
{
    QMessageBox::aboutQt(this);
}

void MainWidget::showSettingsDialog()
{
    m_settingsDialog->exec();
    if (m_settingsDialog->result() == QDialog::Accepted) {
        m_engine->setAudioInputDevice(m_settingsDialog->inputDevice());
        m_engine->setAudioOutputDevice(m_settingsDialog->outputDevice());
        m_engine->setWindowFunction(m_settingsDialog->windowFunction());
    }
    /*
    QSize size = viewer.size();
    viewer.setFixedSize(60, 60);
    viewer.grabFramebuffer().save("test.png");
    viewer.setFixedSize(size);
    viewer.setAutoFillBackground(true);
    */
}

void MainWidget::getScreenShot(){
    /*QSize size = viewer.size();
    viewer.setFixedSize(9000, ((double)size.height()/size.width())*9000);
    QImage img = viewer.grabFramebuffer();
    viewer.setFixedSize(size);
    viewer.setAutoFillBackground(true);*/
    QImage img = viewer.grabFramebuffer();
    QString filter;
    QString path = QFileDialog::getSaveFileName(this, QString(), "screenShot.png","PNG (*.png);;JPG (*.jpg);;  GIF (*.gif)", &filter);
    if(path.isEmpty() == false)
    {
        if(filter.isEmpty())
            path += ".png";
        img.save(path);
    }
}

void MainWidget::initializeRecord()
{
    reset();
    setMode(RecordMode);
    if (m_engine->initializeRecord())
    {
        m_engine->startRecording();
        ///////////////////////////////////////////////////////////RECORD START
    }

}

void MainWidget::play_pause()
{
    if(m_engine->state() == QAudio::SuspendedState || m_engine->state() == QAudio::StoppedState)
        m_engine->startPlayback();
    else
        if(m_engine->state() == QAudio::ActiveState)
            m_engine->suspend();

}

bool MainWidget::isFullScreen()
{
    return QMainWindow::isFullScreen();
}

void MainWidget::stop()
{
    m_engine->stopPlayback();
}

bool MainWidget::saveDump()
{
    QBuffer buf;
    buf.open(QBuffer::ReadWrite);
    m_engine->getFilterTempateForPlay()->save(0, m_engine->getDuration(), &buf);
    WavFile::saveWAV("test.wav", buf.data(), m_engine->format());
}

double MainWidget::getDuration()
{
    return m_engine->getDuration();
}

double MainWidget::getTimePosition()
{
    return m_engine->getTimePosition();
}

void MainWidget::setTimePosition(double time)
{
    m_engine->setTimePosition(time);
}

Graph *MainWidget::addPraph(QString name, int idView)
{
    Graph *nGraph = new Graph(qrand(), name, 0, Graph::WAVE, getTemplatesQML().first(), this);
    graphs[idView].insert(nGraph->getId(), nGraph);
    return nGraph;
}

QList<int> MainWidget::getPraphIds(int idView)
{
    return graphs[idView].keys();
}

Graph *MainWidget::getPraphById(int id, int idView)
{
    return graphs[idView][id];
}

QStringList MainWidget::getTemplatesQML()
{
    return m_engine->getCreatedTemplates().keys();;
}

bool MainWidget::subscribeToTemplate(Graph *graph, QXYSeries *set, int chanel)
{
    if(graph == NULL)
        return false;
    GraphFilterService* servise = m_engine->getCreatedTemplates().value(graph->getTemplateName());
    if(servise == NULL)
        return false;

    switch (graph->getType()) {
    case Graph::SPECTR:
        servise->subscribeSpectrum(set, chanel);
        break;
    case Graph::WAVE:
        servise->subscribeWaveForm(set, chanel);
        break;
    default:
        return false;
        break;
    }
    return true;
}

bool MainWidget::unSubscribeToTemplate(Graph *graph, QXYSeries *set, int chanel)
{
    if(graph == NULL)
        return false;
    GraphFilterService* servise = m_engine->getCreatedTemplates().value(graph->getTemplateName());
    if(servise == NULL)
        return false;

    switch (graph->getType()) {
    case Graph::SPECTR:
        servise->unSubscribeSpectrum(set, chanel);
        break;
    case Graph::WAVE:
        servise->unSubscribeWaveFormm(set, chanel);
        break;
    default:
        return false;
        break;
    }
    return true;
}

void MainWidget::changePlayTemplate(QString name)
{
    m_engine->setPlayTemplate(name);
}

void MainWidget::keyReleaseEvent(QKeyEvent *event)
{
    QMainWindow::keyReleaseEvent(event);
    switch (event->key()) {
    case Qt::Key_F11:
        switchFullScreen();
        break;
    default:
        break;
    }
}

void MainWidget::keyPressEvent(QKeyEvent *event)
{
    QMainWindow::keyPressEvent(event);
    event->setAccepted(false);
}

bool MainWidget::eventFilter(QObject *Object, QEvent *Event)
{
    if (Event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = (QKeyEvent*)Event;
        keyReleaseEvent(keyEvent);
    }
}


//-----------------------------------------------------------------------------
// Private functions
//-----------------------------------------------------------------------------

void MainWidget::switchFullScreen()
{
    if(this->isFullScreen())
        this->showNormal();
    else
        this->showFullScreen();
}

void MainWidget::createUi()
{

    /*viewer.engine()->addImportPath(extraImportPath.arg(QGuiApplication::applicationDirPath(),
                                      QString::fromLatin1("qml")));*/
    QObject::connect(viewer.engine(), &QQmlEngine::quit, this, &QMainWindow::close);

    ui->setupUi(this);
    this->setWindowTitle("Spectrum");
   // this->setWindowIcon(QIcon(":/audio-spectrum-xxl.png"));
    // this->showFullScreen();
    dataSource = new WaveFormCustom(this);


    viewer.rootContext()->setContextProperty("dataSpectr", m_spectrograph);
    viewer.rootContext()->setContextProperty("dataSource", dataSource);
    viewer.rootContext()->setContextProperty("mainWindow", this);

    viewer.setSource(QUrl("qrc:/qml/qmloscilloscope/main.qml"));
    viewer.setResizeMode(QQuickWidget::SizeRootObjectToView);
    //viewer.setColor(QColor("#404040"));
    //    viewer.show();
    ui->gridLayout->addWidget(&viewer);
    this->setFocusPolicy(Qt::StrongFocus);
    //viewer.setFocusProxy(this);
    setFocusProxy(&viewer);
    //viewer.setFocusPolicy(Qt::StrongFocus);
    viewer.grabKeyboard();
}

void MainWidget::connectUi()
{
    CHECKED_CONNECT(m_engine, SIGNAL(stateChanged(QAudio::Mode,QAudio::State)),
                    this, SLOT(stateChanged(QAudio::Mode,QAudio::State)));

    CHECKED_CONNECT(m_engine, SIGNAL(formatChanged(const QAudioFormat &)),
                    this, SLOT(formatChanged(const QAudioFormat &)));

    m_progressBar->bufferLengthChanged(m_engine->bufferLength());

    CHECKED_CONNECT(m_engine, SIGNAL(bufferLengthChanged(qint64)),
                    this, SLOT(bufferLengthChanged(qint64)));

    CHECKED_CONNECT(m_engine, SIGNAL(recordPositionChanged(qint64)),
                    m_progressBar, SLOT(recordPositionChanged(qint64)));

    CHECKED_CONNECT(m_engine, SIGNAL(playPositionChanged(qint64)),
                    m_progressBar, SLOT(playPositionChanged(qint64)));

    CHECKED_CONNECT(m_engine, SIGNAL(recordPositionChanged(qint64)),
                    this, SLOT(audioPositionChanged(qint64)));

    CHECKED_CONNECT(m_engine, SIGNAL(playPositionChanged(qint64)),
                    this, SLOT(audioPositionChanged(qint64)));

    CHECKED_CONNECT(m_engine, SIGNAL(levelChanged(qreal, qreal, int)),
                    m_levelMeter, SLOT(levelChanged(qreal, qreal, int)));

    CHECKED_CONNECT(m_engine, SIGNAL(spectrumChanged(qint64, qint64, const FrequencySpectrum &)),
                    this, SLOT(spectrumChanged(qint64, qint64, const FrequencySpectrum &)));
    /*
    CHECKED_CONNECT(m_engine, SIGNAL(infoMessage(QString, int)),
            this, SLOT(infoMessage(QString, int)));

    CHECKED_CONNECT(m_engine, SIGNAL(errorMessage(QString, QString)),
            this, SLOT(errorMessage(QString, QString)));

    CHECKED_CONNECT(m_spectrograph, SIGNAL(infoMessage(QString, int)),
            this, SLOT(infoMessage(QString, int)));*/

#ifndef DISABLE_WAVEFORM
    /*CHECKED_CONNECT(m_engine, SIGNAL(bufferChanged(qint64, qint64, const QByteArray &)),
                    m_waveform, SLOT(bufferChanged(qint64, qint64, const QByteArray &)));*/
    /*CHECKED_CONNECT(m_engine, SIGNAL(bufferChanged(qint64, qint64, const QByteArray &)),
                    dataSource, SLOT(bufferChanged(qint64, qint64, const QByteArray &)));
    CHECKED_CONNECT(m_engine, SIGNAL(bufferChanged(qint64, qint64, const QByteArray &)),
                    m_spectrograph, SLOT(bufferChanged(qint64, qint64, const QByteArray &)));*/


#endif

}

void MainWidget::createMenus()
{
    /*
    connect(m_loadFileAction, SIGNAL(triggered(bool)), this, SLOT(showFileDialog()));
    connect(m_recordAction, SIGNAL(triggered(bool)), this, SLOT(initializeRecord()));
    */
}


void MainWidget::reset()
{
#ifndef DISABLE_WAVEFORM
    m_waveform->reset();
#endif
    m_engine->reset();
    m_levelMeter->reset();
    m_spectrograph->reset();
    m_progressBar->reset();
}

void MainWidget::setMode(Mode mode)
{
    m_mode = mode;
    emit modeChanged(mode);
}

