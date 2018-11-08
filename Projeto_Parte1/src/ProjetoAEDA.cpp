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

using namespace std;

#include <string>

int main() {

	cout << "!!!Buenos Dias Matosinhos!!!" << endl;

	Date A(12, 2, 18);
	Date B(11, 2, 18);
	int a, b, c;
	while (1) {
		cin >> a;
		cout << endl;
		cin >> b;
		cout << endl;
		cin >> c;
		cout << endl;
		A.setDate(a,b,c);
		cout << A.getDate();

	}

	return 0;
}
