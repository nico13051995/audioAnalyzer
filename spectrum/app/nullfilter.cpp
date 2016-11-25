#include "nullfilter.h"

NullFilter::NullFilter()
{

}

QByteArray NullFilter::doFilter(QAudioFormat format, QByteArray array)
{
    return array;
}

