#ifndef DATE_H_
#define DATE_H_

#include <string>

using namespace std;

class Date {
	int day,month,year;

public:
	Date();
	Date(int day, int month, int year);
	Date(string date);
	string getDate()const;
	void setDate(int day, int month, int year);
	void setDate(string date);
	bool operator>(const Date &d1);
	void operator=(Date d);
};


class InvalidDate : public exception {
private:
	int day;
	int month;
	int year;
	string err = "";
public:
	InvalidDate(int day, int month, int year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
	string getInvalidDate() {
		err += to_string(day);
		err += "/";
		err += to_string(month);
		err += "/";
		err += to_string(year);
		err += "/";

		return err;
	}
};

//hehe

#endif /* DATE_H_ */
