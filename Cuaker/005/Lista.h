/*
 * Lista.h
 *
 *  Created on: Nov 9, 2018
 *      Author: serms1999
 */

#ifndef LISTA_H_
#define LISTA_H_

#include "Cuac.h"

class nodoCuac{

private:

	Cuac cuac;
	nodoCuac *sig;
public:
	void insertar(Cuac &cuac);
	Cuac getUltCuac();
};

#endif /* LISTA_H_ */
