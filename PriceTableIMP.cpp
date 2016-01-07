//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************

//KEEP-THIS-HEADER-UNTOUCHED
#include "PriceTableIMP.h"
#include <stdio.h>
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
    
    long long int table[12][12];
    for(int i=0 ; i<12 ; i++)   for(int j = 0 ; j<12 ; j++) table[i][j] = INT_MAX;
    for(int i=0 ; i<12 ; i++)   table[i][i] = 0;
    
    while(fscanf(in, "%s %s %d",station1,station2,&distance) != EOF)
    {
        int index1,index2;
        string a(station1);
        string b(station2);
        for(int i=0 ; i<StationNum ; i++)
            if(StationNames[i] == a)    index1 = i;
        for(int i=0 ; i<StationNum ; i++)
            if(StationNames[i] == b)    index2 = i;
        
        table[index1][index2] = distance;
    }
    fclose(in);
    
    // Floyd Warshall
    
    
    for(int mid = 0 ; mid < StationNum ; mid++){
        for(int i = 0 ; i < StationNum ; i++){
            for(int j=0 ; j < StationNum ; j++){
                long long int  old = table[i][j];
                long long int k = table[i][mid] + table[mid][j];
                if( k < old )
                   table[i][j] = k;
            }
        }
    }
    
    // Into dist table
    for(int i=0 ; i<12 ; i++)
        for(int j=0 ; j<12 ; j++)
            distTable[StationNames[i]][StationNames[j]] = table[i][j];
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
