/**
* @file logger.cpp
* @brief file for handling declaring logger fuction
* @author Olivia Van Pelt
* @assignment Lecture 10.2
* @date 11/11/2020
* credits
*   geeksforgeeks.org
*/

#include "logger.h"
#include <unistd.h>

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
    //string hostName = "mine";
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