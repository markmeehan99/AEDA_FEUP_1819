/*
 * Empresa.cpp
 *
 *  Created on: 08/01/2019
 *      Author: david
 */

#include <fstream>
#include <iostream>
#include "Empresa.h"
using namespace std;


Empresa::Empresa(){
	this->contacto = 0;
	this->name = "";
	this->nib = 0;
}


vector<Game*> Empresa::Getgames() const{
	return this->games;
}

void Empresa::Addgame(Game *game){
	this->games.push_back(game);
}

int Empresa::getNib() const{
	return this->nib;
}

int Empresa::getContacto() const{
	return this->contacto;
}

string Empresa::getName() const{
	return this->name;
}

Empresa::Empresa(string file){
	file += ".txt";

	ifstream File(file);
	string name,  numero, nib;
	if (File.is_open()) {
		getline(File, name);
		getline(File, numero);
		getline(File, nib);
	}
	else{
		cout << "Nao abriu o ficheiro." << endl;
	}
	File.close();
	this->contacto = stoi(numero);
	this->name = name;
	this->nib = stoi(nib);
}


bool Empresa::operator<(const Empresa &c1){
	if (this->games.size() < c1.Getgames().size()){
		return true;
	}
	else if (this->games.size() > c1.Getgames().size()){
		return false;
	}
	else if (this->games.size() == c1.Getgames().size()){
		if (this->name < c1.getName()){
			return true;
		}
	}
	return false;
}


bool Empresa::operator==(const Empresa &c1){
	if (this->name == c1.getName()){
		return true;
	}
	else{
		return false;
	}
}
