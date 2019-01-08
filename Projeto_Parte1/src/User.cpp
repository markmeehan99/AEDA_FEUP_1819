#include "User.h"
#include "Game.h"
#include "Card.h"
#include <iostream>
#include <fstream>
#include <tuple>

User::User() {
	this->name = "";
	this->email = "";
	this->age = 0;
	this->address = "";
	this->buy_prob = 0.7;
	this->last_buy = Date();
}
User::User(string name, string email, int age, string address, double buy_prob, string date) {
	this->name = name;
	this->email = email;
	this->age = age;
	this->address = address;
	this->buy_prob = buy_prob;
	this->last_buy = Date(date);
}

double User::getBuyProb() const {
	return this->buy_prob;
}

string User::getName() const {
	return name;
}
string User::getEmail() const {
	return email;
}
int User::getAge() const {
	return age;
}
string User::getAddress() const {
	return address;
}

vector<Game*> User::getGames() const {
	return games;
}

vector<Card*> User::getCards() const {
	return cards;
}

void User::addCard(Card *card) {

	for (size_t i = 0; i < cards.size(); i++) {
		if (cards.at(i) == card)
			throw InvalidCard(card->getName());
	}

	cards.push_back(card);
}

void User::buyGame(Game *game, Card* card) {

	for (size_t i = 0; i < games.size(); i++) {
		if (games.at(i) == game) {
			cout << "Game already bought" << endl; //criar excepcao
			return;
		}
	}

	if (game->getPrice() > card->getCredit()) {
		cout << "Not enough money" << endl; //criar excepcao
		return;
	}

	card->removeCredit(game->getPrice());
	games.push_back(game);

	//2a parte do projeto. Verificar se User é adormecido. Se for, adiciona-o a tabela de dispersao do jogo game.

	if (this->buy_prob < 0.7) //0.7 representa o residuo. Se for menor, user e adormecido
			{
		game->addInactiveUser(this);
		cout << "User adormecido foi adicionado a tabela de dispersao!\n";
	}

	cout << "User adormecido foi adicionado a tabela de dispersao!\n";

}

void User::importUserInfo(string file) {
	file += ".txt";
	ifstream is(file);

	string name, email, age, address, prob;

	if (is.is_open()) {
		getline(is, name);
		getline(is, email);
		getline(is, age);
		getline(is, address);
		getline(is, prob);

		this->address = address;
		this->age = stoi(age);
		this->email = email;
		this->name = name;
		this->buy_prob = stod(prob);

		string temp;

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
		}
	} else
		cout << "Nao abriu file" << endl;
}

void userInfoHeader(User *user) {

	string fileName = user->getName() + ".txt";
	fstream File(fileName, ios::app);

	File.seekg(0, ios::end);
	if (File.tellg() == 0) {
		File << user->getName() << endl << user->getEmail() << endl
				<< user->getAge() << endl << user->getAddress() << endl << endl;

	}
}

void User::exportUserInfo(char type, Date date, Game game, int playTime) {
	if (type != 'P')
		cout << "Invalid info type4" << endl;

	userInfoHeader(this);

	string fileName = this->getName() + ".txt";
	fstream File(fileName, ios::app);

	if (File.is_open()) {

		File << type << endl << date.getDate() << endl << "\"" << game.getName()
				<< "\"" << endl << playTime << endl << endl;
	}

	File.close();

}
void User::exportUserInfo(char type, Date date, Game game) {

	if (type != 'U')
		cout << "Invalid info type3" << endl;

	userInfoHeader(this);

	string fileName = this->getName() + ".txt";
	fstream File(fileName, ios::app);

	if (File.is_open()) {

		File << type << endl << date.getDate() << endl << "\"" << game.getName()
				<< "\"" << endl;
	}

	File.close();
}

void User::playGame(string gameName, int playTime) {

	if (playTime <= 0) {
		cout << "Invalid playTime" << endl;
		return;
	}

	int pos = -1;

	for (size_t i = 0; i < games.size(); i++) {
		if (games.at(i)->getName() == gameName) {
			pos = i;
		}
	}
	if (pos == -1) {
		cout << "Game not bought" << endl;
		return;
	}

	playSessions.at(pos).push_back(
			make_tuple(games.at(pos), playTime, games.at(pos)->getPlatform()));
	games.at(pos)->addPlayTime(playTime);
}

void User::removeCard(string card) {

	if (cards.empty())
		throw InvalidCard(card);

	for (unsigned int i = 0; i < cards.size(); i++) {
		if (cards.at(i)->getName() == card){
			cards.erase(cards.begin() + i);
			return;
		}
	}
	throw InvalidCard(card);
}

bool User::isUpdated(string gameName) {
	string file = gameName;
	file += ".txt";
	ifstream is(file);
	string date;
	if (is.is_open()) {
		string temp;
		getline(is, temp);
		getline(is, temp);
		getline(is, temp);
		getline(is, temp);
		getline(is, temp);

		string ignore, type, game, no_hours, lastUpdate = 0;

		//Import user info
		while (!is.eof()) {
			getline(is, type); //TRATAR)
			getline(is, date);
			getline(is, game);
			getline(is, no_hours);
			getline(is, ignore);

			if (type == "U" && game == gameName) {
				lastUpdate = date;
			}
		}
	} else {
		cout << "Nao abriu o ficheiro" << endl;
		return true;
	}
	Date a(date);

	if (this->getGame(gameName)->getLastUpdate() > a) {
		return false;
	} else
		return true;

}

Game* User::getGame(string gameName) const {
	for (size_t i = 0; i < games.size(); i++) {
		if (games.at(i)->getName() == gameName) {
			return games.at(i);
		}
	}
	throw Game::NonExistentGame(gameName);

}

Card* User::getCard(string cardName) const {

	for (size_t i = 0; i < cards.size(); i++) {
		if (cards.at(i)->getName() == cardName) {
			return cards.at(i);
		}
	}
	throw InvalidCard(cardName);
}

ostream& operator<<(ostream& sp, User& user) {
	sp << user.getName();
	return sp;
}
void User::displayUser() const {
	cout << "Nome: " << this->name << endl << "Email: " << this->email << endl
			<< "Idade: " << this->age << endl << "Morada: " << this->address
			<< endl << "Prob: " << this->buy_prob << endl;
}

void User::addToWishList(Game* Game, int wishLevel) {

	if (wishLevel > 10 || wishLevel < 0) {
		cout << "Nivel de interesse invalido\n";
		return;
	}

	double prob = ((double) rand() / (RAND_MAX));

	GAME_PROB a = make_pair(Game, prob);

	gameProbVector.emplace_back(a); //Voltar aqui se houverem erros
	WISH_LIST_ITEM b = make_pair(a, wishLevel);

	wishList.push(b);
}

void User::showBestBuy() {

	cout << "\n O jogo " << wishList.top().first.first->getName()
			<< " da sua Wish List esta a sua espera! Compre ja!\n";
}

void User::showWishList() {

	vector<WISH_LIST_ITEM> toPush;

	while(!wishList.empty()) {
		cout << "\nJogo: " << wishList.top().first.first->getName();
		cout << "  Interesse: " << wishList.top().second;

		toPush.push_back(wishList.top());
		wishList.pop();
	}

	while (!toPush.empty()) {
		wishList.push(toPush.back());
		toPush.pop_back();
	}

}

void User::setLastBuy(Date date)
{
	this->last_buy = date;
}

Date User::getLastBuy()
{
	return this->last_buy;
}

bool User::buyTimePast(Date current_date)
{
	if (this->getLastBuy() > current_date)
	{
		return false;
	}
	return true;
}
