#include "graphfilterservice.h"
#include "engine.h"

GraphFilterService::GraphFilterService(Engine *engine, QList<Filter *> &filters, QObject *parent) : QObject(parent)
{
    this->filters = filters;
    this->engine = engine;
    if(engine == NULL)
        throw "ENGINE IS NULL" ;
    CHECKED_CONNECT(engine, SIGNAL(bufferChanged(qint64, qint64, const QByteArray &)),
                        this, SLOT(bufferChanged(qint64, qint64, const QByteArray &)));
    CHECKED_CONNECT(engine,  SIGNAL(formatChanged(const QAudioFormat &)),
               this, SLOT(formatChanged(const QAudioFormat &)));
   /* CHECKED_CONNECT(engine, SIGNAL(bufferChanged(qint64, qint64, const QByteArray &)),
                    &waveBuilder, SLOT(bufferChanged(qint64, qint64, const QByteArray &)));
    CHECKED_CONNECT(engine, SIGNAL(bufferChanged(qint64, qint64, const QByteArray &)),
                    &spectrBuilder, SLOT(bufferChanged(qint64, qint64, const QByteArray &)));*/
}
GraphFilterService::~GraphFilterService()
{
    if(engine != NULL)
    {
        disconnect(engine, SIGNAL(bufferChanged(qint64, qint64, const QByteArray &)),
                   this, SLOT(bufferChanged(qint64, qint64, const QByteArray &)));
        disconnect(engine, SIGNAL(formatChanged(const QAudioFormat &)),
                   this, SLOT(formatChanged(const QAudioFormat &format)));
  /*      disconnect(engine, SIGNAL(bufferChanged(qint64, qint64, const QByteArray &)),
                   &waveBuilder, SLOT(bufferChanged(qint64, qint64, const QByteArray &)));
        disconnect(engine, SIGNAL(bufferChanged(qint64, qint64, const QByteArray &)),
                   &spectrBuilder, SLOT(bufferChanged(qint64, qint64, const QByteArray &)));*/
    }
}

void GraphFilterService::formatChanged(const QAudioFormat &format)
{
    waveBuilder.setFormat(format);
    spectrBuilder.setFormat(format);
}

void GraphFilterService::bufferChanged(qint64 position, qint64 length, const QByteArray &buffer){
    waveBuilder.bufferChanged(position, length, buffer);
    spectrBuilder.bufferChanged(position, length, buffer);
}

bool GraphFilterService::save(qint64 start, qint64 end, QIODevice *out)
{
    if(out == NULL)
    {
        qWarning() << "IO == NULL(file)!!!";
        return false;
    }

    if(!out->isOpen())
    {
        qWarning() << "Out not init, try do it!!!";
        if(!out->open(QIODevice::WriteOnly))
        {
            qWarning() << "Couldn't open IO(file)!!!";
            return false;
        }
    }
    /*
     * CODE FOR WRITE
    */
    out->close();
}

void GraphFilterService::subscribeWaveForm(QXYSeries *set, int chanel)
{
    waveBuilder.subscribeSeries(set, chanel);
}

void GraphFilterService::unSubscribeWaveFormm(QXYSeries *set, int chanel)
{
    waveBuilder.subscribeSeries(set, chanel);
}

void GraphFilterService::subscribeSpectrum(QXYSeries *set, int chanel)
{
    spectrBuilder.subsctibeChart(set);
}

void GraphFilterService::unSubscribeSpectrum(QXYSeries *set, int chanel)
{
    spectrBuilder.unSubsctibeChart(set);
}

QString GraphFilterService::getName() const
{
    return name;
}

void GraphFilterService::setName(const QString &value)
{
    name = value;
}


