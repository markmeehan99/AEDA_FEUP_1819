#ifndef HOMEGAME_H_
#define HOMEGAME_H_

#include "Game.h"
#include "Date.h"
#include <string>

using namespace std;

class HomeGame: public Game {
private:

public:
	HomeGame();
	HomeGame(int age_limit, string name, double price, int rating,
			string platform, string genre, string publisher);
	void importGameInfo(string file);
};

#endif /* HOMEGAME_H_ */
