/*
 * Game.h
 *
 *  Created on: 06/11/2018
 *      Author: josem
 */

#ifndef GAME_H_
#define GAME_H_

#include "Review.h"
#include <vector>
#include <string>

using namespace std;

class Game{
private:
	vector<Review *> reviews;
	int age_limit;
	int id;
	std::string name;
	float price;
	int rating;
	string platform;
	string genre;
	string publisher;
public:
	Game(int age_limit, int id, std::string name, float price, int rating,
			string platform, string genre, string publisher);
	int getID() const;
	int getAgeLimit() const;
	float getPrice() const;
	int getRating() const;
	string getPlatform() const;
	string getGenre() const;
	string getPublisher() const;

};

#endif /* GAME_H_ */
