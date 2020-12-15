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
#include "earth_utils.h"
#include <string>

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
    static places orderPlaces[9];
    places travelList[9];
    int num;

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
    //for debugging purposes
    //cout<< "flags- kmlflag: " << kmlFlag << " logFlag: " << logFlag << endl;

    if(kmlFlag && logFlag)
    {
        //for debugging purposes
        //cout << "flagset"<< endl;
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
                ifstream inFile;
                inFile.open(kmlVal);
                if(inFile)
                {
                    int recordCount = processCSV(inFile, kmlVal + ".kml", flog, orderPlaces);
                    inFile.close();
                    if(recordCount)
                    {
                        cout << recordCount << " countries loaded processed" << endl;
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
                for (int i = 0; i<9; i++)
                {
                    cout << orderPlaces[i].choice<< " " << orderPlaces[i].city<< endl;
                }
                cout << "Please enter the order in which You wish to visit these places (numbers 1-9)" << endl;
                for (int i=0; i<9; i++)
                {
                    cout<<"destingation " << i+1 << ": ";
                    cin>>num;
                    travelList[i]=orderPlaces[num-1];
                }
                log("User has changed the flight log:", programName, flog);
                clear();
                for (int i = 0; i<9; i++)
                {
                    logName(travelList[i].city, flog, travelList);
                }
                cout<<"Your changes have been updated to our flight schedule."<<endl;
                flog.close();
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

    //for debugging erposes only
    //cout << "optErr: " << optErr << endl;

    return EXIT_SUCCESS;
}