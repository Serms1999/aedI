/*
 * Arbol.h
 *
 *  Created on: Dec 4, 2018
 *      Author: serms1999
 */

#ifndef ARBOL_H_
#define ARBOL_H_
#include "Nodo.h"

class Arbol {
	friend class DiccionarioCuacs;
private:
	Nodo* raiz;
	void RSI (Nodo* &B);
	void RSD (Nodo* &A);
	void RDI (Nodo* &A);
	void RDD (Nodo* &A);
	void aux_last(Nodo* nodo, int N, int &cont);
	void aux_insertar(Nodo* &nodo, Cuac* ref);
	void aux_date(Nodo* nodo, int &cont, Fecha f1, Fecha f2);
public:
	Arbol();
	~Arbol(){
		delete raiz;
	}
	void insertar (Cuac *ref);
	void last (int N);
	void date (Fecha f1, Fecha f2);
	int altura (Nodo* n);
};

#endif /* ARBOL_H_ */
