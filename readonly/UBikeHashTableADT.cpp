#include "UBikeHashTableADT.h"

void UBikeHashTableADT::addUBikePtr(UBike* ubptr)
{
    throw "UBikeHashTableADT::addUBikePtr";
}

UBike* UBikeHashTableADT::findUBikePtr(std::string license, bool toRemove)
{
    throw "UBikeHashTableADT::findUBikePtr";
}

std::string UBikeHashTableADT::toString() const
{
    std::ostringstream oss;
    for(int i=0; i<256; i++)
    {
        const UBikePtrList &curList = (*this)[i];
        if( curList.empty() )
            continue;
        
        oss << std::setw(4) << i << ": ";
        
        UBikePtrList::const_iterator it = curList.cbegin();
        UBikePtrList::const_iterator itbck = --curList.cend();
        for(;it!=curList.end();it++)
        {
            oss << (*it)->license;
            if( it!=itbck )
                oss << "->";
        }
        oss << std::endl;
    }
    
    return oss.str();
}