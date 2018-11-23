//============================================================================
// Name        : ProjetoAEDA.cpp
// Author      : GRUPO 1
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Card.h"
#include "Store.h"
#include "Date.h"
#include "User.h"
#include "Game.h"
#include "HomeGame.h"
#include "OnlineGame.h"

using namespace std;

#include <string>
#include <iomanip>
#include <fstream>

Store store;

void printVector(vector<User*> c) {
	int counter = 0;
	for (User* u : c) {
		if (counter % 3 == 0)
			cout << endl;
		cout << *u << "\t";
		counter++;
	}
	cout << endl;
}
void printVector(vector<Game*> c) {
	int counter = 0;
	for (Game* u : c) {
		if (counter % 3 == 0)
			cout << endl;
		cout << *u << "\t";
		counter++;
	}
	cout << endl;
}
void printVector(vector<Card*> c) {
	int counter = 0;
	for (Card* u : c) {
		if (counter % 3 == 0)
			cout << endl;
		cout << *u << "\t";
		counter++;
	}
	cout << endl;
}

void viewGameinfo() {
	printVector(store.getAllGames());
	cout << "Nome do jogo: \n";
	string gamename;
	cin >> gamename;
	cout << "Preco: " << store.getGame(gamename)->getPrice() << endl;
	cout << "ID: " << store.getGame(gamename)->getID() << endl;
	cout << "Idade limite: " << store.getGame(gamename)->getAgeLimit()
			<< endl;
	cout << "Ratings: " << store.getGame(gamename)->getRating() << endl;
	cout << "Platforma: " << store.getGame(gamename)->getPlatform()
			<< endl;
	cout << "Publicador: " << store.getGame(gamename)->getName() << endl;
	cout << "Tempo jogado por todos os users: "
			<< store.getGame(gamename)->getTotalPlayTime() << endl;
	cout << "Categoria: " << store.getGame(gamename)->getGenre() << endl;
}

void viewGames() {
	cout << setw(10) << "nome:" << setw(7) << "ID: " << setw(7) << "Idade: "
			<< setw(9) << "ratings: " << setw(11) << "platforma: " << setw(12)
			<< "publicador: " << setw(7) << "tempo: " << setw(11)
			<< "categoria: \n";
	for (unsigned int i = 0; i < store.printsorted().size(); i++) {
		cout << setw(10) << store.printsorted().at(i)->getName() << setw(7)
				<< store.printsorted().at(i)->getID() << setw(7)
				<< store.printsorted().at(i)->getAgeLimit() << setw(9)
				<< store.printsorted().at(i)->getRating() << setw(11)
				<< store.printsorted().at(i)->getPlatform() << setw(12)
				<< store.printsorted().at(i)->getPublisher() << setw(7)
				<< store.printsorted().at(i)->getTotalPlayTime() << setw(11)
				<< store.printsorted().at(i)->getGenre();
	}
}

void viewAllUsers() {
	cout << "0- Voltar ao inicio \n" << "1- Numero medio de jogos\n"
			<< "2- Dinheiro medio gasto\n" << "opcao: ";
	int input;
	cin >> input;
	if (input == 0)
		return;
	else if (input == 1) {
		cout << "numero medio de jogos: " << store.averageGames() << endl;
	} else if (input == 2) {
		cout << "dinheiro medio gasto: " << store.averageCost() << endl;
	}
}

void viewUser() {
	printVector(store.getAllUser());
	cout << "Nome do utilizador que quer ver: \n";
	string name;
	cin >> name;
	cout << "0-Voltar ao inicio\n" << "1-ver dados \n" << "2-Ver jogos \n"
			<< "3-Ver cards";
	int opcao;
	cin >> opcao;
	if (opcao == 0) {
		return;
	} else if (opcao == 1) {
		store.getUser(name)->displayUser();
	} else if (opcao == 2) {
		printVector(store.getUser(name)->getGames());
	} else if (opcao == 3) {
		printVector(store.getUser(name)->getCards());
	}

}

void viewData() {
	cout << "\nO que pretende fazer:\n0-Voltar ao inicio\n"
			"1-Ver utilizador \n2-Ver utilizadores \n"
			"3-Ver jogo \n4-Ver jogos \n";
	cout << "Opcao: ";
	int input;
	cin >> input;
	if (input == 0) {
		return;
	} else if (input == 1) {
		viewUser();
	} else if (input == 2) {
		viewAllUsers();
	} else if (input == 3) {
		viewGameinfo();
	} else if (input == 4) {
		viewGames();
	}
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
		cout << "Qual e o nome do ficheiro(sem o .txt)?\n";
		cin >> file;
		User *u = new User;
		u->importUserInfo(file);
		store.addUser(u);
		cout << "Utilizador " << *u << " adicionado!\n\n";
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
		cout << "Utilizador " << *u << " adicionado!\n\n";
	}
}

void removeUser() {
	printVector(store.getAllUser());
	cout << "\nQual utilizador pretende remover? Insira 0 para cancelar\n";
	string name;
	cin >> name;
	if (name == "0")
		return;
	store.removeUser(name);
	cout << "Utilizador " << name << " eliminado!\n\n";
}

void userUpdateGame(string userName, string gameName) {
	if (!store.getUser(userName)->isUpdated(gameName)) {
		store.getUser(userName)->exportUserInfo('U', store.getDate(),
				*store.getGame(gameName));
		cout << "O jogo " << gameName << "foi atualziado!\n\n";
	}
}

bool checkCardDate(Card* c) {
	if (store.getDate() > c->getExpDate()) {
		return false;
	} else
		return true;

}
void userBuyGame(string userName, string gameName, string cardName) {
	if (checkCardDate(store.getUser(userName)->getCard(cardName))) { //TRY/CATCH
		store.getUser(userName)->buyGame(store.getGame(gameName),
				store.getUser(userName)->getCard(cardName));
		userUpdateGame(userName, gameName);
	}
}

void userAddCard(string userName) { //TODO: VALIDAR INPUTS
	int id;
	string name;
	double credit;
	string expDate;
	cout << "Introduza a informacao do cartao:\nCard name: ";
	cin >> name;
	cout << "ID do cartao: ";
	cin >> id;
	cout << "Credito disponivel: ";
	cin >> credit;
	cout << "Data de validade(dd/mm/aa): ";
	cin >> expDate;
	Date d(expDate);
	Card *c = new Card(id, name, credit, expDate);
	store.getUser(userName)->addCard(c);
	cout << "Cartao adicionado com sucesso!\n\n";
}

void userRemoveCard(string userName, string cardName) { //TODO: TRY/CATCH

	store.getUser(userName)->removeCard(cardName);

}
void alterUser() { //TODO: INSERIR TRY/CATCH
	printVector(store.getAllUser());
	cout << "\nQual utilizador pretende alterar? Insira 0 para cancelar\n";
	string userName;
	string gameName;
	string cardName;
	cin >> userName;
	if (userName == "0")
		return;
	cout << "\nO que pretende fazer?\n0-Voltar ao inicio\n1-Jogar jogo\n"
			"2-Atualizar jogo\n3-Comprar jogo\n"
			"4-Adicionar cartao\n5-Remover cartao\n";
	int input;
	cin >> input;
	if (input == 0) {
		return;
	}
	if (input == 1) {
		printVector(store.getAllUser());
		cout << "\nQual jogo quer jogar? Insira 0 para cancelar\n";
		cin >> gameName;
		if (gameName == "0")
			return;
		cout << "\nDurante quanto tempo?\n";
		int t;
		cin >> t;
		store.getUser(userName)->playGame(gameName, t);
		store.getUser(userName)->exportUserInfo('P', store.getDate(),
				*store.getGame(gameName), t);
		store.getGame(gameName)->exportGameInfo('P', store.getDate(), t);
	} else if (input == 2) {
		printVector(store.getUser(userName)->getGames());
		cout << "\nQual jogo quer atualizar? Insira 0 para cancelar\n";
		cin >> gameName;
		if (gameName == "0")
			return;
		userUpdateGame(userName, gameName);
	} else if (input == 3) {
		printVector(store.getAllGames());
		cout << "\nQual jogo quer comprar? Insira 0 para cancelar\n";
		cin >> gameName;
		if (gameName == "0")
			return;
		printVector(store.getUser(userName)->getCards());
		cout << "\nCom qual cartao? Insira 0 para cancelar\n";
		cin >> cardName;
		if (cardName == "0")
			return;
		userBuyGame(userName, gameName, cardName);
	} else if (input == 4) {
		userAddCard(userName);
	} else if (input == 5) {
		printVector(store.getUser(userName)->getCards());
		cout << "\nQual cartao pretende remover? Insira 0 para cancelar\n";
		cin >> cardName;
		if (cardName == "0")
			return;
		userRemoveCard(userName, cardName);
	}
}
void addOnlineGame() {
	cout << "Adicionar jogo por ficheiro(1) ou criar jogo(2)? "
			"Pressione 0 para voltar atras.\n";
	int input;
	cin >> input;
	if (input == 0)
		return;
	else if (input == 1) {
		string file;
		cout << "Qual e o nome do ficheiro(sem o .txt)?\n";
		cin >> file;
		Game *g = new OnlineGame();
		g->importGameInfo(file);
		store.addGame(g);
		cout << "O jogo " << g->getName() << "foi adicionado com sucesso!\n\n";
	} else if (input == 2) {
		string name, platform, genre, publisher;
		int age, price, rating;
		double cost;
		bool paymentMethod;
		cout << "\nNome do jogo: ";
		cin >> name;
		cout << "\nIdade minima recomendada: ";
		cin >> age;
		cout << "\nPreco do jogo:";
		cin >> price;
		cout << "\nClassificacao: ";
		cin >> rating;
		cout << "\nPlataforma: ";
		cin >> platform;
		cout << "\nCategoria: ";
		cin >> genre;
		cout << "\nPublicador: ";
		cin >> publisher;
		cout
				<< "\nSe o jogo for pago mensalmente o valor seguinte sera 1, se for pago por hora de jogo será 0\n";
		cin >> paymentMethod;
		cout << "\nPreco da subscricao:";
		cin >> cost;
		Game *g = new OnlineGame(age, name, price, rating, platform, genre,
				publisher, cost, paymentMethod);
		store.addGame(g);
		cout << "O jogo " << g->getName() << "foi adicionado com sucesso!\n\n";
	}
}

void addHomeGame() {
	cout << "Adicionar jogo por ficheiro(1) ou criar jogo(2)? "
			"Pressione 0 para voltar atras.\n";
	int input;
	cin >> input;
	if (input == 0)
		return;
	else if (input == 1) {
		string file;
		cout << "Qual e o nome do ficheiro(sem o .txt)?\n";
		cin >> file;
		Game *g = new HomeGame();
		g->importGameInfo(file);
		store.addGame(g);
		cout << "O jogo " << g->getName() << "foi adicionado com sucesso!\n\n";
	} else if (input == 2) {
		string name, platform, genre, publisher;
		int age, price, rating;
		cout << "\nNome do jogo: ";
		cin >> name;
		cout << "\nIdade minima recomendada: ";
		cin >> age;
		cout << "\nPreco do jogo:";
		cin >> price;
		cout << "\nClassificacao: ";
		cin >> rating;
		cout << "\nPlataforma: ";
		cin >> platform;
		cout << "\nCategoria: ";
		cin >> genre;
		cout << "\nPublicador: ";
		cin >> publisher;
		Game *g = new HomeGame(age, name, price, rating, platform, genre,
				publisher);
		store.addGame(g);
		cout << "O jogo " << g->getName() << "foi adicionado com sucesso!\n\n";
	}
}

void addGame() {
	int input;
	cout << "O jogo e Online(1) ou Home(2)? Insira 0 para cancelar\n ";
	cin >> input;
	if (input == 0)
		return;
	else if (input == 1)
		addOnlineGame();

	else if (input == 2)
		addHomeGame();
	else
		cout << "Opcao Invalida!";
	return;

}

void updateGame(){
	string name;
	printVector(store.getAllUser());
	cout << "Nome do jogo: ";
	cin >> name;

	store.getGame(name)->update(store.getDate());
	cout << "o Jogo foi atualizado. \n";

}


void editData() {
	cout << "\nO que pretende fazer?\n0-Voltar ao inicio\n"
			"1-Adicionar utilizador\n2-Retirar utilizador\n"
			"3-Alterar utilizador\n4-Adicionar jogo a loja\n"
			"5-Atualizar Jogo\n6-Mudar a data\n";
	cout << "Opcao:";
	int input;
	cin >> input;
	if (input == 0)
		return;
	else if (input == 1) {
		addUser();
	} else if (input == 2) {
		removeUser();
	} else if (input == 3) {
		alterUser();
	} else if (input == 4) {
		addGame();
	} else if (input == 5) {
		updateGame();
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
	cout << "Qual e o nome do ficheiro(sem o .txt)?\n";
	cin >> file;
	User *u = new User();
	u->importUserInfo(file);
	store.addUser(u);

}
int main() {

	cout << "!!!Buenos Dias Matosinhos!!!\n" << endl;

	int input;
	while (true) {
		cout << "O que pretende fazer?\n1-Editar Dados\n2-Ver Dados\n3-Sair\n";
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

	/*cout << store.getAllUser().at(0)->getName() << endl;
	 cout << store.getAllUser().size();
	 cout << *store.getAllUser().at(0) << endl;
	 cout << *store.getAllUser().at(1) << endl;*/

	return 0;
}
