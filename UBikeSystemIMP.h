//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************

#ifndef UBikeSystemIMP_h
#define UBikeSystemIMP_h

//KEEP-THIS-HEADER-UNTOUCHED
#include "readonly/UBikeSystemADT.h"

class UBikeSystemIMP : public UBikeSystemADT
{
    //DO SOMETHINE HERE
public:
    //=================================================================
    // read the map and initialize this->priceTable
    //=================================================================
    void InitDistTable
    (std::string MapFile);
    
    //=================================================================
    // add a new bike to the system
    //=================================================================
    void NewBike
    (std::string classType, std::string license,
     int mile, std::string station);
    
    //=================================================================
    // remove the bike license
    //=================================================================
    void JunkIt
    (std::string license);
    
    //=================================================================
    // rent a bike
    //=================================================================
    void Rent
    (std::string classType, std::string station);
    
    //=================================================================
    // return the bike
    //=================================================================
    void Return
    (std::string station, std::string license, int returnMile);
    
    //=================================================================
    // move the ubike license to another station
    //=================================================================
    void Trans
    (std::string station, std::string license);
    
    //=================================================================
    // clear all the allocated memories for ubikes
    //=================================================================
    void ShutDown();
    
};

#endif

//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************
