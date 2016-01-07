//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************

//KEEP-THIS-HEADER-UNTOUCHED
#include "UBikeHeapIMP.h"
#include <algorithm>
using namespace std;
//DO SOMETHINE HERE
void UBikeHeapIMP::addUBikePtr(UBike* ubptr)
{
    // heap[1] is root
    int in = ubptr->mileage;
    int cur = ++number;
    
    while( cur > 1 )
    {
        // Be careful heap[0] and <=
        if(in <= this->at(cur/2)->mileage) break;
        
        this->at(cur) = this->at(cur/2);
        // Update the data for Ubike
        this->at(cur)->heapIndex = cur;
        cur /= 2;
    }
    
    this->at(cur) = ubptr;
    ubptr->heapIndex = cur;
}

UBike* UBikeHeapIMP::removeUBikePtr(int heapIndex)
{
    // Nothing in heap
    if(heapIndex > number)  return NULL;
    
    UBike* re = this->at(heapIndex);
    int cur = heapIndex;
    
    UBike* last = this->at(number);
    int lastMileage = this->at(number)->mileage;
    number--;
    
    // Compare with parent or children  Be careful of heap[0] and >=
    while(  cur > 1 )
    {
        if(lastMileage >= this->at(cur/2)->mileage)  break;
        
        this->at(cur) = this->at(cur/2);
        this->at(cur)->heapIndex = cur;
        cur /= 2;
    }
    
    int child = cur * 2;
    while(child <= number)
    {
        // Largest child left or right?
        if(child + 1 <= number)
            if(this->at(child)->mileage < this->at(child+1)->mileage) child++;
        
        // Swap?
        if(lastMileage >= this->at(child)->mileage)   break;
        
        // Swap
        this->at(cur) = this->at(child);
        this->at(cur)->heapIndex = cur;
        cur = child;
        child = cur*2;
    }
    
    // Place
    this->at(cur) = last;
    this->at(cur)->heapIndex = cur;
    
    return re;
}

//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************
