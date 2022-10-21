/*
 * Arbol.cpp
 *
 *  Created on: Dec 4, 2018
 *      Author: serms1999
 */

#include "Arbol.h"
#include <algorithm>

void Arbol::aux_insertar(Nodo* &nodo, Cuac* ref) {

	if (nodo == NULL){

			nodo = new Nodo;
			nodo->cuac = ref;
	}
	else{

		if (nodo->cuac->es_anterior2(ref)) {		//Inserción subarbol derecho

			aux_insertar(nodo->der, ref);

			if (altura(nodo->der) - altura(nodo->izq) > 1) {

				if (ref->es_anterior2(nodo->der->cuac)) {

					RDD(nodo);		//Caso DI
				}
				else {

					RSD(nodo);		//Caso DD
				}
			}
			else {

				nodo->alt = 1 + max(altura(nodo->izq), altura(nodo->der));
			}
		}

		else if (ref->es_anterior2(nodo->cuac)){		//Inserción subarbol izquierdo

			aux_insertar(nodo->izq, ref);

			if (altura(nodo->izq)- altura(nodo->der) > 1){

				if(ref->es_anterior2(nodo->izq->cuac)){

					RSI(nodo);		//Caso II
				}
				else{

					RDI(nodo);		//Caso ID
				}
			}
			else{

				nodo->alt = 1 + max(altura(nodo->izq), altura(nodo->der));
			}
		}
	}
}

void Arbol::aux_date(Nodo* nodo, int &cont, Fecha f1, Fecha f2)
{

	if (nodo->der != NULL && f2 < nodo->cuac->getFecha())
	{
		aux_date(nodo->der, cont, f1, f2);
	}
	else if (nodo->izq != NULL)
	{
		aux_date(nodo->izq, cont, f1, f2);
	}
	if (!(nodo->cuac->getFecha() < f1 || f2 < nodo->cuac->getFecha()))
	{

		cont++;
		cout << cont << ". ";
		nodo->cuac->escribir();
		if (nodo->der != NULL && !(nodo->cuac->getFecha() < f1))
		{
			aux_date(nodo->der, cont, f1, f2);
		}
	}
}
void Arbol::aux_last(Nodo* nodo, int N, int &cont) {

	if (nodo->izq != NULL && cont < N) aux_last(nodo->izq, N, cont);
	if (cont < N) {
		cont++;
		cout << cont << ". ";
		nodo->cuac->escribir();
	}
	if (nodo->der != NULL && cont < N) aux_last(nodo->der, N, cont);
}

Arbol::Arbol() {

	raiz = NULL;
}

int Arbol::altura(Nodo* n){

	if (n == NULL) return -1;
	else return n->alt;
}

void Arbol::insertar(Cuac* ref){

	aux_insertar(raiz, ref);
}

void Arbol::RSI(Nodo* &B){

	Nodo* A = B->izq;
	B->izq = A->der;
	A->der = B;
	B->alt = 1 + max(altura(B->izq), altura(B->der));
	A->alt = 1 + max(altura(B), altura(A->izq));
	B = A;
}

void Arbol::RSD(Nodo* &A){

	Nodo* B = A->der;
	A->der = B->izq;
	B->izq = A;
	A->alt = 1 + max(altura(A->izq), altura(A->der));
	B->alt = 1 + max(altura(A), altura(B->der));
	A = B;
}

void Arbol::RDD(Nodo* &A){

	RSI(A->der);
	RSD(A);
}

void Arbol::RDI(Nodo* &A){

	RSD(A->izq);
	RSI(A);
}

void Arbol::last(int N){

	int contlast = 0;
	if (raiz != NULL){

		aux_last(raiz, N, contlast);
	}
	cout << "Total: " << contlast << " cuac" << endl;

};

void Arbol::date(Fecha f1, Fecha f2){

	int contdate = 0;
	if (raiz != NULL)
	{
		aux_date(raiz, contdate, f1, f2);
	}
	cout << "Total: " << contdate << " cuac" << endl;
};

