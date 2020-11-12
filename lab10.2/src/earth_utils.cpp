/**
* @file earth_utils.cpp
* @brief file for handling csv file
* @author Olivia Van Pelt
* @assignment Lecture 10.2
* @date 11/11/2020
* credits
*   
*/
#include "earth_utils.h"
#include <iostream>
int processCSV(ifstream& inFile, string kmlFileName)
{
    string strCoun, strCap, strLat, strLong;
    string strLine;
    int recordCount{};


    if(inFile)
    {
        getline(inFile, strLine);
        cout << strLine << endl;
    }

    
}