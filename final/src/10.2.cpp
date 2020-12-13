/**
* @file 10.2.cpp
* @brief file for main code
*
* @author Olivia Van Pelt
* @assignment Lecture 10.2
* @date 11/11/2020
* credits
*
*/
#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>
#include "logger.h"
#include "earth_utils.h"

using namespace std;

int main(int argc, char* argv[])
{
    int opt{};
    bool kmlFlag{false};
    bool logFlag{false};
    int count{};
    string logVal;
    string kmlVal;
    bool optErr=true;
    while((opt =getopt(argc, argv, "k:l:")) != EOF)
    {
         switch(opt)
       {
           case 'k':
                kmlFlag = true;
                kmlVal = optarg;
                break;
            case 'l':
                logFlag = true;
                logVal =optarg;
                break;
            default:
                optErr =true;
                break;
       }

    }

    cout<< "flags- kmlflag: " << kmlFlag << " logFlag: " << logFlag << endl;

    if(kmlFlag && logFlag)
    {
        cout << "flagset"<<endl;
        if(logVal.empty() || kmlVal.empty())
        {
            optErr=true;
            cout << "option arguments are not set" << endl;
        }  
        else
        {
            ofstream flog;
            flog.open(logVal, ios_base::app);
            if(flog)
            {
                string programName = basename(argv[0]);
                string msg = "The kmlfile is: " + kmlVal + " and the logfile is: " + logVal;
                log(msg, programName, flog);
                optErr = false;
                flog.close();
                ifstream inFile;
                inFile.open(kmlVal);
                if(inFile)
                {
                    int recordCount = processCSV(inFile, kmlVal + ".kml");
                    inFile.close();
                    if(recordCount)
                    {
                        cout << recordCount << " records processed" << endl;
                        optErr=false;
                    }
                    else
                    {
                        optErr=true;
                    }                 
                }
                else
                {
                    optErr = true;
                }
                
            }
            else
            {
                cout << "could not open " << logVal << endl;
                optErr =true;
            }
        }
    }
    else
    {
        cout << "error - flags not set" << endl;
        optErr=true;
    }
    
    if(optErr)
    {
        return EXIT_FAILURE;
    }

    cout << "optErr: " << optErr << endl;

    
    return EXIT_SUCCESS;
}