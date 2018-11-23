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
	friend ostream& operator<<(ostream& sp, Card& card);
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

class InvalidCard
{
private:
	string InvCard;
public:
	InvalidCard(string card)
{
		this->InvCard = card;
}
	string getMessage()
	{
		return "O cartao" + InvCard + " nao existe!";
	}
};


#endif /* CARD_H_ */
