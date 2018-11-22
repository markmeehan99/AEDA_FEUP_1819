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

Store store;

void viewData() {

}

void addUser() {
	cout << "Adicionar utilizador por ficheiro(1) ou criar utilizador(2)? "
			"Pressione 0 para voltar atras.\n";
	int input;
	cin >> input;
	if (input == 0)
		return;
	else if (input == 1) {
		string file;
		cout << "Qual é o nome do ficheiro(sem o .txt)?\n";
		cin >> file;
		User *u = new User;
		u->importUserInfo(file);
		store.addUser(u);
	} else if (input == 2) {
		string name;
		string email;
		int age;
		string address;
		cout << "Nome do utilizador:";
		cin >> name;
		cout << "Email:";
		cin >> email;
		cout << "Idade:";
		cin >> age;
		cout << "Morada:";
		cin >> address;
		//ADICIONAR TRY/CATCH E CRIAR A EXCEPTION
		User *u = new User(name, email, age, address);
		store.addUser(u);
	}

}

void editData() {
	cout << "\nO que pretende fazer:\n0-Voltar ao inicio\n"
			"1-Adicionar utilizador\n2-Retirar utilizador\n"
			"3-Alterar utilizador\n4-Adicionar jogo a loja\n"
			"5-Alterar Jogo\n6-Mudar a data\n";
	cout << "Opção:";
	int input;
	cin >> input;
	if (input == 0)
		return;
	else if (input == 1) {
		addUser();
	} else if (input == 2) {

	} else if (input == 3) {

	} else if (input == 4) {

	} else if (input == 5) {

	} else if (input == 6) {
		string d;
		cout << "Escreva a data(dd/mm/aa):\n";
		cin >> d;
		store.changeDate(d);
	} else {
		cout << "Opcao invalida!\n\n";
		editData();
	}
}

void t() {
	string file;
	cout << "Qual é o nome do ficheiro(sem o .txt)?\n";
	cin >> file;
	User *u = new User();
	u->importUserInfo(file);
	store.addUser(u);

}
int main() {

	cout << "!!!Buenos Dias Matosinhos!!!\n" << endl;

	int input;
	while (true) {
		cout << "O que pretende fazer:\n1-Editar Dados\n2-Ver Dados\n3-Sair\n";
		cout << "Opcao: ";
		cin >> input;
		if (input == 1) {
			editData();
		} else if (input == 2) {
			viewData();
		} else if (input == 3) {
			break;
		} else {
			cout << "Opcao invalida!\n\n";
			continue;
		}
	}

	cout << store.getAllUser().at(0)->getAddress() << endl;
	cout << store.getAllUser().size();

	return 0;
}

