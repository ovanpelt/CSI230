/**
* @file util.h
* @brief file for functions declarations for week10
*
* @author Olivia Van Pelt
* @assignment Lecture 10.1
* @date 11/8/2020
* credits
*
*/

// header guard
#ifndef UTIL_H
#define UTIL_H

//includes
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
//forward declaration
/**
 *  @brief returns random element in a string vector
 *  @date 11/9
 *  @param vector<string>, vector to be randomly chosen from
 *  @return string, the chosen element of vector
 */
string randomElement(vector<string> vec);

/**
 *  @brief returns the sum of a vector of doubles
 *  @date 11/9
 *  @param vector<double>, vector to be added
 *  @return double, the sum
 */
double sum (vector<double> vec);

/**
 *  @brief returns the average of a vector of doubles
 *  @date 11/9
 *  @param vector<double>, vector to be averaged
 *  @return double, the average
 */
double avg(vector<double> vec);

/**
 *  @brief returns the lowest number in a vector of doubles
 *  @date 11/9
 *  @param vector<double>, vector to be searched through
 *  @return double, the lowest value
 */
double lowest(vector<double> vec);

/**
 *  @brief changes to the camel case version of a sentance
 *  @date 11/9
 *  @param string, sentance to be changed
 *  @return nothingg, but changes the sentance
 */
void camelCase(string& sent);

//ends declartion
#endif