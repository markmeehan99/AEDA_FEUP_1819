#include "Date.h"
#include <string>
#include <iostream>

Date::Date() {
	this->day = 01;
	this->month = 01;
	this->year = 00;
}

Date::Date(int day, int month, int year) {
	setDate(day, month, year);
}

Date::Date(string date) {
	int d = stoi(date.substr(0, 2));
	int m = stoi(date.substr(3, 2));
	int y = stoi(date.substr(6, 2));
	setDate(d, m, y);
}

string Date::getDate() const {
	string res;
	res += to_string(day) + "/" + to_string(month) + "/" + to_string(year);
	return res;
}


string Date::getDateIncremented() const {
	string res;
	if (month + 5 <= 12)
		res += to_string(day) + "/" + to_string(month + 5) + "/" + to_string(year);
	else
		res += to_string(day) + "/" + to_string((month + 5) % 12) + "/" + to_string(year + 1);

	return res;
}


bool Date::operator>(const Date &d1) {

	//Se os anos forem diferentes

	if (this->year > d1.year)
		return true;
	else if (this->year < d1.year)
		return false;


	//Se os anos forem iguais

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

void Date::setDate(int day, int month, int year) {
	bool InvDate = false; //If date is invalid

	//Checks year
	if (year < 0)
		InvDate = true;

	//Checks month and respective day
	switch (month) {
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

	//If date is invalid, throws exception
	if (InvDate)
		throw InvalidDate(day, month, year);
	else {
		this->day = day;
		this->month = month;
		this->year = year;
	}
}

void Date::setDate(string date) {
	int d = stoi(date.substr(0, 2));
	int m = stoi(date.substr(3, 2));
	int y = stoi(date.substr(6, 2));
	setDate(d, m, y);

}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}


void Date::operator=(Date d) {

	this->day = d.getDay();
	this->month = d.getMonth();
	this->year = d.getYear();
}

/*
ostream& Date::operator<< (ostream& stream)
{
	stream << this->day << "/" << this->month << "/" << this->year;

	return stream;
}*/


ostream& operator<<(ostream& sp, Date& date) {
	sp << date.getDate();
	return sp;
}

