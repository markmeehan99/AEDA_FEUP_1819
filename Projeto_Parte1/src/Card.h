/*
 * Card.h
 *
 *  Created on: 06/11/2018
 *      Author: josem
 */

#ifndef CARD_H_
#define CARD_H_

#include "Date.h"
#include <string>

using namespace std;

class Card {
	int id;
	string name;
	double credit;
	Date expDate;
public:
	Card(int id, string name, double credit, Date expDate);
	Date getExpDate() const;
	double getCredit() const;
	int getID() const;
	string getName()const;
	void removeCredit(double amount);
	void addCredit(double amount);
};

class InvalidAmount{
public:
	double amount;
	InvalidAmount(double amount){
		this->amount = amount;
	}
	double getAmount(){
		return amount;
	}
};



#endif /* CARD_H_ */
