/*
 * HomeGame.h
 *
 *  Created on: 06/11/2018
 *      Author: josem
 */

#ifndef HOMEGAME_H_
#define HOMEGAME_H_

#include "Game.h"
#include "Date.h"
#include <string>

using namespace std;

class HomeGame: public Game {
private:
	Date lastUpdate =  Date(1,1,00);
public:
	HomeGame(int age_limit, string name, double price, int rating,
			string platform, string genre, string publisher);
};

#endif /* HOMEGAME_H_ */
