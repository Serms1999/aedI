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
#include <list>
using namespace std;
class DiccionarioCuacs {
	private:
		TablaHash T;
	public:
		DiccionarioCuacs();
		void insertar (Cuac nuevo);
		void follow (string nombre);
		void last (int N);
		void date (Fecha f1, Fecha f2);
		int numElem ()
			{return T.numElem();}
};

#endif
