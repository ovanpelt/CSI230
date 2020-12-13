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


/**
 * @brief processes csv file
 * @date 11/11/2020
 * @return returns number of records
 * @param inFile ifstream to open csv file
 * @param kmlFileName string containing kml file name
 * @param logFile ofstream referance
*/
int processCSV(ifstream& inFile, string kmlFileName);


/**
 * @brief writes placemenk record
 * @date 11/11/2020
 * @param name string representing capital, country
 * @param latitude string latitude
 * @param longitude string longitude
 * @param elevation string elevation, default zero
*/
void WritePlacemark(ofstream& kmlFile, string name, string latitude, string longitude);


#endif