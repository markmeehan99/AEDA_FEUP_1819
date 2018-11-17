/*
 * Date.cpp
 *
 *  Created on: 07/11/2018
 *      Author: josem
 */

#include "Date.h"
#include <string>

Date::Date(){}

Date::Date(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

string Date::getDate()const {
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
	bool InvDate = false; //If date is invalid

	//Checks year
	if (year <= 0)
		InvDate = true;

	//Checks month and respective day
	switch(month) {
	case 1:
		if (day < 1 || day > 31)
			InvDate = false;
		break;
	case 2:
		if (year % 4 == 0) //ano bissexto
			if (day < 1 || day > 29)
				InvDate = false;
			else if (day < 1 || day > 28)
				InvDate = false;
		break;
	case 3:
		if (day < 1 || day > 31)
			InvDate = false;
		break;
	case 4:
		if (day < 1 || day > 30)
			InvDate = false;
		break;
	case 5:
		if (day < 1 || day > 31)
			InvDate = false;
		break;
	case 6:
		if (day < 1 || day > 30)
			InvDate = false;
		break;
	case 7:
		if (day < 1 || day > 31)
			InvDate = false;
		break;
	case 8:
		if (day < 1 || day > 31)
			InvDate = false;
		break;
	case 9:
		if (day < 1 || day > 30)
			InvDate = false;
		break;
	case 10:
		if (day < 1 || day > 31)
			InvDate = false;
		break;
	case 11:
		if (day < 1 || day > 30)
			InvDate = false;
		break;
	case 12:
		if (day < 1 || day > 31)
			InvDate = false;
		break;
	}

//hehe
	//If date is invalid, throws exception
	if (InvDate)
		throw InvalidDate(day, month, year);
	else {
		this->day = day;
		this->month = month;
		this->year = year;
	}
}
