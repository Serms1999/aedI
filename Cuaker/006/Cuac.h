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

class Cuac{

private:

	Fecha fecha;
	string usuario;
	string texto;
	string tipo;
public:

	bool leer_mcuac();
	bool leer_pcuac();
	void escribir();
	bool es_anterior(Cuac &otro);
	void asignar_cuac(Cuac &otro);
	string getUsuario(){
	return usuario;}
	Fecha getFecha(){
	return fecha;}
};

#endif /* CUAC_H_ */
