/*
 * Game.cpp
 *
 *  Created on: 06/11/2018
 *      Author: josem
 */

#include "Game.h"
#include <string>

static int ID = 0;

Game::Game() {

}

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
int Game::getPlaytime() const {
	return totalPlaytime;
}

