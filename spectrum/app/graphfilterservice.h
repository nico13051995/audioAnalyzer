#ifndef GRAPHFILTERSERVICE_H
#define GRAPHFILTERSERVICE_H

#include <QObject>
#include <QByteArray>
#include "filter.h"
#include "datasource.h"
#include "spectrograph.h"
#include "spectrumanalyser.h"


class Engine;

class GraphFilterService : public QObject
{
    Q_OBJECT
public:
    GraphFilterService(Engine *engine, QList<Filter*>  &filters, QObject *parent = 0);
    ~GraphFilterService();
    QString getName() const;
    void setName(const QString &value);

signals:

public slots:
    void bufferChanged(qint64 position, qint64 length, const QByteArray &buffer);
    bool save(qint64 start, qint64 end, QIODevice *out);

    void subscribeWaveForm(QXYSeries *set, int chanel);
    void unSubscribeWaveFormm(QXYSeries *set, int chanel);

    void subscribeSpectrum(QXYSeries *set, int chanel);
    void unSubscribeSpectrum(QXYSeries *set, int chanel);
private slots:
    void formatChanged(const QAudioFormat &format);
private:
    //QByteArray m_source_signal;
    QByteArray m_filtered_signal;

    QList<Filter*>  filters;
    WaveFormCustom waveBuilder;
    Spectrograph spectrBuilder;
    Engine *engine;

    QString name;
};

#endif // GRAPHFILTERSERVICE_H
