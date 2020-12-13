/**
* @file count.cpp
* @brief count library implimentation
* @author Olivia Van Pelt
* @assignment Lecture 12.1
* @date 11/30/2020
* credits
* written by:
* https://www.fayewilliams.com/2015/07/07/creating-a-shared-library/
*/
#include "count.h"
#include <string.h>
 
int count(char* word)
{
    char *p = word;
    int len = strlen(word);
    int vowels = 0;

 
    for (int i = 0 ; i < len ; ++i, ++p)
    {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u')
        {
            vowels++;
        }
    }
 
    return vowels;
}