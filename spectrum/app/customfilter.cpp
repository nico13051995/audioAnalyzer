#include "customfilter.h"

CustomFilter::CustomFilter(QObject *parent) : Filter(parent)
{

}

QByteArray CustomFilter::doFilter(QAudioFormat format, QByteArray array)
{
    char *inData = array.data();
    int sampmleSize = format.sampleType();
    int samplesCount = array.size()/sampmleSize;
    char *outData = array.data();

    for (int i=0; i<samplesCount; i++)
    {
        outData[i]=0.;
        for (int j=0; j<this->size-1; j++)
            if(i-j>=0)
                outData[i]+= parameters[j]*inData[i-j];
    }
}
