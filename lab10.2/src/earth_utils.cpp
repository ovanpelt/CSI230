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
#include <sstream>
int processCSV(ifstream& inFile, string kmlFileName)
{
    string strCoun, strCap, strLat, strLong;
    string strLine;
    int recordCount{};


    if(inFile)
    {
        ofstream kmlFile;
        kmlFile.open(kmlFileName);
        if(kmlFile)
        {
            kmlFile << KMLHEADER1 << endl;
            kmlFile << KMLHEADER2 << endl;
            kmlFile << KMLDOCSTART << endl;

            getline(inFile, strLine);
            while(getline(inFile, strLine))
            {   
                stringstream s_stream(strLine);
                getline(s_stream, strCoun, ',');
                getline(s_stream, strCap, ',');
                getline(s_stream, strLat, ',');
                getline(s_stream, strLong, ',');

                WritePlacemark(kmlFile, strCap+", "+strCoun, strLat, strLong);
                recordCount++;
            }

            kmlFile << KMLDOCEND << endl;
            kmlFile << KMLFOOTER << endl;
            kmlFile.close();
        }
    }
    return recordCount;
}

void WritePlacemark(ofstream& kmlFile, string name, string latitude, string longitude)
{
    kmlFile << "<Placemark>" <<endl;
    kmlFile << "<name>" << name << "</name>" << endl;
    kmlFile<<"<Point>" << "<coordinate>" << latitude << ", "<< longitude << "</coordinate>" << "</Point>" << endl;
    kmlFile << "</Placemark>" << endl;
}