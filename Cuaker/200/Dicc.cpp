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
#include <list>
using namespace std;

DiccionarioCuacs::DiccionarioCuacs(){

	this->T = TablaHash();
}

void DiccionarioCuacs::insertar (Cuac nuevo) {
	
	this->T.insertar(nuevo);
}
void DiccionarioCuacs::last(int N){

}
void DiccionarioCuacs::follow(string nombre){

	this->T.consultar(nombre);
}
void DiccionarioCuacs::date(Fecha f1, Fecha f2){

}
