//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************

//KEEP-THIS-HEADER-UNTOUCHED
#include "UBikeHashTableIMP.h"
#include <string>
#include <bitset>
using namespace std;
//DO SOMETHINE HERE
void UBikeHashTableIMP::addUBikePtr(UBike* ubptr)
{
    // Add into hash table
    int index = calcLicense(ubptr->license);
    (this->at(index)).push_back(ubptr);
}

UBike* UBikeHashTableIMP::findUBikePtr(std::string license, bool toRemove)
{
    int index = calcLicense(license);
    
    
    // This List in hash table is empty?, no such buck exist
    //if(this->at(index).empty()) return NULL;
    
    auto i = (this->at(index)).begin();
    
    for( ; i != (this->at(index)).end() ; i++)
        if((*i)->license == license)    break;
    
    // Not found
    if(i == (this->at(index)).end())    return NULL;
    
    // Remove?
    if(toRemove)    (this->at(index)).remove(*i);
    return *i;
}

int UBikeHashTableIMP::calcLicense(string x)
{
    int s;
    if(isdigit(x[0]))   s = x[0] - '0';
    else s = x[0] - 'A' + 10;
    for(int i=1 ; i < 5 ; i++)
    {
        if(isdigit(x[i])) s = s*31 + x[i] - '0';
        else s = s*31 + x[i] - 'A' + 10;
    }
    // convert to binary, choose 11~18 bit
    bitset<40> b(s);
    int index = 0;
    for(int i=17 ; i >= 10 ; i--)  index = index*2 + b[i];
    return index;
}
//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************
