/*
 * OnlineGame.cpp
 *
 *  Created on: 06/11/2018
 *      Author: josem
 */

#include "OnlineGame.h"
#include

OnlineGame::OnlineGame(int age_limit, string name, float price, int rating, string platform,
		string genre, string publisher,  float subscriptionCost) {
	ID++;
	this->age_limit = age_limit;
	this->name = name;
	this->price = price;
	this->rating = rating;
	this->platform = platform;
	this->genre = genre;
	this->publisher = publisher;
	this->id = ID;
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
