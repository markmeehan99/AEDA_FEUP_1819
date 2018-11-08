/*
 * Card.h
 *
 *  Created on: 06/11/2018
 *      Author: josem
 */

#ifndef CARD_H_
#define CARD_H_

#include <string>

using namespace std;

class Card {
	int id;
	string name;
	double credit;
	string expDate;
public:
	Card(int id, string name, double credit, string expDate);
	string getExpDate();
	double getCredit() const;

};

#endif /* CARD_H_ */
