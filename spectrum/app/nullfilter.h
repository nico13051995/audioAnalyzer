#ifndef NULLFILTER_H
#define NULLFILTER_H

#include "filter.h"

class NullFilter : public Filter
{
public:
    NullFilter();
    QByteArray doFilter(QByteArray array);
};

#endif // NULLFILTER_H
