#include "OnlineGame.h"
#include <string>
#include <fstream>
#include <iostream>

OnlineGame::OnlineGame() {

}

OnlineGame::OnlineGame(int age_limit, string name, double price, int rating,
		string platform, string genre, Empresa *publisher,
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
				<< game->getPublisher()->getName() << endl << game->getTotalPlayTime()
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

void OnlineGame::importGameInfo(string file, BST<Empresa*> empresas) {
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
		this->id = ID;
		this->subscriptionCost = stoi(cost);
		this->isMonthly = stoi(payMethod);

		BSTItrIn<Empresa*> itr(empresas);
		while(!itr.isAtEnd()){
			if (itr.retrieve()->getName() == publisher){
				this->publisher = itr.retrieve();
				break;
			}
			itr.advance();
		}


	} else
		cout << "Nao abriu file" << endl;
	is.close();
}
