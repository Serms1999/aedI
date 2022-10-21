/*
 * Dicc.h
 *
 *  Created on: Nov 13, 2018
 *      Author: amm1999
 */

#ifndef DICC_H_
#define DICC_H_

#include <iostream>
#include "Cuac.h"
#include <list>
using namespace std;
class DiccionarioCuacs {
	private:
		list<Cuac> lista;
		int contador;
	public:
		DiccionarioCuacs ();
		void insertar (Cuac nuevo);
		void last (int N);
		void follow (string nombre);
		void date (Fecha f1, Fecha f2);
		int numElem ()
			{return contador;}
};

#endif
