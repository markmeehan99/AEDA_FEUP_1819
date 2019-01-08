#ifndef DATE_H_
#define DATE_H_

#include <string>

using namespace std;

class Date {
	int day, month, year;

public:
	/**
	 * @brief Cria uma data vazia.
	 */
	Date();
	/**
	 * @brief Cria uma data com os parametros dados em ints separadas.
	 * @param day Dia da data.
	 * @param month Mes da data.
	 * @param year Ano da data.
	 */
	Date(int day, int month, int year);
	/**
	 * @brief Cria uma data com a string dada.
	 * @param date String com a data no formato dd/mm/aa.
	 */
	Date(string date);
	/**
	 * @brief Retorna a data numa string de formato dd/mm/aa.
	 * @return Data em string.
	 */
	string getDate() const;
	/**
	 * @brief Altera a data para os parametros fornecidos em ints.
	 * @param day Dia da data.
	 * @param month Mes da data.
	 * @param year Ano da data.
	 */
	void setDate(int day, int month, int year);
	/**
	 * @brief Altera a data para os parametros fornecidos numa string.
	 * @param day Dia da data.
	 * @param month Mes da data.
	 * @param year Ano da data.
	 */
	void setDate(string date);
	/**
	 * @brief Operador para comparar duas datas.
	 * @param d1
	 * @return True se a data for mais avancada no tempo do que a de d1.
	 * @return False se a data for menos avancada no tempo do que a de d1.
	 */

	int getDay();

	int getMonth();

	int getYear();


	//void viewDate();

	string getDateIncremented() const;

	bool operator>(const Date &d1);

	/**
	 * @brief Operador para igualar duas datas.
	 * @param d
	 */
	void operator=(Date d);

	//ostream& operator<< (ostream& stream);
};

class InvalidDate: public exception {
private:
	int day;
	int month;
	int year;
	string err = "";
public:
	InvalidDate(int day, int month, int year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
	string getInvalidDate() {
		err += to_string(day);
		err += "/";
		err += to_string(month);
		err += "/";
		err += to_string(year);
		err += "/";

		return err;
	}
};


#endif /* DATE_H_ */
