#include "customfilter.h"

#define GETMASK(index, size) (((1 << (size)) - 1) << (index))
#define READFROM(data, index, size) (((data) & GETMASK((index), (size))) >> (index))
#define WRITETO(data, index, size, value) ((data) = ((data) & (~GETMASK((index), (size)))) | ((value) << (index)))

CustomFilter::CustomFilter(QList<float> params, QObject *parent) : Filter(parent)
{
    parameters = params;
}

QByteArray CustomFilter::doFilter(QAudioFormat format, QByteArray array)
{

    int sampmleSize = format.sampleSize();
    int samplesCount = (array.size()*8)/sampmleSize;
    QByteArray out = QByteArray(array.size(), Qt::Uninitialized);
    if(sampmleSize == 16)
    {
        int16_t *outData = (int16_t *)out.data();
        int16_t *inData = (int16_t *)array.data();

        for (int i=0; i<samplesCount; i++)
        {
            int32_t outDataD =0;
            for (int j=0; j<this->parameters.size(); j++)
            {
                if(i-j>=0)
                {
                    outDataD += parameters[j]*inData[i-j];
                }
            }
            outData[i] = qFloor( outDataD/this->parameters.size());
        }
    }

    return out;
}
