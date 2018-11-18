/*
 * User.cpp
 *
 *  Created on: 06/11/2018
 *      Author: josem
 */

#include "User.h"
#include "Game.h"
#include "Card.h"
#include <iostream>
#include <fstream>

User::User() {
	// TODO Auto-generated constructor stub
}
User::User(string name, string email, int age, string address) {
	this->name = name;
	this->email = email;
	this->age = age;
	this->address = address;
}

string User::getName() const {
	return name;
}
string User::getEmail() const {
	return email;
}
int User::getAge() const {
	return age;
}
string User::getAddress() const {
	return address;
}

vector<Game*> User::getGames() const {
	return games;
}

vector<Card*> User::getCards() const {
	return cards;
}

bool User::addCard(Card *card) {

	for (size_t i = 0; i < cards.size(); i++) {
		if (cards.at(i) == card)
			return false;
	}

	cards.push_back(card);
	return true;
}

void User::buyGame(Game *game) {

	for (size_t i = 0; i < games.size(); i++) {
		if (games.at(i) == game) {
			cout << "Game already bought" << endl; //criar excep��o
			return;
		}
	}

	int c = -1;
	for (size_t i = 0; i < cards.size(); i++) {
		if (game->getPrice() < cards.at(i)->getCredit()) {
			c = i;
		}
	}
	if (c == -1) {
		cout << "Not enough money" << endl; //criar excep��o
		return;
	}

	cards.at(c)->removeCredit(game->getPrice());
	games.push_back(game);
}

void userInfoHeader(User *user) {

	string fileName = user->getName() + ".txt";
	fstream File(fileName, ios::app);

	File.seekg(0, ios::end);
	if (File.tellg() == 0) {
		File << user->getName() << endl << user->getEmail() << endl
				<< user->getAge() << endl << user->getAddress() << endl << endl;

	}
}

void User::exportUserInfo(char type, Date date, Game game, int playTime) {
	if (type != 'P')
		cout << "Invalid info type4" << endl;

	userInfoHeader(this);

	string fileName = this->getName() + ".txt";
	fstream File(fileName, ios::app);

	if (File.is_open()) {

		File << type << endl << date.getDate() << endl << "\"" << game.getName()<<"\"" << endl
				<< playTime << endl << endl;
	}

	File.close();

}
void User::exportUserInfo(char type, Date date, Game game) {

	if (type != 'U')
		cout << "Invalid info type3" << endl;

	userInfoHeader(this);

	string fileName = this->getName() + ".txt";
	fstream File(fileName, ios::app);

	if (File.is_open()) {

	File << type << endl << date.getDate() << endl<< "\"" << game.getName()<<"\"" <<endl;
}

File.close();
}

