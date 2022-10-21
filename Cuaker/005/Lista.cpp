/*
 * Lista.cpp
 *
 *  Created on: Nov 6, 2018
 *      Author: serms1999
 */

#include "Cuac.h"
#include "Lista.h"

void nodoCuac::insertar(Cuac &cuac){

	nodoCuac *nuevo = new nodoCuac();
	nuevo->cuac.asignar_cuac(cuac);
	nuevo->sig = this->sig;
	this->sig = nuevo;
}
Cuac nodoCuac::getUltCuac(){

	Cuac ult;
	ult.asignar_cuac(this->sig->cuac);
	return ult;
}
