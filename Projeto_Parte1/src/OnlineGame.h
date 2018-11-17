/*
 * OnlineGame.h
 *
 *  Created on: 06/11/2018
 *      Author: josem
 */

#ifndef ONLINEGAME_H_
#define ONLINEGAME_H_

#include "Game.h"
#include <string>

using namespace std;

class OnlineGame: public Game {
private:
	bool isMonthlyPayment;
	float subscriptionCost;
public:
	OnlineGame(int age_limit, string name, float price, int rating,
			string platform, string genre, string publisher, float subscriptionCost);
};

#endif /* ONLINEGAME_H_ */
