#include "Game.h"
#include <iostream>
#include <string>
#include <fstream>

int Game::ID = 0;

bool empty(std::fstream& pFile);

Game::Game(){

}

Game::Game(int age_limit, string name, double price, int rating, string platform,
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

string Game::getName() const {
	return name;
}
int Game::getID() const {
	return id;
}

int Game::getAgeLimit() const {
	return age_limit;
}
double Game::getPrice() const {
	return price;
}
int Game::getRating() const {
	return rating;
}
string Game::getPlatform() const {
	return platform;
}
string Game::getGenre() const {
	return genre;
}
string Game::getPublisher() const {
	return publisher;
}


void gameInfoHeader(Game *game) {

	string fileName = game->getName() + ".txt";
	fstream File(fileName, ios::app);

	File.seekg(0, ios::end);
	if (File.tellg() == 0) {
		File << game->getName() << endl << game->getID() << endl
				<< game->getAgeLimit() << endl << game->getPrice() << endl
				<< game->getRating() << endl << game->getPlatform() << endl
				<< game->getGenre() << endl << game->getPublisher() << endl
				<< game->getTotalPlayTime() << endl<< endl;
	}

}

void Game::exportGameInfo(char type, Date date, int playTime) {

	if (type != 'P')
		cout << "Invalid info type" << endl;

	gameInfoHeader(this);

	string fileName = this->getName() + ".txt";
	fstream File(fileName, ios::app);

	if (File.is_open()) {

		File << type << endl << date.getDate() << endl << playTime << endl<< endl;
	}

	File.close();
}

void Game::exportGameInfo(char type, Date date) {

	if (type != 'U')
		cout << "Tipo de informacao invalido" << endl;

	gameInfoHeader(this);

	string fileName = this->getName() + ".txt";
	fstream File(fileName, ios::app);

	if (File.is_open()) {

		File << type << endl << date.getDate() << "***Ignorar linha***"<< endl<<endl;
	}

	File.close();
	this->lastUpdate = date;
}

int Game::getTotalPlayTime() const {
	return this->totalPlaytime;
}

void Game::addPlayTime(int playTime){

	totalPlaytime += playTime;
}

double Game::getSubscriptionCost() const{

}
ostream& operator<<(ostream& sp, Game& game){
	sp << game.getName();
	return sp;
}

Date Game::getLastUpdate() const{
	return lastUpdate;
}

bool Game::operator<(const Game& other){
	return (this->name < other.getName());
}

void Game::importGameInfo(string file){

}


void Game::update(Date date){
	this->lastUpdate = date;
}
