#include "PriceTableADT.h"

void PriceTableADT::calcAllPairsShortestPath(std::string mapFile)
{
    throw "PriceTableADT::calcAllPairsShortestPath";
}

int PriceTableADT::calcPrice
(int milageDiff, std::string bClass, std::string from, std::string toStation)
{
    throw "PriceTableADT::calcPrice";
}

PriceTableADT::PriceTableADT()
{
    for(int i=0;i<StationNum;i++) for(int j=0;j<StationNum;j++)
    {
        const std::string &sti = StationNames[i];
        const std::string &stj = StationNames[j];
        this->distTable[sti][stj];
    }
}
