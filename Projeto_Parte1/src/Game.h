#ifndef GAME_H_
#define GAME_H_

#include "Date.h"
#include <vector>
#include <string>

using namespace std;

class Game {
private:
	int age_limit = 0;
	int id;
	string name;
	double price;
	int rating;
	string platform;
	string genre;
	string publisher;
	int totalPlaytime = 0;
	Date lastUpdate = Date(1, 1, 00);
public:
	Game(int age_limit, string name, double price, int rating, string platform,
			string genre, string publisher);
	string getName() const;
	int getID() const;
	int getAgeLimit() const;
	double getPrice() const;
	int getRating() const;
	string getPlatform() const;
	string getGenre() const;
	string getPublisher() const;
	int getTotalPlayTime() const;
	Date getLastUpdate() const;
	void addPlayTime(int playTime);
	bool changePrice();
	virtual void exportGameInfo(char type, Date date, int playTime); //overload for Updates
	virtual void exportGameInfo(char type, Date date);
	void importGameInfo();
	virtual double getSubscriptionCost() const;
	friend ostream& operator<<(ostream& sp, Game& game);
  bool operator<(const Game& other);

	class NonExistentGame{
		string name;
	public:
		NonExistentGame(string name){this->name = name;}
		string getName(){return name;}
	};

};


#endif /* GAME_H_ */
