#ifndef GRAPHFILTERSERVICE_H
#define GRAPHFILTERSERVICE_H

#include <QObject>
#include <QByteArray>
#include "filter.h"
#include "datasource.h"
#include "spectrograph.h"
#include "spectrumanalyser.h"

class GraphFilterService : public QObject
{
    Q_OBJECT
public:
    explicit GraphFilterService(QObject *parent = 0);

signals:

public slots:

protected:

    //QByteArray m_source_signal;
    QByteArray m_filtered_signal;

    Filter filter;
    WaveFormCustom waveBuilder;
    Spectrograph spectrBuilder;
};

#endif // GRAPHFILTERSERVICE_H
