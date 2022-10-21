/*
 * TablaHash.cpp
 *
 *  Created on: Dec 3, 2018
 *      Author: serms1999
 */

#include "TablaHash.h"
#include <iostream>
using namespace std;
const int primo = 53;

int funcionDisp(string nombre){

	int i = 0;
	int pos = 0;
	while (i < nombre.length()){

		unsigned char c = nombre[i];
		pos+=c*primo^i;
		i++;
	}
	return pos % TAM;
}

TablaHash::TablaHash(){

	M = TAM;
	nElem = 0;
}

Cuac* TablaHash::insertar(Cuac nuevo){

	list<Cuac>* lista = &T[funcionDisp(nuevo.getUsuario())];
	list<Cuac>::iterator itLista = lista->begin();
	while (itLista!=lista->end() && *itLista<nuevo){
		itLista++;
	}

	if (itLista==lista->end() || *itLista!=nuevo){

		nElem++;
		lista->insert(itLista, nuevo);
	}
	cout << nElem << " cuac" << endl;
	itLista--;
	return &*itLista;
}

void TablaHash::consultar(string nombre){

	list<Cuac> lista = T[funcionDisp(nombre)];
	list<Cuac>::iterator itLista;
	int contador = 0;
	Cuac actual;
	for (itLista = lista.begin(); itLista != lista.end(); itLista++){

		actual = *itLista;
		if (actual.getUsuario() == nombre){

			++contador;
			cout << contador << ". ";
			actual.escribir();
		}
	}
	cout << "Total: " << contador << " cuac" << endl;
}

int TablaHash::numElem(){

	return this->nElem;
}

