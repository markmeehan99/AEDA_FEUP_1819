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

using namespace std;

#include <string>

int main() {

	cout << "!!!Buenos Dias Matosinhos!!!" << endl;

	//Date A(12, 2, 18);
	//Date B(11, 2, 18);
	//User u("João", "adasd", 32, "asdas");
	//Card a(2, "ab", 23, A);
	//Card b(3, "ab", 23, A);

	string date = "23/12/99";
	string day = date.substr(0,2);
	string month = date.substr(3,2);
	string year = date.substr(6,2);
	cout << day<< endl << month<< endl << year;
	//cout << u.getCards().size();

	return 0;
}
