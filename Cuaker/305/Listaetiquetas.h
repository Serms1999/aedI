/*
 * Listaetiquetas.h
 *
 *  Created on: Dec 28, 2018
 *      Author: serms1999
 */

#ifndef LISTAETIQUETAS_H_
#define LISTAETIQUETAS_H_
#include <list>
#include "Cuac.h"
using namespace std;
const int tamano = 36721;

class ListaEtiquetas {

private:

	list<Cuac*> T[tamano];
	int M;
public:

	ListaEtiquetas();
	void insertar(Cuac* nuevo, string etiqueta);
	void consultar(string etiqueta);
};

#endif /* LISTAETIQUETAS_H_ */

