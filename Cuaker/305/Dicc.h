/*
 * Dicc.h
 *
 *  Created on: Dec 3, 2018
 *      Author: serms1999
 */

#ifndef DICC_H_
#define DICC_H_

#include <iostream>
#include "Cuac.h"
#include "TablaHash.h"
#include "Arbol.h"
#include "Listaetiquetas.h"
#include <list>
using namespace std;
class DiccionarioCuacs {
	private:
		TablaHash T;
		Arbol a;
		ListaEtiquetas l;
	public:
		void insertar (Cuac nuevo);
		void follow (string nombre);
		void last (int N);
		void date (Fecha f1, Fecha f2);
		void tag(string etiqueta);
		int numElem ()
			{return T.numElem();}
};

#endif
