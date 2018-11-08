/*
 * Card.cpp
 *
 *  Created on: 06/11/2018
 *      Author: josem
 */

#include "Card.h"

Card::Card(int id, string name, double credit, Date *expDate) {

	this->id = id;
	this->name = name;
	this->credit = credit;
	//this->expDate = expDate;
}

Date Card::getExpDate() const{
	return expDate;
}
int Card::getID() const{
	return id;
}

