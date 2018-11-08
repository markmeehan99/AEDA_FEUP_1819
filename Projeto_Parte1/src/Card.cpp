/*
 * Card.cpp
 *
 *  Created on: 06/11/2018
 *      Author: josem
 */

#include "Card.h"

Card::Card(int id, string name, double credit, string expDate) {

	this->id = id;
	this->name = name;
	this->name = credit;
	this->expDate = expDate;
}

string Card::getExpDate() {
	return expDate;
}
