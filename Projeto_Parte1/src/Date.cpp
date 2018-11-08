/*
 * Date.cpp
 *
 *  Created on: 07/11/2018
 *      Author: josem
 */

#include "Date.h"
#include <string>

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}
string Date::getDate() {
	string res;

	res += to_string(day) + "/" + to_string(month) + "/" + to_string(year);
	return res;
}

bool Date::operator>(const Date &d1) {

	if (this->year > d1.year)
		return true;
	else if (this->year < d1.year)
		return false;
	if (this->month > d1.month)
		return true;
	else if (this->month < d1.month)
		return false;
	if (this->day > d1.day)
		return true;
	else if (this->day < d1.day)
		return false;

	return false;
}

void Date::setDate(int day, int month, int year){

	//lan�ar excep��o caso data inv�lida
		this->day = day;
		this->month = month;
		this->year = year;
}
