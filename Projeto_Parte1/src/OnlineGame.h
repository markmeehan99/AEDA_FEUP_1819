#ifndef ONLINEGAME_H_
#define ONLINEGAME_H_

#include "Game.h"
#include <string>

using namespace std;

class OnlineGame: public Game {
private:
	bool isMonthly;
	double subscriptionCost;
public:
	/**
	 * @brief Cria um jogo vazio
	 */
	OnlineGame();
	/**
	 * @brief Cria um OnlineGame com os parametros dados
	 * @param age_limit Idade minima para poder jogar o jogo
	 * @param name Nome do jogo
	 * @param price Preco do jogo
	 * @param rating Classificacao do jogo
	 * @param platform Plataforma
	 * @param genre Categoria
	 * @param publisher Publicador
	 * @param subscriptionCost Custo da subscricao
	 * @param isMonthly	True se o jogo for pago mensalmente ou false se for pago consoante o numero de horas jogadas
	 */
	OnlineGame(int age_limit, string name, double price, int rating,
			string platform, string genre, string publisher,
			double subscriptionCost, bool isMonthly);
	/**
	 * @brief Retorna o metodo de pagamento(True se o jogo for pago mensalmente ou false se for pago consoante o numero de horas jogadas)
	 * @return Metodo de pagamento
	 */
	bool getPaymentMethod() const;
	/**
	 * @brief Retorna o custo da subscricao
	 * @return Custo da subscricao
	 */
	double getSubscriptionCost() const;

	/**
	 * @brief Guarda a informacao de uma sessao de jogo nun ficheiro .txt com o mesmo nome do Gamed
	 * @param type	Tipo de sessão tem de ser um char 'U' obrigatoriamente.
	 * @param date	Data da sessao de jogo.
	 */
	void exportGameInfo(char type, Date date, int playTime); //overload for Updates

	/**
	 * @brief Guarda a informacao de uma sessao de jogo nunm ficheiro .txt com o mesmo nome do Game
	 * @param type	Tipo de sessão tem de ser um char 'U' obrigatoriamente.
	 * @param date	Data da sessao de jogo.
	 */
	void exportGameInfo(char type, Date date);
	/**
	 * @brief Carregar um jogo atraves de um ficheiro.
	 * @param file Nome do ficheiro  a ser carregado sem o .txt.
	 */
	void importGameInfo(string file);
};

#endif /* ONLINEGAME_H_ */
