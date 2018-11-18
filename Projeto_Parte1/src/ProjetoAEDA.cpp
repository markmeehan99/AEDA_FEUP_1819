//============================================================================
// Name        : ProjetoAEDA.cpp
// Author      : GRUPO 1
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Review.h"
#include "Card.h"
#include "Store.h"
#include "Date.h"
#include "User.h"
#include "Game.h"
#include "HomeGame.h"
#include "OnlineGame.h"

using namespace std;

#include <string>

int main() {

	cout << "!!!Buenos Dias Matosinhos!!!" << endl;

	Date A(12, 2, 18);
	Date B(11, 2, 18);
	User u("Joao", "mail@gmail.com", 32, "rua dos abra�os");
	//Card a(2, "ab", 23, A);
	//Card b(3, "ab", 23, A);
	u.importUserInfo();

	//cout << u.getAge() << endl << u.getEmail() << endl << u.getName() << endl << u.getAddress() << endl;

	HomeGame C(2,"JOGO1", 12, 12,"xBox", "FPS", "UBISOFT");


	OnlineGame E(2,"JOGO2", 12,12,"PS4", "RPG", "Rockstar", 2);



	C.exportGameInfo('P', A, 2);
	C.exportGameInfo('U', A);
	C.exportGameInfo('P', A, 4);
	C.exportGameInfo('P', A, 2);
	C.exportGameInfo('U', A);
	C.exportGameInfo('P', A, 4);
	u.exportUserInfo('P', A, E, 2);
	u.exportUserInfo('U', B, C);

	return 0;
}
