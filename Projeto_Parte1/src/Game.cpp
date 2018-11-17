/*
 * Game.cpp
 *
 *  Created on: 06/11/2018
 *      Author: josem
 */

#include "Game.h"
#include <iostream>
#include <string>
#include <fstream>

static int ID = 0;

bool empty(std::fstream& pFile);

Game::Game(int age_limit, string name, float price, int rating, string platform,
		string genre, string publisher) {
	ID++;
	this->age_limit = age_limit;
	this->name = name;
	this->price = price;
	this->rating = rating;
	this->platform = platform;
	this->genre = genre;
	this->publisher = publisher;
	this->id = ID;
}

string Game::getName() const {
	return name;
}
int Game::getID() const {
	return id;
}

int Game::getAgeLimit() const {
	return age_limit;
}
float Game::getPrice() const {
	return price;
}
int Game::getRating() const {
	return rating;
}
string Game::getPlatform() const {
	return platform;
}
string Game::getGenre() const {
	return genre;
}
string Game::getPublisher() const {
	return publisher;
}
int Game::getPlayTime() const {
	return totalPlaytime;
}

void Game::exportGameInfo(char type, Date date, int playTime) {

	if (type != 'P')
		cout << "Invalid info type" << endl;

	string fileName = this->getName() + ".txt";

	fstream File(fileName, ios::app);

	/*if (File.tellg() == 0) {
	 File << this->getName() << endl << this->getID() << endl
	 << this->getAgeLimit() << endl << this->getPrice() << endl
	 << this->getRating() << endl << this->getPlatform() << endl
	 << this->getGenre() << endl << this->getPublisher() << endl
	 << this->getPlayTime();
	 }*/

	if (File.is_open()) {

		File << type << " " << date.getDate() << " " << playTime << endl;
	}

	File.close();
}
void Game::exportGameInfo(char type, Date date) {

	if (type != 'U')
		cout << "Invalid info type" << endl;

	string fileName = this->getName() + ".txt";

	fstream File(fileName, ios::app);

	if (File.is_open()) {

		File << type << " " << date.getDate() << endl;
	}

	File.close();

}
