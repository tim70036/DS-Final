//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************

//KEEP-THIS-HEADER-UNTOUCHED
#include "UBikeSystemIMP.h"
using namespace std;
//DO SOMETHINE HERE

void UBikeSystemIMP::InitDistTable(std::string MapFile)
{
    priceTable.calcAllPairsShortestPath(MapFile);
}

void UBikeSystemIMP::NewBike(std::string classType, std::string license, int mile, std::string station)
{
    // Initialize
    UBike* tmp = new UBike;
    tmp->isRented = false;
    tmp->mileage = mile;
    tmp->license = license;
    tmp->station = station;
    tmp->classType = classType;
    
    // Add to hash table
    ubHashTable.addUBikePtr(tmp);
    
    // Add to that station's heap
    ubStations[station][classType].addUBikePtr(tmp);
}

void UBikeSystemIMP::Rent(std::string classType, std::string station)
{
    // Find the bike with bigest mileage
    UBike* tmp = ubStations[station][classType].removeUBikePtr(1);
    
    // No free bike availiable
    if(tmp == NULL) return;
    
    // Add to rented heap in that station
    tmp->isRented = true;
    ubStations[station]["Rented"].addUBikePtr(tmp);
}

void UBikeSystemIMP::Return(std::string station, std::string license, int returnMile)
{
    // Find the bike by using license
    UBike* tmp = ubHashTable.findUBikePtr(license, false);
    
    
    
    // This bike is not rented, not found in hash table
    if(tmp == NULL) return;
    if(tmp->isRented == false)  return;
    
    // Remove from Rented heap in original station
    tmp = ubStations[tmp->station]["Rented"].removeUBikePtr(tmp->heapIndex);
    
    // Not found in Rented heap
    if(tmp == NULL) return;
    
    // Calculate rental
    net += priceTable.calcPrice(returnMile - tmp->mileage,
                                tmp->classType,
                                tmp->station, station);
    
    // Update
    tmp->isRented = false;
    tmp->mileage = returnMile;
    
    // Add to original station's heap
    ubStations[tmp->station][tmp->classType].addUBikePtr(tmp);
    
}

void UBikeSystemIMP::Trans(std::string station, std::string license)
{
    // Find the bike by using license
    UBike* tmp = ubHashTable.findUBikePtr(license, false);
    
    // This bike is now rented or not found in hash table
    if(tmp == NULL) return;
    if(tmp->isRented == true)   return;
    
    // Remove from heap in original station
    tmp = ubStations[tmp->station][tmp->classType].removeUBikePtr(tmp->heapIndex);
    
    // Not found in heap
    if(tmp == NULL) return;
    
    // Update
    tmp->station = station;
    
    // Add to new Station's heap
    ubStations[tmp->station][tmp->classType].addUBikePtr(tmp);
}

void UBikeSystemIMP::JunkIt(std::string license)
{
    // Find the bike by using license, and remove from hash table
    UBike* tmp = ubHashTable.findUBikePtr(license, true);
    
    // This bike is now rented or not found in hash table
    if(tmp == NULL) return;
    if(tmp->isRented == true)   return;
    
    // Remove from heap
    tmp = ubStations[tmp->station][tmp->classType].removeUBikePtr(tmp->heapIndex);
    
    if(tmp != NULL) delete tmp;
}

void UBikeSystemIMP::ShutDown()
{
    for(int i=0 ; i < 256 ; i++)
    {
        if(ubHashTable[i].empty())  continue;
        for(auto cur = ubHashTable[i].begin() ; cur != ubHashTable[i].end() ; cur++)
            if(*cur != NULL)    delete *cur;
        
    }
}

//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************
