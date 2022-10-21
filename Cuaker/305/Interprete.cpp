/*
 * Interprete.cpp
 *
 *  Created on: Dec 3, 2018
 *      Author: serms1999
 */

#include <iostream>
#include "Interprete.h"
#include "Cuac.h"
#include "Fecha.h"
#include "Dicc.h"
using namespace std;

void procesar_mcuac(DiccionarioCuacs &dic){

	Cuac nuevo;
	nuevo.leer_mcuac();
	dic.insertar(nuevo);
}

void procesar_pcuac(DiccionarioCuacs &dic){

	Cuac nuevo;
	nuevo.leer_pcuac();
	dic.insertar(nuevo);
}

void procesar_last(DiccionarioCuacs &dic,string comando){

	int N;
	cin >> N;
	cout << comando << " " << N << endl;
	dic.last(N);

}

void procesar_follow(DiccionarioCuacs &dic,string comando){

	string nombre;
	cin >> nombre;
	cout << comando << " " << nombre << endl;
	dic.follow(nombre);
}

void procesar_date(DiccionarioCuacs &dic, string comando){

	Fecha fmin, fmax;
	fmin.leer();
	fmax.leer();

    cout << comando << " ";
	fmin.escribir();
	cout << " ";
	fmax.escribir();
	cout <<  endl;
	dic.date(fmin,fmax);
}

void procesar_tag(DiccionarioCuacs &dic, string comando){

	string etiqueta;
	cin >> etiqueta;
	cout << comando << " " << etiqueta << endl;
	dic.tag(etiqueta);
}

void Interprete(DiccionarioCuacs dic,string comando){

	while (cin >> comando && comando != "exit"){

		if (comando == "mcuac" || comando == "pcuac"){

			if (comando == "mcuac") procesar_mcuac(dic);
			else if (comando == "pcuac") procesar_pcuac(dic);
		}

		else if (comando == "last") procesar_last(dic, comando);
		else if (comando == "follow") procesar_follow(dic, comando);
		else if (comando == "date") procesar_date(dic, comando);
		else if (comando == "tag") procesar_tag(dic, comando);
	}
}
