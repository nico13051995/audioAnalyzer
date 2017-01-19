#include "graphfilterservice.h"
#include "engine.h"

GraphFilterService::GraphFilterService(Engine *engine, QList<Filter *> &filters, QObject *parent) : QObject(parent)
{
    spectrBuilder.setParams(SpectrumNumBands, SpectrumLowFreq, SpectrumHighFreq);
    this->filters = filters;
    this->engine = engine;
    this->format = engine->format();
    qDebug() << this->format.sampleSize();
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
    this->format = format;
    waveBuilder.setFormat(format);
    spectrBuilder.setFormat(format);
}

void GraphFilterService::bufferChanged(qint64 position, qint64 length, const QByteArray &buffer){
    QByteArray filtered = applyFilters(buffer);
    waveBuilder.bufferChanged(position, length, filtered);
    spectrBuilder.bufferChanged(position, length, filtered);
}

QByteArray GraphFilterService::applyFilters(const QByteArray &buffer)
{
    QByteArray filtered = filters[0]->doFilter(format, buffer);//QByteArray(buffer.size(), Qt::Initialization);
    for(int i = 1; i < filters.size(); i++)
    {
        filters[i]->doFilter(format, filtered);
    }
    return filtered;
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

    if(engine->getFile() != NULL)
    {
        QFile file(engine->getFile()->fileName());
        if(file.open(QFile::ReadOnly))
        {
            qint64 startByte = engine->getFile()->headerLength() + audioLength(format, start);
            qDebug() << startByte;
            qint64 length = audioLength(format, end);
            file.seek(startByte);
            QByteArray data = file.read(length);
            out->write(applyFilters(data));
        }
    }
    out->close();
}

void GraphFilterService::subscribeWaveForm(QXYSeries *set, int chanel)
{
    waveBuilder.subscribeSeries(set, chanel);
}

void GraphFilterService::unSubscribeWaveFormm(QXYSeries *set, int chanel)
{
    waveBuilder.unSubscribeSeries(set, chanel);
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


