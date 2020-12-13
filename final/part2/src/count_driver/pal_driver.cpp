/**
* @file pal_driver.cpp
* @brief palendrome library driver
* @author Olivia Van Pelt
* @assignment Lecture 12.1
* @date 11/30/2020
* @credits
* written by:
* https://www.fayewilliams.com/2015/07/07/creating-a-shared-library/
*/
#include "count.h"
#include <iostream>
 
using namespace std;
 
int main()
{
    while (1)
    {
        char buffer[64] = {0};
        cin >> buffer;
        cout << "Word countains " << count(buffer) << " vowels." << endl;
    }
 
    return 0;
}