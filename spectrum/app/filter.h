#ifndef FILTER_H
#define FILTER_H

#include <QObject>
#include <QAudioFormat>

class Filter : public QObject
{
    Q_OBJECT
private:
    QString name;
public:
    explicit Filter(QObject *parent = 0);
    virtual QByteArray doFilter(QAudioFormat format, QByteArray array) = 0;

    QString getName() const;
    void setName(const QString &value);

signals:

public slots:
};

#endif // FILTER_H
