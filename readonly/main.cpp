//========================DO-NOT-MODIFY-THE-FILE========================

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../UBikeSystemIMP.h"
using namespace std;
static void basicTest
(std::string TransFile, std::string MapFile, std::string AnsFile)
{
    try
    {
        UBikeSystemIMP ubSystem;

        //init the distance table
        ubSystem.InitDistTable(MapFile);

        //parse the transaction file
        std::ifstream ifs(TransFile);

        //process each command
        std::string trs;
        while( ifs >> trs )
        {
            if( trs=="NewBike" )
            {
                std::string classType, license, station;
                int mile;
                ifs >> classType >> license >> mile >> station ;
                ubSystem.NewBike( classType, license, mile, station );
            }
            else if( trs=="JunkIt" )
            {
                std::string license;
                ifs >> license;
                ubSystem.JunkIt( license );
            }
            else if( trs=="Rent" )
            {
                std::string classType, station;
                ifs >> station >> classType;
                ubSystem.Rent( classType, station );
            }
            else if( trs=="Return" )
            {
                std::string station, license;
                int returnMile;
                ifs >> station >> license >> returnMile;
                ubSystem.Return( station, license, returnMile );
            }
            else if( trs=="Trans" )
            {
                std::string station, license;
                ifs >> station >> license;
                ubSystem.Trans( station, license );
            }
        }

        ifs.close();

        //read the answer texts
        std::ifstream ifsAns( AnsFile );
        std::string ansText( (std::istreambuf_iterator<char>(ifsAns)),
                             (std::istreambuf_iterator<char>()      ) );
        ifsAns.close();

        //your output
        std::ostringstream oss;
        oss << ubSystem.toString();

        //release the allocated memory
        ubSystem.ShutDown();

        //compare the results
        if( oss.str() == ansText )
            std::cout << "PASS!" << std::endl;
        else
            std::cout << "FAIL." << std::endl;
    }
    catch(const char* str)
    {
        std::cout << "The implementation is not done. : [" << str << "]" << std::endl;
    }
}

int main(int argc, char *argv[])
{

    std::cout << "test case 1: ";
    basicTest( "tc1/testCase", "tc1/testMap", "tc1/output" );

    std::cout << "test case 2: ";
    basicTest( "tc2/testCase", "tc2/testMap", "tc2/output" );

    std::cout << "test case 3: ";
    basicTest( "tc3/testCase", "tc3/testMap", "tc3/output" );



/*
    UBikeSystemIMP ubSystem;

    //init the distance table
    ubSystem.InitDistTable("tc1/testMap");


    std::string trs;
    while( cin >> trs )
    {
        if( trs=="NewBike" )
        {
            std::string classType, license, station;
            int mile;
            cin >> classType >> license >> mile >> station ;
            ubSystem.NewBike( classType, license, mile, station );
        }
        else if( trs=="JunkIt" )
        {
            std::string license;
            cin >> license;
            ubSystem.JunkIt( license );
        }
        else if( trs=="Rent" )
        {
            std::string classType, station;
            cin >> station >> classType;
            ubSystem.Rent( classType, station );
        }
        else if( trs=="Return" )
        {
            std::string station, license;
            int returnMile;
            cin >> station >> license >> returnMile;
            ubSystem.Return( station, license, returnMile );
        }
        else if( trs=="Trans" )
        {
            std::string station, license;
            cin >> station >> license;
            ubSystem.Trans( station, license );
        }

        else if ( trs == "q")   break;
        else if( trs == "s")    cout <<ubSystem.toString() << endl;
    }
    cout << ubSystem.toString() << endl;

*/






// HIDDEN-TEST-CASES
//=============================================================
    std::cout << "test case 4: ";
    basicTest( "tc4/testCase", "tc4/testMap", "tc4/output" );
//
    std::cout << "test case 5: ";
    basicTest( "tc5/testCase", "tc5/testMap", "tc5/output" );
//
//    std::cout << "test case 6: ";
//    basicTest( "tc6/testCase", "tc6/testMap", "tc6/output" );
//
//    std::cout << "test case 7: ";
//    basicTest( "tc7/testCase", "tc7/testMap", "tc7/output" );
//=============================================================

	return 0;
}

//========================DO-NOT-MODIFY-THE-FILE========================
