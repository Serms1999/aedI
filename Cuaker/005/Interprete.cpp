/*
 * Interprete.cpp
 *
 *  Created on: Oct 30, 2018
 *      Author: serms1999
 */

#include <iostream>
#include "Interprete.h"
#include "Cuac.h"
#include "Lista.h"
#include "Fecha.h"
using namespace std;

void procesar_mcuac(string comando,Cuac &cuac, int &num){

	cuac.leer_mcuac();
	cout << ++num << " cuac" << endl;
}

void procesar_pcuac(string comando,Cuac &cuac, int &num){

	cuac.leer_pcuac();
	cout << ++num << " cuac" << endl;
}

void procesar_last(string comando, Cuac ultcuac){

	int N;
	cin >> N;
	cout << comando << " " << N << endl;
	cout << "1. ";
	ultcuac.escribir();
	cout << "Total: 1 cuac" << endl;
}

void procesar_follow(string comando, Cuac ultcuac){

	string nombre;
	cin >> nombre;
	cout << comando << " " << nombre << endl;
	cout << "1. ";
	ultcuac.escribir();
	cout << "Total: 1 cuac" << endl;
}

void procesar_date(string comando, Cuac ultcuac){

	Fecha fmin, fmax;
	fmin.leer();
	fmax.leer();

	cout << comando << " ";
	fmin.escribir();
	cout << " ";
	fmax.escribir();
	cout <<  endl;

	cout << "1. ";
	ultcuac.escribir();
	cout << "Total: 1 cuac" << endl;
}

void procesar_tag(string comando, Cuac ultcuac){

	string nombre;
	cin >> nombre;
	cout << comando << " " << nombre << endl;
	cout << "1. ";
	ultcuac.escribir();
	cout << "Total: 1 cuac" << endl;
}

void Interprete(string comando){

	int num = 0;

	nodoCuac *p = new nodoCuac();

	while (cin >> comando && comando != "exit"){


		if (comando == "mcuac" || comando == "pcuac"){

			Cuac cuac;

			if (comando == "mcuac") procesar_mcuac(comando, cuac, num);
			else if (comando == "pcuac") procesar_pcuac(comando, cuac, num);

			p->insertar(cuac);
		}
		else if (comando == "last") procesar_last(comando, p->getUltCuac());
		else if (comando == "follow") procesar_follow(comando, p->getUltCuac());
		else if (comando == "date") procesar_date(comando, p->getUltCuac());
		else if (comando == "tag") procesar_tag(comando, p->getUltCuac());

	}
}
