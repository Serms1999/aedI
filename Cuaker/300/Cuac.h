/*
 * Cuac.h
 *
 *  Created on: Nov 9, 2018
 *      Author: serms1999
 *  Modified on: Nov 16, 2018
 *      Author: amm1999
 */

#ifndef CUAC_H_
#define CUAC_H_
#include <iostream>
#include "Fecha.h"
using namespace std;

class Cuac {
private:
	Fecha fecha;
	string usuario;
	string texto;
public:
	bool leer_mcuac();
	bool leer_pcuac();
	void escribir();
	bool es_anterior(Cuac otro);
	bool es_anterior2(Cuac* otro);
	bool operator< (Cuac otro) { return es_anterior(otro); }
	bool operator!= (Cuac otro) { return !(fecha == otro.fecha && usuario == otro.usuario && texto == otro.texto); }
	Fecha getFecha() { return fecha; }
	string getUsuario() { return usuario; }
	string getTexto() { return texto; }
};

#endif /* CUAC_H_ */
