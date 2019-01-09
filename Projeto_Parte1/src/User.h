#ifndef USER_H_
#define USER_H_
class Game;

#include <string>
#include <vector>
#include <utility>
#include <tuple>
#include "Date.h"
#include <queue>
//#include "Game.h"
#include "Card.h"
#include <unordered_set>

typedef pair<Game*, double> GAME_PROB; //Jogo mais probabilidade de compra

typedef pair<GAME_PROB, int> WISH_LIST_ITEM; // < <Jogo, probabilidade de compra>, Interessa 0-10>

class heapCompare {
	bool reverse;
public:
	heapCompare(const bool& revparam = false) {
		reverse = revparam;
	}
	bool operator()(const pair<GAME_PROB, int>& lhs,
			const pair<GAME_PROB, int>&rhs) const {

		if (reverse)
			if (lhs.second == rhs.second) {
				return lhs.first.second > rhs.first.second;
			} else
				return (lhs.second > rhs.second);
		else if (lhs.second == rhs.second) {
			return lhs.first.second < rhs.first.second;
		} else
			return (lhs.second < rhs.second);
	}
};

typedef priority_queue<WISH_LIST_ITEM, vector<pair<GAME_PROB, int>>, heapCompare> WISH_LIST_PQ;

class User {
	string name;
	string email;
	int age;
	string address;
	vector<Game *> games;
	vector<Card *> cards;
	vector<pair<Game*, Date*> > updateDate;
	vector<vector<tuple<Game*, int, string> > > playSessions;
	WISH_LIST_PQ wishList;
	vector<GAME_PROB> gameProbVector;
	double buy_prob;
	Date last_buy = Date("01/01/00");

public:
	/**
	 * 	@brief Constroi um novo utilizador vazio.
	 */
	User();

	/**
	 * @brief Constroi um novo utilizador.
	 *
	 * @param name Nome	do utilizador.
	 * @param email Email do utilizador.
	 * @param age Idade do utilizador.
	 * @param address Morada do utilizador.
	 */
	User(string name, string email, int age, string address, double buy_prob,
			string date);
	/**
	 * @brief Retorna o nome do utilizador.
	 * @return Nome do utilizador.
	 */
	string getName() const;
	/**
	 * @brief Retorna o email do utilizador.
	 * @return Email do utilizador.
	 */
	string getEmail() const;
	/**
	 * @brief Retorna a idade do utilizador
	 * @return Idade do utilizador.
	 */
	int getAge() const;
	/***
	 * @brief Retorna a morada do utilizador.
	 * @return Morada do utilizador.
	 */
	string getAddress() const;
	/**
	 * @brief Retorna um vetor de jogos do utilizador.
	 * @return Vetor de jogos que o usuario possui.
	 */
	vector<Game*> getGames() const;

	/**
	 * @brief Retorna um vetor de cartoes do utilizador.
	 * @return Vetor de cartoes que o usuario possui.
	 */
	vector<Card*> getCards() const;

	/**
	 *
	 * @param gameName Nome do jogo a retornar.
	 * @return Pointer para um Game.
	 */
	Game* getGame(string gameName) const;
	/**
	 *
	 * @param cardName Nome do cartao a retornar.
	 * @return Pointer para um Card.
	 */
	Card* getCard(string cardName) const;

	double getBuyProb() const;
	/**
	 * @brief Compra o jogo neste utilizador se ele tiver dinheiro disponivel.
	 *
	 *
	 * @param game Objeto da class Game.
	 */

	void buyGame(Game *game, Card* card);
	/**
	 * @brief Adiciona o cartao card ao utilizador.
	 *
	 *
	 * @param card cartao a adicionar.
	 * @return true Conseguiu adicionar o cartao.
	 * @return false Nao conseguiu adicionar o cartao.
	 */
	void addCard(Card *card);
	/**
	 * @brief Retira o cartao de nome card ao utilizador.
	 *
	 *
	 * @param card Nome do cartao.
	 */
	void removeCard(string card);

	/**
	 * @brief Guarda a informacaoo de tempo jogado.
	 * @param game Jogo jogado.
	 * @param playTime Tempo jogado.
	 */
	void playGame(string gameName, int playTime);
	/**
	 * @brief Ve se o jogo esta atualizado.
	 * @param gameName Nome do ficheiro do jogo.
	 * @return true Se estiver atualizado.
	 * @return false Se nao estiver atualizado.
	 */
	bool isUpdated(string gameName);
	/**
	 * @brief Carregar um utilizador atravas de um ficheiro.
	 *
	 * @param file Nome do ficheiro.
	 */
	void importUserInfo(string file);
	/**
	 *
	 * @brief Guarda a informacao de uma sessao de jogo nunm ficheiro .txt com o mesmo nome do User
	 * @param type	Tipo de sessao tem de ser um char 'P' obrigatoriamente.
	 * @param date	Data da sessao de jogo
	 * @param game	Nome do jogo que foi jogado
	 * @param playTime Duracao da sessao de jogo
	 */
	void exportUserInfo(char type, Date date, Game game, int playTime);

	/**
	 * @brief Guarda a informacao de uma sessao de jogo nunm ficheiro .txt com o mesmo nome do User
	 * @param type	Tipo de sessao tem de ser um char 'U' obrigatoriamente.
	 * @param date	Data da sessao de jogo.
	 * @param game	Nome do jogo que foi jogado.
	 */
	void exportUserInfo(char type, Date date, Game game);
	/**
	 * @brief Faz display de toda a informacao de um utilizador
	 */
	void displayUser() const;
	/**
	 * @brief Overload do operador << para fazer display do nome de um utilizador
	 * @param sp
	 * @param user
	 * @return
	 */
	friend ostream& operator<<(ostream& sp, User& user);

	//ACRESCENTAR FUNÇÕES DA PARTE 2 ABAIXO DESTA LINHA
	/**
	 * @brief Adiciona um WISH_LIST_ITEM à priority queue wishList
	 * @param Game Nome do jogo a ser adicionado
	 * @param wishLevel Inteiro que representa o nivel de interesse de 0-10
	 */
	void addToWishList( Game* Game, int wishLevel);
	/**
	 * @brief Faz display do jogo mais "apelativo" ao utilizador
	 */
	void showBestBuy();
	/**
	 * @brief Faz display da priority queue wishList
	 */
	void showWishList();

	void addToGameProb(Game* Game);

	GAME_PROB getGameProb(Game * game);

	void setLastBuy(Date date);

	Date getLastBuy();

	bool buyTimePast(Date current_date);

};

/*
 struct UserHash
 {
 int operator() (User u1)
 {
 return u1.getBuyProb();
 }

 bool operator() (User u1, User u2)
 {
 return (u1.getBuyProb() == u2.getBuyProb());
 }
 };*/

//typedef std::unordered_set<User, UserHash, UserHash> HashTableUsersAdormecidos;
#endif /* USER_H_ */
