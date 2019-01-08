#ifndef STORE_H_
#define STORE_H_

#include "Date.h"
#include "Game.h"
#include "User.h"
#include "Card.h"
#include <vector>
#include <string>
//#include <set>
#include <unordered_set>

using namespace std;

//typedef unordered_set<User, > HashTableUsers;

class Store {
	vector<User*> userList;
	vector<Game*> allGames;
	Date date = Date(02, 02, 02);
	//HashTableUsers usersAdormecidos;

public:
	/**
	 * @brief Cria uma Store vazia com data default de 02/02/02
	 */
	Store();
	/**
	 * @brief Adiciona um jogo a loja
	 * @param game Pointer para o jogo a adicionar
	 * @return True se consegui adicionar o jogo
	 * @return False se o jogo ja existir na loja
	 */
	bool addGame(Game *game);
	/**
	 * @brief Adiciona um User a loja
	 * @param u Pointer para o User a adicionar
	 * @return True se conseguiu adicionar o User
	 * @return False se o user ja existir
	 */
	bool addUser(User *u);
	/**
	 * @brief Remove o utilizador com o nome passado por argumento
	 * @param userName Nome do utilizador a remover
	 */
	void removeUser(string userName);
	/**
	 * @brief Retorna o vetor de todos os utilizadores existentes
	 * @return Vetor de pointers para todos os utilizadores existentes
	 */
	vector<User*> getAllUser() const;
	/**
	 * @brief Retorna o vetor de todos os Games existentes
	 * @return Vetor de pointers para todos os Games existentes
	 */
	vector<Game*> getAllGames() const;
	/**
	 * 	@brief Retorna um pointer para um jogo
	 * @param gameName Nome do jogo a retornar
	 * @return Pointer para o jogo
	 */
	Game* getGame(string gameName);
	/**
	 * @brief Retorna um pointer para um user
	 * @param userName
	 * @return Pointer para o User
	 */
	User* getUser(string userName);
	/**
	 * @brief Retorna a data atual
	 * @return Data atual
	 */
	Date getDate() const;
	/**
	 * @brief Muda a data atual
	 * @param date Data para qual mudar
	 */
	void changeDate(string date);
	/**
	 * @brief Retorna o numero medio de jogos dos utilizadors todos
	 * @return
	 */
	int averageGames() const;
	/**
	 * @brief Retorna o custo medio das bibliotecas de todos os jogadores
	 * @return
	 */
	double averageCost() const;
	/**
	 * @brief Retorna o vetor de Games ordenado por nome
	 * @return
	 */
	vector<Game*> printsorted() const;

	//ostream& operator<< (ostream& stream);

};

class NonExistentUser {
	string name;
public:
	NonExistentUser(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
};

#endif /* STORE_H_ */
