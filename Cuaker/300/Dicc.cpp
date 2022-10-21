/*
 * Dicc.cpp
 *
 *  Created on: Dec 3, 2018
 *      Author: serms1999
 */

#include <iostream>
#include "Cuac.h"
#include "Dicc.h"
#include "TablaHash.h"
#include "Arbol.h"
#include <list>

using namespace std;

void DiccionarioCuacs::insertar (Cuac nuevo) {
	
	Cuac* ref = T.insertar(nuevo);
	a.insertar(ref);
}
void DiccionarioCuacs::last(int N){

	a.last(N);
}
void DiccionarioCuacs::follow(string nombre){

	T.consultar(nombre);
}
void DiccionarioCuacs::date(Fecha f1, Fecha f2){

	a.date(f1, f2);
}
