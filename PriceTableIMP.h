//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************

#ifndef PriceTableIMP_h
#define PriceTableIMP_h

//KEEP-THIS-HEADER-UNTOUCHED
#include "readonly/PriceTableADT.h"

class PriceTableIMP : public PriceTableADT
{
    //DO SOMETHING HERE
public:
    //=================================================================
    // calculate the all paris shortest patch and store the results
    // in this->distTable
    //=================================================================
    void calcAllPairsShortestPath(std::string mapFile);
    
    //=================================================================
    // calculate and return the rental when an ubike is returned
    //=================================================================
    int calcPrice(int milageDiff, std::string bClass,
                          std::string from, std::string toStation);
    

};

#endif

//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************