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

class Game {
private:
	vector<Review *> reviews;
	int age_limit = 0;
	int id;
	string name;
	float price;
	int rating;
	string platform;
	string genre;
	string publisher;
	int totalPlaytime;
public:
	Game();
	Game(int age_limit, std::string name, float price, int rating,
			string platform, string genre, string publisher);
	string getName() const;
	int getID() const;
	int getAgeLimit() const;
	float getPrice() const;
	int getRating() const;
	string getPlatform() const;
	string getGenre() const;
	string getPublisher() const;
	int getPlaytime() const;
	bool changePrice();
	int getPlayTime() const;

};

#endif /* GAME_H_ */
