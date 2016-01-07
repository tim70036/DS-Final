#ifndef UBikeSystemADT_h
#define UBikeSystemADT_h

#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "../PriceTableIMP.h"
#include "../UBikeHashTableIMP.h"
#include "../UBikeHeapIMP.h"

class UBikeSystemADT
{
protected:
    //=================================================================
    // the price table
    // it calculates the shortest distances of the map and the rental.
    //=================================================================
    PriceTableIMP priceTable;
    
    //=================================================================
    // the hash table for the ubikes owned by the ubike company
    // overflow is handled by chaining
    //=================================================================
    UBikeHashTableIMP ubHashTable;
    
    //=================================================================
    // the ADT for an ubike station
    // it is composed of 5 heaps, "Rented", "Electric", "Lady" ...
    //=================================================================
    typedef std::map<std::string, UBikeHeapIMP> UBStation;
    
    //=================================================================
    // the ADT for all ubike stations
    // it is composed of 12 stations, "Danshui", "Hongshulin", ...
    //=================================================================
    std::map< std::string, UBStation > ubStations;
    
    //=================================================================
    // the money earned by the company
    //=================================================================
    int net;
    
public:

    //=================================================================
    // read the map and initialize this->priceTable
    //=================================================================
    virtual void InitDistTable
    (std::string MapFile);
    
    //=================================================================
    // add a new bike to the system
    //=================================================================
    virtual void NewBike
    (std::string classType, std::string license,
     int mile, std::string station);
    
    //=================================================================
    // remove the bike license
    //=================================================================
    virtual void JunkIt
    (std::string license);
    
    //=================================================================
    // rent a bike
    //=================================================================
    virtual void Rent
    (std::string classType, std::string station);
    
    //=================================================================
    // return the bike
    //=================================================================
    virtual void Return
    (std::string station, std::string license, int returnMile);
    
    //=================================================================
    // move the ubike license to another station
    //=================================================================
    virtual void Trans
    (std::string station, std::string license);
    
    //=================================================================
    // clear all the allocated memories for ubikes
    //=================================================================
    virtual void ShutDown();
    
    
    //=================================================================
    // constructor
    //=================================================================
    UBikeSystemADT();
    
    //=================================================================
    // information
    //=================================================================
    std::string toString() const;
};

#endif