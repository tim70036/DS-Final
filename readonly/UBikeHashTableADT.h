#ifndef UBikeHashTableADT_h
#define UBikeHashTableADT_h

#include "UBike.h"
#include <list>
#include <array>

//doubly linked list of Bike*
typedef std::list<UBike*> UBikePtrList;

//=================================================================
// the hash table for the ubikes owned by the ubike company
// overflow is handled by chaining
//=================================================================
class UBikeHashTableADT : public std::array< UBikePtrList, 256 >
{
public:

    //=================================================================
    // add the ubike pointer to the heap
    //=================================================================
    virtual void addUBikePtr(UBike* ubptr);
    
    //=================================================================
    // find the ubike pointer in the hash table given ubike license
    // if toRemove is true, remove the the pointer from the hash table
    // return the ubike pointer that points to the ubike license
    //=================================================================
    virtual UBike* findUBikePtr(std::string license, bool toRemove);
    
    //=================================================================
    // information
    //=================================================================
    std::string toString() const;
};

#endif
