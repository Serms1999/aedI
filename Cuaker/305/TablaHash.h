/*
 * TablaHash.h
 *
 *  Created on: Dec 3, 2018
 *      Author: serms1999
 */

#ifndef TABLAHASH_H_
#define TABLAHASH_H_
#include <list>
#include "Cuac.h"
using namespace std;
const int TAM = 12721;

class TablaHash{

private:

	list<Cuac> T[TAM];
	int M;
	int nElem;
public:

	TablaHash();
	Cuac* insertar(Cuac nuevo);
	void consultar(string nombre);
	int numElem();
};

#endif /* TABLAHASH_H_ */
