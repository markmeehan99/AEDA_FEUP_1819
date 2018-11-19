/*
 * User.h
 *
 *  Created on: 06/11/2018
 *      Author: josem
 */

#ifndef USER_H_
#define USER_H_

#include <string>
#include <vector>
#include <utility>
#include "Date.h"
#include "Game.h"
#include "Card.h"
#include <tuple>

class User {
	string name;
	string email;
	int age;
	string address;
	vector<Game *> games;
	vector<Card *> cards;
	vector<pair<Game*, Date*> > updateDate;
	vector<vector<tuple<Game*, int, string> > > playSessions;

public:
	User();
	User(string name, string email, int age, string address);

	string getName() const;
	string getEmail() const;
	int getAge() const;
	string getAddress() const;
	vector<Game*> getGames() const;
	vector<Card*> getCards() const;

	void buyGame(Game *game);
	bool addCard(Card *card);

	void playGame(Game *game, int playTime);
	void UpdateGame(int playTime);

	void makeReview(Review *review, Game *game); //REVER UTILIDADE DISTO
	void importUserInfo();
	void exportUserInfo(char type, Date date, Game game, int playTime);
	void exportUserInfo(char type, Date date, Game game);

};

#endif /* USER_H_ */
