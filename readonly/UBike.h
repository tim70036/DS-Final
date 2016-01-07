#ifndef UBike_h
#define UBike_h

#include <string>
#include <iomanip>
#include <sstream>

// The ADT of an ubike
class UBike
{
public:
    //=================================================================
    // if this ubike is rented
    //=================================================================
    bool isRented;
    
    //=================================================================
    // the mileage of this ubike
    //=================================================================
    int mileage;
    
    //=================================================================
    // the heap index of the heap where the ubike is.
    //=================================================================
    int heapIndex;
    
    //=================================================================
    // the license of this bike
    //=================================================================
    std::string license;

    //=================================================================
    // the station to which this ubike belongs
    // it can be any string in StationNames
    // "Danshui", "Hongshulin", "Beitou", ...
    //=================================================================
    std::string station;
    
    //=================================================================
    // the class type of this ubike
    // it can be any string in HeapNames
    // "Electric", "Lady", "Road" ...
    //=================================================================
    std::string classType;
    
    //=================================================================
    // infomation
    //=================================================================
    std::string toString() const;
};

#endif
