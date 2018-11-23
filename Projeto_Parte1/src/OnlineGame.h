#ifndef ONLINEGAME_H_
#define ONLINEGAME_H_

#include "Game.h"
#include <string>

using namespace std;

class OnlineGame: public Game {
private:
	bool isMonthly;
	double subscriptionCost;
public:
	OnlineGame();
	OnlineGame(int age_limit, string name, double price, int rating,
			string platform, string genre, string publisher,
			double subscriptionCost, bool isMonthly);
	bool getPaymentMethod() const;
	double getSubscriptionCost() const;
	void exportGameInfo(char type, Date date, int playTime); //overload for Updates
	void exportGameInfo(char type, Date date);
	void importGameInfo(string file);
};

#endif /* ONLINEGAME_H_ */
