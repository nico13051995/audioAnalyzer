#ifndef NULLFILTER_H
#define NULLFILTER_H

#include "filter.h"
/**
 * @brief The NullFilter class
 * @author Nicolas
 */
class NullFilter : public Filter
{
public:
    NullFilter();
    QByteArray doFilter(QAudioFormat format, QByteArray array);
};

#endif // NULLFILTER_H
