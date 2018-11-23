#ifndef STORE_H_
#define STORE_H_

#include "Date.h"
#include "Game.h"
#include "User.h"
#include "Card.h"
#include <vector>
#include <string>

using namespace std;

class Store {
  vector<User*> userList;
  vector<Game*> allGames;
  Date date;

public:
  Store();
  bool addGame(Game *game);
  bool addUser(User *u);
  void removeUser(string userName);
  vector<User*> getAllUser() const;
  vector<Game*> getAllGames() const;
  Game* getGame(string gameName);
  User* getUser(string userName);
  Date getDate() const;
  void changeDate(string date);
  int averageGames() const;
  double averageCost() const;
  vector<Game*> printsorted() const;

};


class NonExistentUser{
  string name;
public:
  NonExistentUser(string name){this->name = name;}
  string getName(){return name;}
};


#endif /* STORE_H_ */
