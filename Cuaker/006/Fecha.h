/*
 * Fecha.h
 *
 *  Created on: Nov 9, 2018
 *      Author: serms1999
 */

#ifndef FECHA_H_
#define FECHA_H_

class Fecha{

private:
	int dia, mes, ano;
	int hora, minuto, segundo;

public:
	Fecha();
	bool leer();
	void escribir();
	bool es_menor(Fecha &otra);
	bool es_igual(Fecha &otra);
	void asigna_fecha(Fecha &otra);
};

#endif /* FECHA_H_ */
