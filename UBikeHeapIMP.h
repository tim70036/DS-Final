//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************

#ifndef UBikeHeapIMP_h
#define UBikeHeapIMP_h

//KEEP-THIS-HEADER-UNTOUCHED
#include "readonly/UBikeHeapADT.h"

class UBikeHeapIMP : public UBikeHeapADT
{
    //DO SOMETHINE HERE
public:
    //=================================================================
    // add the ubike pointer to the heap
    //=================================================================
    void addUBikePtr(UBike* ubptr);
    
    //=================================================================
    // remove the ubike pointer in this heap at "index"
    //=================================================================
    UBike* removeUBikePtr(int heapIndex);
    
};

#endif

//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************
