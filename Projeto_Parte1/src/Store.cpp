#include "Store.h"
#include <vector>

Store::Store() {

 }

bool Store::addGame(Game *game) {

	for (size_t i = 0; i < allGames.size(); i++) {
		if (allGames.at(i)->getName() == game->getName())
			return false;
	}
	allGames.push_back(game);

	return true;
}
bool Store::addUser(User *u) {

	for (size_t i = 0; i < userList.size(); i++) {
		if (userList.at(i)->getName() == u->getName())
			return false;
	}
	userList.push_back(u);

	return true;
}


Game* Store::getGame(string gameName) {

	for (size_t i = 0; i < allGames.size(); i++) {
		if (allGames.at(i)->getName() == gameName)
			return allGames.at(i);
	}

	throw Game::NonExistentGame(gameName);
}

void Store::changeDate(string date){
	this->date.setDate(date);

}

User* Store::getUser(string userName) {
	User *u = new User();

	for (size_t i = 0; i < userList.size(); i++) {
		if (userList.at(i)->getName() == userName)
			return userList.at(i);
	}

	return u;
}
vector<User*> Store::getAllUser() const{
	return userList;
}
vector<Game*> Store::getAllGames() const{
	return allGames;
}

void Store::removeUser(string userName){

	for (size_t i = 0; i < userList.size(); i++) {
		if (userList.at(i)->getName() == userName){
			userList.erase(userList.begin()+i);
			return;
		}
	}
	throw NonExistentUser(userName);
}

Date Store::getDate() const{
	return date;
}
int Store::averageGames() const{
	int counter = 0;
	for (int i = 0; i < getAllUser().size(); i++){
		counter += getAllUser().at(i)->getGames().size();
	}
	counter = counter / getAllUser().size();
	return counter;
}

double Store::averageCost() const{
	double counter=0;
		for (int i = 0; i < getAllUser().size(); i++){
			for (int k = 0; k < getAllUser().at(i)->getGames().size(); k++){
				counter += getAllUser().at(i)->getGames().at(k)->getPrice();
			}
		}
		counter = counter / getAllUser().size();
		return counter;
}

vector<Game*> Store::printsorted() const{
	vector <Game*> temp = allGames;

	/*for (unsigned int j = 0; j < temp.size() - 1; ++j) {

	    int min = j;
	    for (unsigned int i = j+1; i < temp.size(); ++i) {
	        if (temp.at(min) > temp.at(i)) {
	            min = i;
	        }

	    }
	    if (min != j)
	        swap(temp.at(j), temp.at(min));
	}


	return temp;*/
}
