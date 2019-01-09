/*
 * Empresa.h
 *
 *  Created on: 08/01/2019
 *      Author: david
 */

#ifndef EMPRESA_H_
#define EMPRESA_H_
#include "Game.h"
#include <string>
#include <vector>

class Empresa {
protected:
	string name;
	int nib;
	int contacto;
	vector<Game*> games;

public:

	Empresa();
	Empresa(string file);
	vector<Game*> Getgames() const;
	void Addgame(Game *game);
	string getName() const;
	int getNib() const;
	int getContacto() const;
	bool operator<(const Empresa &c1);
	bool operator==(const Empresa &c1);


};

#endif /* EMPRESA_H_ */
