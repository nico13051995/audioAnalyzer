#include "filter.h"


QString Filter::getName() const
{
    return name;
}

void Filter::setName(const QString &value)
{
    name = value;
}
Filter::Filter(QObject *parent) : QObject(parent)
{
    
}

