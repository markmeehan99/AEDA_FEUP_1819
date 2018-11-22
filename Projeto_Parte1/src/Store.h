/*
 * Store.h
 *
 *  Created on: 06/11/2018
 *      Author: josem
 */

#ifndef STORE_H_
#define STORE_H_

#include "Date.h"
#include "Game.h"
#include "User.h"
#include "Card.h"
#include <vector>
#include <string>

using namespace std;

class Store {
	vector<User*> userList;
	vector<Game*> allGames;
	Date date;

public:
	Store();
	bool addGame(Game *game);
	bool addUser(User *u);
	vector<User*> getAllUser() const;
	vector<Game*> getAllGames() const;
	Game* getGame(string gameName);
	User* getUser(string userName);
	void changeDate(string date);

};

class NonExistentGame{
	string name;
public:
	NonExistentGame(string name){this->name = name;}
	string getName(){return name;}
};

#endif /* STORE_H_ */
