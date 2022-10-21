/*
 * Nodo.h
 *
 *  Created on: Dec 4, 2018
 *      Author: serms1999
 */

#ifndef NODO_H_
#define NODO_H_
#include "Cuac.h"

class Nodo {
	friend class Arbol;
private:
	Cuac* cuac;
	int alt;
	Nodo* izq;
	Nodo* der;
public:
	Nodo();
	~Nodo(){
		delete izq;
		delete der;
	}
};

#endif /* NODO_H_ */
