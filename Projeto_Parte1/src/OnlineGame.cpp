#include "OnlineGame.h"
#include <string>
#include <fstream>
#include <iostream>

OnlineGame::OnlineGame() {

}

OnlineGame::OnlineGame(int age_limit, string name, double price, int rating,
		string platform, string genre, string publisher,
		double subscriptionCost, bool isMontlhy) :
		Game(age_limit, name, price, rating, platform, genre, publisher) {
	if (subscriptionCost > 0)
		this->subscriptionCost = subscriptionCost;

	this->isMonthly = isMontlhy;

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
		File << game->getName() << endl << game->getAgeLimit() << endl
				<< game->getPrice() << endl << game->getRating() << endl
				<< game->getPlatform() << endl << game->getGenre() << endl
				<< game->getPublisher() << endl << game->getTotalPlayTime()
				<< endl << game->getPaymentMethod() << endl
				<< game->getSubscriptionCost() << endl << endl;
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

void OnlineGame::importGameInfo(string file) {
	file += ".txt";
	ifstream is(file);

	string name, age, price, rating, platform, genre, publisher, totalPlayTime,
			payMethod, cost;

	if (is.is_open()) {
		getline(is, name);
		getline(is, age);
		getline(is, price);
		getline(is, rating);
		getline(is, platform);
		getline(is, genre);
		getline(is, publisher);
		getline(is, totalPlayTime);
		getline(is, payMethod);
		getline(is, cost);

		ID++;
		this->age_limit = stoi(age);
		this->name = name;
		this->price = stoi(price);
		this->rating = stoi(rating);
		this->platform = platform;
		this->genre = genre;
		this->publisher = publisher;
		this->id = ID;
		this->subscriptionCost = stoi(cost);
		this->isMonthly = stoi(payMethod);

		/*string temp;

		 getline(is, temp);
		 getline(is, temp);

		 string ignore, type, date, game, no_hours;

		 //Import user info
		 while (!is.eof()) {
		 getline(is, type); //TRATAR)
		 getline(is, date);
		 getline(is, game);
		 getline(is, no_hours);
		 getline(is, ignore);

		 for (Game* g : games) {
		 if (g->getName() == game) {
		 //found game
		 Date *d = new Date(date);

		 this->updateDate.push_back(make_pair(g, d));
		 }
		 }
		 }*/
	} else
		cout << "Nao abriu file" << endl;

}
