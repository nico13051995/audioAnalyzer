#ifndef GRAPH_H
#define GRAPH_H

#include <QObject>

class Graph : public QObject
{
    Q_OBJECT
public:
    enum GRAPHICTYPE
    {
        SPECTR = 2,
        WAVE = 1,
        STYLE_FILLED
    };
    Q_ENUMS(GRAPHICTYPE)
    explicit Graph(QObject *parent = 0);
    Graph(int id, QString name, int chanel, GRAPHICTYPE type, QString templateName, QObject *parent = 0);

signals:

public slots:
    GRAPHICTYPE getType() const;
    void setType(const GRAPHICTYPE &value);

    int getChanel() const;
    void setChanel(int value);

    QString getTemplateName() const;
    void setTemplateName(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    int getId() const;
private:
    int id;
    QString name;
    GRAPHICTYPE type;
    int chanel;
    QString templateName;
};

#endif // GRAPH_H
