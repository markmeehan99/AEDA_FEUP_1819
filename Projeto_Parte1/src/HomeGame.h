#ifndef HOMEGAME_H_
#define HOMEGAME_H_

#include "Game.h"
#include "Date.h"
#include <string>
#include "Empresa.h"
#include "BST.h"
using namespace std;

class HomeGame: public Game {
private:

public:
	/**
	 * @brief Cria um HomeGame vazio
	 */
	HomeGame();
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
	HomeGame(int age_limit, string name, double price, int rating,
			string platform, string genre, Empresa *publisher);
	/**
	 * @brief Carregar um jogo atraves de um ficheiro.
	 * @param file Nome do ficheiro  a ser carregado sem o .txt.
	 */
	void importGameInfo(string file, BST<Empresa*> empresas);
};

#endif /* HOMEGAME_H_ */
