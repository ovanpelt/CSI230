/**
* @file util.cpp
* @brief file for functions for week10
*
* @author Olivia Van Pelt
* @assignment Lecture 10.1
* @date 11/8/2020
* credits
*
*/

#include "util.h"

string randomElement(vector<string> vec)
{
	int size = vec.size();
	int index = rand() % (size + 1);
	return vec[index];
}

double sum (vector<double> vec)
{
	double total = 0;
	for (double num : vec)
	{
		total += num;
	}
	return total;
}

double avg(vector<double> vec)
{
	double total = sum(vec);
	return total / vec.size();

}

double lowest(vector<double> vec)
{
	double lowest = vec[0];
	for (double num : vec)
	{
		if( num < lowest)
			lowest = num;
	}
	return lowest;
}

void camelCase(string& sent)
{
	for (int i = 0; i < sent.size(); i++)
	{
		if (sent[i] == ' ')
		{
			sent.erase(i, 1);
			sent[i] = toupper(sent[i]);
		}
	}
}