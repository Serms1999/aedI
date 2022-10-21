/*
 * Fecha.h
 *
 *  Created on: Nov 9, 2018
 *      Author: serms1999
 */

#ifndef FECHA_H_
#define FECHA_H_

class Fecha {
private:
	int dia, mes, ano;
	int hora, minuto, segundo;
	long long convierte_a_segundos();
public:
	Fecha();
	bool leer();
	void escribir();
	bool es_menor(Fecha otra);
	bool es_igual(Fecha otra);
	bool operator< (Fecha otra) { return es_menor(otra); }
	bool operator== (Fecha otra) { return es_igual(otra); }
	bool operator<= (Fecha otra) {return es_menor(otra) || es_igual(otra);}
};

#endif /* FECHA_H_ */
