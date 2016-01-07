#ifndef UBikeHeapADT_h
#define UBikeHeapADT_h

#include <array>
#include "UBike.h"
#include "ConstParams.h"

//=================================================================
// An special heap used in the system
// The detailed description can be found in the spec
//=================================================================
class UBikeHeapADT : public std::array< UBike*, 1024 >
{
public:
    UBikeHeapADT():number(0){}

    //=================================================================
    // the size of the heap
    //=================================================================
    int number;
    
    //=================================================================
    // add the ubike pointer to the heap
    //=================================================================
    virtual void addUBikePtr(UBike* ubptr);
    
    //=================================================================
    // remove the ubike pointer in this heap at "index"
    //=================================================================
    virtual UBike* removeUBikePtr(int heapIndex);
    
    //=================================================================
    // check if the heap is empty
    //=================================================================
    bool isEmpty() const;
    
    //=================================================================
    // information
    //=================================================================
    std::string toString() const;
};

#endif
