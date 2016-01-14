#include "UBikeSystemADT.h"

void UBikeSystemADT::InitDistTable
(std::string MapFile)
{
    throw "UBikeSystemADT::InitDistTable";
}

void UBikeSystemADT::NewBike
(std::string classType, std::string license,
 int mileage, std::string station)
{
    throw "UBikeSystemADT::NewBike";
}

void UBikeSystemADT::JunkIt
(std::string license)
{
    throw "UBikeSystemADT::JunkIt";
}

void UBikeSystemADT::Rent
(std::string classType, std::string station)
{
    throw "UBikeSystemADT::Rent";
}

void UBikeSystemADT::Return
(std::string station, std::string license, int returnMile)
{
    throw "UBikeSystemADT::Return";
}

void UBikeSystemADT::Trans
(std::string station, std::string license)
{
    throw "UBikeSystemADT::Trans";
}

void UBikeSystemADT::ShutDown()
{
    throw "UBikeSystemADT::ShutDown";
}

UBikeSystemADT::UBikeSystemADT():net(0)
{
    for(int i=0;i<StationNum;i++) for(int j=0;j<HeapTypeNum;j++)
    {
        const std::string &station = StationNames[i];
        const std::string &classType = HeapNames[j];
        this->ubStations[station][classType];
    }
}

std::string UBikeSystemADT::toString() const
{
    std::ostringstream oss;
    
    oss << "[ Net ]" << std::endl;
    oss << this->net << std::endl << std::endl;
    
    oss << "[ Hash Table ]" << std::endl;
    oss << this->ubHashTable.toString() << std::endl;
    
    for(int i=0;i<StationNum;i++)
    {
        const std::string &station = StationNames[i];
        for(int j=1;j<HeapTypeNum;j++)
        {
            const std::string &classType = HeapNames[j];
            const UBikeHeapIMP &ubheap = this->ubStations.at(station).at(classType);
            
            if( ubheap.isEmpty() )
                continue;
            
            oss << "[ " << station << " - " << classType << " Heap ]" << std::endl;
            oss << ubheap.toString();
        }
    }

    return oss.str();
}
