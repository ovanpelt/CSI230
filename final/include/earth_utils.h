/**
* @file earth_utils.h
* @brief file for handling declaring google earth fuction
* @author Olivia Van Pelt
* @assignment Lecture 10.2
* @date 11/11/2020
* credits
*
*/
#ifndef EARTH_UTILS_H
#define EARTH_UTILS_H
#include <string>
#include <fstream>

using namespace std;

const string KMLHEADER1 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
const string KMLHEADER2 = "<kml xmlns=\"http://www.opengis.net/kml/2.2\">";
const string KMLFOOTER = "</kml>";
const string KMLDOCSTART = "<Document>";
const string KMLDOCEND = "</Document>";


struct places {string city; int choice;};


/**
 * @brief processes csv file
 * @date 11/11/2020
 * @return returns number of records
 * @param inFile ifstream to open csv file
 * @param kmlFileName string containing kml file name
 * @param logFile ofstream referance
*/
int processCSV(ifstream& inFile, string kmlFileName, ofstream& logFile, places orderPlaces[9]);


/**
 * @brief writes placemenk record
 * @date 11/11/2020
 * @param name string representing capital, country
 * @param latitude string latitude
 * @param longitude string longitude
 * @param elevation string elevation, default zero
 * @param logFile ofstream refferance, to log names
*/
void WritePlacemark(ofstream& kmlFile, string name, string latitude, string longitude, ofstream& logFile, places orderPlaces[9]);

/**
 * @brief creates a discrete syslog message
 * @date 11/11/2020
 * @return returns a boolean showing if the message was writen
 * @param msg string containing syslog message
 * @param programName string name of program
 * @param logFile ofstream refferance
*/
bool log(string msg, string programName, ofstream& logFile);


/**
 * * @brief creates a discrete logging of names
 * @date 11/12/2020
 * @return returns a boolean showing if the name was writen
 * @param name string containing syslog messag
 * @param logFile ofstream refferance
*/
bool logName(string name, ofstream& logFile, places orderPlaces[9]);

void clear();
#endif