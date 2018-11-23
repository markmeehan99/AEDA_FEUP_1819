#include "OnlineGame.h"
#include <string>
#include <fstream>
#include <iostream>

OnlineGame::OnlineGame(int age_limit, string name, double price, int rating,
		string platform, string genre, string publisher,
		double subscriptionCost,  bool isMontlhy) :
		Game(age_limit, name, price, rating, platform, genre, publisher) {
	if (subscriptionCost != 0) {
		this->subscriptionCost = subscriptionCost;
		this->isMonthly = true;
	} else {
		this->subscriptionCost = subscriptionCost;
		this->isMonthly = false;
	}

}

bool OnlineGame::getPaymentMethod() const {
	return isMonthly;
}

double OnlineGame::getSubscriptionCost() const {
	return subscriptionCost;
}

void gameInfoHeader(OnlineGame *game) {

	string fileName = game->getName() + ".txt";
	fstream File(fileName, ios::app);

	File.seekg(0, ios::end);
	if (File.tellg() == 0) {
		File << game->getName() << endl << game->getID() << endl
				<< game->getAgeLimit() << endl << game->getPrice() << endl
				<< game->getRating() << endl << game->getPlatform() << endl
				<< game->getGenre() << endl << game->getPublisher() << endl
				<< game->getTotalPlayTime() << endl << game->getPaymentMethod()
				<< endl << game->getSubscriptionCost() << endl << endl;
	}

}

void OnlineGame::exportGameInfo(char type, Date date, int playTime) { //For PLAY SESSIONS

	if (type != 'P')
		cout << "Invalid info type" << endl;

	gameInfoHeader(this);

	string fileName = this->getName() + ".txt";
	fstream File(fileName, ios::app);

	if (File.is_open()) {

		File << type << endl << date.getDate() << endl << playTime << endl
				<< endl;
	}

	File.close();
}

void OnlineGame::exportGameInfo(char type, Date date) { // for UPDATES
	if (type != 'U')
		cout << "Invalid info type" << endl;

	gameInfoHeader(this);

	string fileName = this->getName() + ".txt";
	fstream File(fileName, ios::app);

	if (File.is_open()) {

		File << type << endl << date.getDate() << endl << endl;
	}

	File.close();
}
