//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************

#ifndef UBikeHashTableIMP_h
#define UBikeHashTableIMP_h

//KEEP-THIS-HEADER-UNTOUCHED
#include "readonly/UBikeHashTableADT.h"
using namespace std;
class UBikeHashTableIMP : public UBikeHashTableADT
{
    //DO SOMETHINE HERE
public:
    //=================================================================
    // add the ubike pointer to the heap
    //=================================================================
    void addUBikePtr(UBike* ubptr);
    
    //=================================================================
    // find the ubike pointer in the hash table given ubike license
    // if toRemove is true, remove the the pointer from the hash table
    // return the ubike pointer that points to the ubike license
    //=================================================================
    UBike* findUBikePtr(std::string license, bool toRemove);
    
    int calcLicense(string x);

};

#endif

//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************
