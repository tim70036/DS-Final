//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************

//KEEP-THIS-HEADER-UNTOUCHED
#include "PriceTableIMP.h"
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

void PriceTableIMP::calcAllPairsShortestPath(string mapFile)
{
    // Read map file
    FILE * in;
    in = fopen(mapFile.c_str(), "r");
    char station1[100];
    char station2[100];
    int distance;


    for(int i=0 ; i<12 ; i++)
        for(int j = 0 ; j<12 ; j++)
            distTable[StationNames[i]][StationNames[j]] = 66666666;
    for(int i=0 ; i<12 ; i++)   distTable[StationNames[i]][StationNames[i]] = 0;

    while(fscanf(in, "%s %s %d",station1,station2,&distance) != EOF)
    {
        string a(station1);
        string b(station2);
        distTable[a][b] = min(distance, distTable[a][b]);
        distTable[b][a] = min(distance, distTable[b][a]);
    }
    fclose(in);

    // Floyd Warshall


    for(int mid = 0 ; mid < StationNum ; mid++){
        for(int i = 0 ; i < StationNum ; i++){
            for(int j=0 ; j < StationNum ; j++){
                int  old = distTable[StationNames[i]][StationNames[j]];
                int k = distTable[StationNames[i]][StationNames[mid]] + distTable[StationNames[mid]][StationNames[j]];
                if( k < old )
                   distTable[StationNames[i]][StationNames[j]] = k;
            }
        }
    }
}

int PriceTableIMP::calcPrice(int milageDiff, string bClass,
              string from, string toStation)
{
    if(milageDiff <= distTable[from][toStation])
        return milageDiff * dscntPriceTable.at(bClass);
    else
        return milageDiff * oriPriceTable.at(bClass);
}
//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************
