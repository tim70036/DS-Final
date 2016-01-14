#ifndef ConstParams_h
#define ConstParams_h

#include <string>
#include <map>

//===============================================================
// names of heaps
//===============================================================
const int HeapTypeNum = 5;
const std::string HeapNames[] =
{ "Rented", "Electric", "Lady", "Road", "Hybrid" };

//===============================================================
// names of stations
//===============================================================
const int StationNum = 12;
const std::string StationNames[] =
{
    "Danshui", "Hongshulin", "Beitou",
    "Shilin",  "Zhongshan", "Xinpu",
    "Ximen",   "Liuzhangli", "Muzha",
    "Guting",  "Gongguan", "Jingmei"
};

//===============================================================
// the original price of each mile
//===============================================================
const std::map< std::string, int > oriPriceTable =
{
    {"Electric", 40},
    {"Lady", 30},
    {"Road", 20},
    {"Hybrid", 25}
};

//===============================================================
// the discount price of each mile
//===============================================================
const std::map< std::string, int > dscntPriceTable =
{
    {"Electric", 30},
    {"Lady", 25},
    {"Road", 15},
    {"Hybrid", 20}
};

#endif
