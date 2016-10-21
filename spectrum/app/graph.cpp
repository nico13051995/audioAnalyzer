#include "graph.h"

Graph::Graph(QObject *parent) : QObject(parent)
{

}

Graph::Graph(int id, QString name, int chanel, Graph::GRAPHICTYPE type, QString templateName, QObject *parent) : QObject(parent)
{
    this->id = id;
    this->name = name;
    this->chanel = chanel;
    this->type = type;
    this->templateName = templateName;
}
Graph::GRAPHICTYPE Graph::getType() const
{
    return type;
}

void Graph::setType(const GRAPHICTYPE &value)
{
    type = value;
}
int Graph::getChanel() const
{
    return chanel;
}
void Graph::setChanel(int value)
{
    chanel = value;
}
QString Graph::getTemplateName() const
{
    return templateName;
}

void Graph::setTemplateName(const QString &value)
{
    templateName = value;
}
int Graph::getId() const
{
    return id;
}
QString Graph::getName() const
{
    return name;
}

void Graph::setName(const QString &value)
{
    name = value;
}





