#ifndef CARD_H_
#define CARD_H_

#include "Date.h"
#include <string>

using namespace std;

class Card {
	int id;
	string name;
	double credit;
	Date expDate;
public:
	/**
	 * Cria um cartao novo.
	 * @param id Numero de ID do cartao.
	 * @param name	Nome do cartao.
	 * @param credit Credito disponivel.
	 * @param expDate Data de validade.
	 */
	Card(int id, string name, double credit, Date expDate);
	/**
	 * @brief Retorna a data de valdiade do cartao.
	 * @return Data de validade do cartao.
	 */
	Date getExpDate() const;
	/**
	 * @brief Retorna o credito dispoinvel do cartao.
	 * @return Credito do cartao.
	 */
	double getCredit() const;
	/**
	 * @brief Retorna o ID do cartao.
	 * @return ID do cartao.
	 */
	int getID() const;
	/**
	 * @brief Retorna o nome do cartao.
	 * @return Nome do cartao.
	 */
	string getName() const;
	/**
	 * @brief Remove o credito amount do ao cartao se possivel.
	 * @param amount Credito a remover.
	 */
	void removeCredit(double amount);
	/**
	 * @brief Adiciona credito amount ao cartao se possivel.
	 * @param amount Credito a adicionar.
	 */
	void addCredit(double amount);
	/**
	 * @brief Overload do operador << para fazer display de um cartao.
	 * @param sp
	 * @param card
	 * @return
	 */
	friend ostream& operator<<(ostream& sp, Card& card);
};

class InvalidAmount {
public:
	double amount;
	InvalidAmount(double amount) {
		this->amount = amount;
	}
	double getAmount() {
		return amount;
	}
};

class InvalidCard {
private:
	string InvCard;
public:
	InvalidCard(string card) {
		this->InvCard = card;
	}
	string getMessage() {
		return "O cartao" + InvCard + " nao existe!";
	}
};

#endif /* CARD_H_ */
