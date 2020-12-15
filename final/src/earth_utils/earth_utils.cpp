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
#include <unistd.h>

static int count = 1;

int processCSV(ifstream& inFile, string kmlFileName, ofstream& logFile, places orderPlaces[9])
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

                WritePlacemark(kmlFile, strCap+", "+strCoun, strLat, strLong, logFile, orderPlaces);
                recordCount++;
            }

            kmlFile << KMLDOCEND << endl;
            kmlFile << KMLFOOTER << endl;
            kmlFile.close();
        }
    }
    return recordCount;
}

void WritePlacemark(ofstream& kmlFile, string name, string latitude, string longitude, ofstream& logFile, places orderPlaces[9])
{

    kmlFile << "<Placemark>" <<endl;
    kmlFile << "<name>" << name << "</name>" << endl;
    kmlFile<<"<Point>" << "<coordinates>" << longitude << ", "<< latitude << "</coordinates>" << "</Point>" << endl;
    kmlFile << "</Placemark>" << endl;

    logName(name, logFile, orderPlaces);
}
 
bool log(string msg, string programName, ofstream& logFile)
{
    string strTime;

    time_t logTime =time(0);
    strTime = ctime(&logTime);

    int timeSize =strTime.size();
    if(timeSize)
    {
        strTime[timeSize -1] = ' ';
    }
    pid_t pid = getpid();
    char hostbuffer [1024];
    gethostname(hostbuffer, 1024);
    if(logFile)
    {
        logFile << strTime << hostbuffer << " " << programName << "[" << pid << "]: " << msg << endl;
        return true;
    }
    else
    {
        return false;
    }   
}

bool logName(string name, ofstream& logFile, places orderPlaces[9])
{
    if (logFile)
    {
        logFile << name <<" is stop number: " << count << endl;
        orderPlaces[count-1].city = name;
        orderPlaces[count-1].choice = count;
        count++;
    }
    else
    {
        return false;
    }
    return true;
}
void clear()
{
    count = 1;
}