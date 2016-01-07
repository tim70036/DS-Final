#include "UBikeHeapADT.h"

void UBikeHeapADT::addUBikePtr(UBike* ubptr)
{
    throw "UBikeHeapADT::addUBikePtr";
}

UBike* UBikeHeapADT::removeUBikePtr(int heapIndex)
{
    throw "BikeHeapADT::removeUBikePtr";
}

std::string UBikeHeapADT::toString() const
{
    std::ostringstream oss;
    for( int k=1; k<=this->number; k++ )
        oss << this->at(k)->toString() << std::endl;
    oss << std::endl;
    
    return oss.str();
}

bool UBikeHeapADT::isEmpty() const
{
    return this->number<=0;
}