#ifndef GAME_H_
#define GAME_H_

#include "Date.h"
#include <vector>
#include <string>

using namespace std;

class Game {
protected:
	static int ID;
	int age_limit = 0;
	int id;
	string name;
	double price;
	int rating;
	string platform;
	string genre;
	string publisher;
	int totalPlaytime = 0;
	Date lastUpdate = Date(1, 1, 1);
public:
	/**
	 * @brief Cria um jogo vazio
	 */
	Game();
	/**
	 * @brief Cria um Game com os parametros dados
	 * @param age_limit Idade minima para poder jogar o jogo
	 * @param name Nome do jogo
	 * @param price Preco do jogo
	 * @param rating Classificacao do jogo
	 * @param platform Plataforma
	 * @param genre Categoria
	 * @param publisher Publicador
	 */
	Game(int age_limit, string name, double price, int rating, string platform,
			string genre, string publisher);
	/**
	 * @brief Retorna o nome do jogo.
	 * @return Nome do jogo.
	 */
	string getName() const;
	/**
	 * @brief Retorna o ID do jogo.
	 * @return ID do jogo.
	 */
	int getID() const;
	/**
	 * Retorna a idade minima para jogar o jogo.
	 * @return Idade minima.
	 */
	int getAgeLimit() const;
	/**
	 * @brief Retorna o preco do jogo.
	 * @return Preco do jogo.
	 */
	double getPrice() const;
	/**
	 * @briefRetorna a classificacao do jogo.
	 * @return Classificacao.
	 */
	int getRating() const;
	/**
	 * @brief Retorna a plataforma do jogo.
	 * @return Plataforma.
	 */
	string getPlatform() const;
	/**
	 * @brief Retorna a categoria do jogo.
	 * @return Categoria.
	 */
	string getGenre() const;
	/**
	 * @brief Retorna o publicador do jogo.
	 * @return Publicador do jogo.
	 */
	string getPublisher() const;
	/**
	 * @brief Retorna o tempo total que todos os utilizadores jogaram desse jogo.
	 * @return Tempo total de jogo.
	 */
	int getTotalPlayTime() const;
	/**
	 * @brief Retorna a ultima vez que o jogo foi atualizado.
	 * @return Ultima atuallizacao.
	 */
	Date getLastUpdate() const;
	/**
	 * @brief Adiciona ao total de horas jogadas.
	 * @param playTime Numero de horas jogadas.
	 */
	void addPlayTime(int playTime);

	/**
	 *
	 * @brief Guarda a informacao de uma sessao de jogo nunm ficheiro .txt com o mesmo nome do Game.
	 * @param type	Tipo de sess�o tem de ser um char 'P' obrigatoriamente.
	 * @param date	Data da sessao de jogo.
	 * @param playTime Duracao da sessao de jogo.
	 */
	virtual void exportGameInfo(char type, Date date, int playTime); //overload for Updates

	/**
	 * @brief Guarda a informacao de uma sessao de jogo nunm ficheiro .txt com o mesmo nome do Game.
	 * @param type	Tipo de sess�o tem de ser um char 'U' obrigatoriamente.
	 * @param date	Data da sessao de jogo.
	 */
	virtual void exportGameInfo(char type, Date date);
	/**
	 * @brief Carregar um jogo atraves de um ficheiro.
	 * @param file Nome do ficheiro  a ser carregado sem o .txt.
	 */
	virtual void importGameInfo(string file);
	/**
	 *  @brief Retorna o pre�o de subscricao do jogo.
	 */
	virtual double getSubscriptionCost() const;
	/**
	 * @brief Operador para fazer display do nome do Game.
	 * @param sp
	 * @param game
	 * @return	Nome do jogo
	 */
	friend ostream& operator<<(ostream& sp, Game& game);
  bool operator<(const Game& other);

	class NonExistentGame{
		string name;
	public:
		NonExistentGame(string name){this->name = name;}
		string getName(){return name;}
	};

};


#endif /* GAME_H_ */
