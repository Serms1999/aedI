/*
 * 200.cpp
 *
 *  Created on: Dec 3, 2018
 *      Author: serms1999
 */


#include "Interprete.h"
#include "Dicc.h"
using namespace std;

DiccionarioCuacs dic = DiccionarioCuacs();

int main(void){

	string comando;
	Interprete(dic,comando);
	return 0;
}

