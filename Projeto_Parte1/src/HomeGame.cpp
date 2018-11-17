/*
 * HomeGame.cpp
 *
 *  Created on: 06/11/2018
 *      Author: josem
 */

#include "HomeGame.h"

HomeGame::HomeGame(int age_limit, string name, float price, int rating, string platform,
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
