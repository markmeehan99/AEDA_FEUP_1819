/*
 * Date.h
 *
 *  Created on: 07/11/2018
 *      Author: josem
 */

#ifndef DATE_H_
#define DATE_H_

#include <string>

using namespace std;

class Date {
	int day,month,year;

public:
	Date();
	Date(int day, int month, int year);
	string getDate()const;
	void setDate(int day, int month, int year);
	bool operator>(const Date &d1);
	Date& operator=(const Date& d);
};

#endif /* DATE_H_ */
