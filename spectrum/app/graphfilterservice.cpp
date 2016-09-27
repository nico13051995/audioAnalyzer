#include "graphfilterservice.h"

GraphFilterService::GraphFilterService(QObject *parent) : QObject(parent)
{

}

GraphFilterService::GraphFilterService(QList<Filter *> &filters, QObject *parent) : QObject(parent)
{
    this->filters = filters;
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

void GraphFilterService::subscribeSpectrum(QXYSeries *set)
{
    spectrBuilder.subsctibeChart(set);
}

void GraphFilterService::unSubscribeSpectrum(QXYSeries *set)
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


