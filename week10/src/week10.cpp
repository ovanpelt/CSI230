/**
* @file week10.cpp
* @brief Week 10, c++ review and warmup from CSI140
*
* @author Olivia Van Pelt
* @assignment Lecture 10.1
* @date 11/8/2020
* credits
*
*/

#include "util.h"

int main()
{
	//String vector section
	vector<string> strVec;
	strVec.push_back("Olivia");
	strVec.push_back("NotOlivia");
	strVec.push_back("StillNotOlivia");
	strVec.push_back("AlsoNotOlivia");
	strVec.push_back("Olivia2");
	cout << "Dumping the Vector of 5 strings: ";
	for (string ele : strVec)
	{
		cout << ele << " ";
	}
	cout << endl;
	cout << "setting srand in main" << endl;
	srand(time(0));
	cout << "calling randomElement" << endl;
	cout << randomElement(strVec) << endl;

	//double vector section
	vector<double> dblVec;
	dblVec.push_back(3.2452);
	dblVec.push_back(12.452);
	dblVec.push_back(235.87);
	dblVec.push_back(86.354);
	dblVec.push_back(3.6);
	cout << "Dumping the Vector of 5 doubles: ";
	for (double ele : dblVec)
	{
		cout << ele << " ";
	}
	cout << endl;
	cout << "Sum: " << sum(dblVec) << endl;
	cout << "Avg: " << avg(dblVec) << endl;
	cout << "Lowest: " << lowest(dblVec) << endl;

	//mutliword string section
	string mwstr = "A little bird with a yellow bill";
	cout << "Calling camelCase with: " << mwstr << endl;
	camelCase(mwstr);
	cout << "String after camelCase: " << mwstr << endl;

	return EXIT_SUCCESS;
}
