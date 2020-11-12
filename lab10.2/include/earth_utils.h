/**
* @file earth_utils.cpp
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

/**
 * @brief processes csv file
 * @date 11/11/2020
 * @return returns number of records
 * @param inFile ifstream to open csv file
 * @param kmlFileName string containing kml file name
 * @param logFile ofstream referance
*/
int processCSV(ifstream& inFile, string kmlFileName);

#endif