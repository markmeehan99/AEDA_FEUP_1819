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
	//User u("Jo�o", "adasd", 32, "asdas");
	//Card a(2, "ab", 23, A);
	//Card b(3, "ab", 23, A);

	HomeGame C(2,"GAME", 12,12,"aa", "aaa", " aaaa");

	C.exportGameInfo('P', A, 2);
	C.exportGameInfo('U', A);

	return 0;
}
