/*
 * Listaetiquetas.cpp
 *
 *  Created on: Dec 28, 2018
 *      Author: serms1999
 */

#include "Listaetiquetas.h"
#include <iostream>
using namespace std;
const int primo2 = 149;

int funcionDisp2(string etiqueta) {

	int i = 0;
	int pos = 0;
	while (i < etiqueta.length()) {

		unsigned char c = etiqueta[i];
		pos += c * primo2^i;
		i++;
	}
	return pos % tamano;
}

ListaEtiquetas::ListaEtiquetas() {

	M = tamano;
}

void ListaEtiquetas::insertar(Cuac* nuevo, string etiqueta) {

	list<Cuac*>* lista = &T[funcionDisp2(etiqueta)];
	list<Cuac*>::iterator itLista = lista->begin();
	while (itLista != lista->end() && (*itLista)->es_anterior2(nuevo)) 
	{
		itLista++;
	}

	if (itLista == lista->end() || !((*itLista)->es_igual(nuevo))) 
	{

		lista->insert(itLista, nuevo);
	}
}

void ListaEtiquetas::consultar(string etiqueta) {

	list<Cuac*> lista2 = T[funcionDisp2(etiqueta)];
	list<Cuac*>::iterator itLista;
	int contador = 0;
	for (itLista = lista2.begin(); itLista != lista2.end(); itLista++) 
	{
		if ((*itLista)->getTexto().find(etiqueta) != string::npos)
		{
		++contador;
		cout << contador << ". ";
		(*itLista)->escribir();
		}
	}
	cout << "Total: " << contador << " cuac" << endl;
}
