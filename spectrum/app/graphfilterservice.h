#ifndef GRAPHFILTERSERVICE_H
#define GRAPHFILTERSERVICE_H

#include <QObject>
#include <QByteArray>
#include "filter.h"
#include "datasource.h"
#include "spectrograph.h"
#include "spectrumanalyser.h"


class Engine;

/**
   @author Nicolas
 * @brief The GraphFilterService class
 * This class acts as an intermediate element between the user interface and classes for charts
 *
 */
class GraphFilterService : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief GraphFilterService
     * @param engine - need for auto subscribe to buffer change;
     * @param filters - list of filters which will be apply
     * @param parent
     */
    GraphFilterService(Engine *engine, QList<Filter*>  &filters, QObject *parent = 0);
    ~GraphFilterService();
    QString getName() const;
    void setName(const QString &value);

signals:

public slots:
    void bufferChanged(qint64 position, qint64 length, const QByteArray &buffer);
    /**
     * @brief GraphFilterService::applyFilters
     * @param buffer - data for procces
     * @return performed data
     */
    QByteArray applyFilters(const QByteArray &buffer);
    /**
     * @brief save - function for dump filtered data
     * @param start - start time in mk seconds
     * @param end - finish time in mk seconds
     * @param out - output stream (ex: QFile)
     * @return is success?
     */
    bool save(qint64 start, qint64 end, QIODevice *out);

    /**
     * @brief subscribeWaveForm - subscribe QML Element to visual update after update data;
     * @param set - QML points for inject data
     * @param chanel - number of chanel
     */
    void subscribeWaveForm(QXYSeries *set, int chanel);
    void unSubscribeWaveFormm(QXYSeries *set, int chanel);

    void subscribeSpectrum(QXYSeries *set, int chanel);
    void unSubscribeSpectrum(QXYSeries *set, int chanel);
private slots:
    void formatChanged(const QAudioFormat &format);
private:
    QByteArray m_filtered_signal;
    QAudioFormat format;

    QList<Filter*>  filters;
    /// object for building wafe form chart
    WaveFormCustom waveBuilder;
    /// object for building spectr chart
    Spectrograph spectrBuilder;
    /// object for play audio
    Engine *engine;
    /// name which will be show in UI
    QString name;
};

#endif // GRAPHFILTERSERVICE_H
