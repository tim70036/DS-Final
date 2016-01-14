#ifndef PriceTableADT_h
#define PriceTableADT_h

#include <map>
#include <iostream>
#include "ConstParams.h"
#include <sstream>

//price table of the 12 stations
class PriceTableADT
{
protected:
    //=================================================================
    // the distance table between each pair of stations
    // distTable.at("Danshui").at(["Hongshulin"]) means the distance
    // from "Danshui" to "Hongshulin"
    //=================================================================
    std::map< std::string, std::map<std::string, int> > distTable;
    
public:
    //=================================================================
    // calculate the all paris shortest patch and store the results
    // in this->distTable
    //=================================================================
    virtual void calcAllPairsShortestPath(std::string mapFile);

    //=================================================================
    // calculate and return the rental when an ubike is returned
    //=================================================================
    virtual int calcPrice(int milageDiff, std::string bClass,
                          std::string from, std::string toStation);
    
    
    //=================================================================
    // constructor
    //=================================================================
    PriceTableADT();
};

#endif /* DistTableADT_hpp */
