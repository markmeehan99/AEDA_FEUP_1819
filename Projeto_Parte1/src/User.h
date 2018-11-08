/*
 * User.h
 *
 *  Created on: 06/11/2018
 *      Author: josem
 */

#ifndef USER_H_
#define USER_H_

#include "Date.h"
#include "Game.h"
#include "Card.h"
#include <string>
#include <vector>

class User {
	string name;
	string email;
	int age;
	string address;
	vector<Game*> games;
	vector <Card*> cards;

public:
	User();
	User(string name, string email, int age,string address);

	string getName() const;
	string getEmail() const;
	int getAge() const;
	vector <Game*> getGames() const;
	vector <Card*> getCards() const;

	bool buyGame(Game *game);
	bool addCard(Card *card);
	void makeReview(Review *review, Game *game);//REVER UTILIDADE DISTO
	void importUserInfo();

};

#endif /* USER_H_ */
