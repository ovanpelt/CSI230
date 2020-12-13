/**
* @file logger.h
* @brief file for declaring logger fuction
* @author Olivia Van Pelt
* @assignment Lecture 10.2
* @date 11/11/2020
* credits
*
*/
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

using namespace std;

/**
 * @brief creates a discrete syslog message
 * @date 11/11/2020
 * @return returns a boolean showing if the message was writen
 * @param msg string containing syslog message
 * @param programName string name of program
 * @param logFile ofstream refferance
*/
bool log(string msg, string programName, ofstream& logFile);

#endif