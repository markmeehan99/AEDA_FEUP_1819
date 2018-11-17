/*
 * OnlineGame.cpp
 *
 *  Created on: 06/11/2018
 *      Author: josem
 */

#include "OnlineGame.h"
#include <string>


OnlineGame::OnlineGame(int age_limit, string name, double price, int rating, string platform,
		string genre, string publisher,  float subscriptionCost):Game(age_limit, name, price, rating, platform, genre, publisher) {
	if (subscriptionCost != 0)
	{
		this->subscriptionCost = subscriptionCost;
		this->isMonthlyPayment = true;
	}
	else
	{
		this->subscriptionCost = subscriptionCost;
		this->isMonthlyPayment = false;
	}

}




