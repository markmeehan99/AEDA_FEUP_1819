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

void User::buyGame(Game *game){

	for (size_t i = 0; i < games.size(); i++) {
			if (games.at(i) == game){
				cout << "Game already bought" << endl; //criar excepção
				return;
			}
		}

	int c= -1;
	for (size_t i = 0; i < cards.size(); i++) {
			if(game->getPrice() < cards.at(i)->getCredit()){
					c = i;
			}
	}
	if(c == -1){
		cout << "Not enough money" << endl; //criar excepção
		return;
	}

	cards.at(c)->removeCredit(game->getPrice());
	games.push_back(game);
}
