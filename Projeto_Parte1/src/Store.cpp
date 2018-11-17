/*
 * Store.cpp
 *
 *  Created on: 06/11/2018
 *      Author: josem
 */

#include "Store.h"
#include <vector>

/*Store::Store() {

 }*/

bool Store::addGame(Game *game) {

	for (size_t i = 0; i < allGames.size(); i++) {
		if (allGames.at(i)->getName() == game->getName())
			return false;
	}
	allGames.push_back(game);

	return true;
}

Game* Store::getGame(string gameName) {

	for (size_t i = 0; i < allGames.size(); i++) {
		if (allGames.at(i)->getName() == gameName)
			return allGames.at(i);
	}

	throw NonExistentGame(gameName);
}

User* Store::getUser(string userName) {
	User *u = new User();

	for (size_t i = 0; i < userList.size(); i++) {
		if (userList.at(i)->getName() == userName)
			return userList.at(i);
	}

	return u;
}
