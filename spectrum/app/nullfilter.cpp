#include "nullfilter.h"

NullFilter::NullFilter()
{

}

QByteArray NullFilter::doFilter(QByteArray array)
{
    return array;
}

