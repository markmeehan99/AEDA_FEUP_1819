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

double Card::getCredit() const{
	return credit;
}

void Card::addCredit(double amount){

	if(amount <=0)
		throw InvalidAmount(amount);

	credit += amount;
}

void Card::removeCredit(double amount){

	if(amount <= 0 || amount > credit){
		throw InvalidAmount(amount);
	}

	credit -= amount;
}



