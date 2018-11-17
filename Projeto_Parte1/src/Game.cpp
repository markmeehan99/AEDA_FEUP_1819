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

Game::Game(int age_limit, string name, double price, int rating, string platform,
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
double Game::getPrice() const {
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

void gameInfoHeader(Game *game) {

	string fileName = game->getName() + ".txt";
	fstream File(fileName, ios::app);

	File.seekg(0, ios::end);
	if (File.tellg() == 0) {
		File << game->getName() << endl << game->getID() << endl
				<< game->getAgeLimit() << endl << game->getPrice() << endl
				<< game->getRating() << endl << game->getPlatform() << endl
				<< game->getGenre() << endl << game->getPublisher() << endl
				<< game->getPlayTime() << endl;
	}

}

void Game::exportGameInfo(char type, Date date, int playTime) {

	if (type != 'P')
		cout << "Invalid info type" << endl;

	gameInfoHeader(this);

	string fileName = this->getName() + ".txt";
	fstream File(fileName, ios::app);

	if (File.is_open()) {

		File << type << " " << date.getDate() << " " << playTime << endl;
	}

	File.close();
}

void Game::exportGameInfo(char type, Date date) {

	if (type != 'U')
		cout << "Invalid info type" << endl;

	gameInfoHeader(this);

	string fileName = this->getName() + ".txt";
	fstream File(fileName, ios::app);

	if (File.is_open()) {

		File << type << " " << date.getDate() << endl;
	}

	File.close();
}
