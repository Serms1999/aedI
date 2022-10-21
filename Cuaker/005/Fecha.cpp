/*
 * Fecha.cpp
 *
 *  Created on: Oct 30, 2018
 *      Author: serms1999
 */

#include <iostream>
#include "Fecha.h"
using namespace std;

Fecha:: Fecha(){

	dia = 0;
	mes = 0;
	ano = 0;
	hora = 0;
	minuto = 0;
	segundo = 0;
};

bool Fecha:: leer(){

	char c;

	cin >> this->dia;
	cin >> c;
	cin >> this->mes;
	cin >> c;
	cin >> this->ano;

	cin >> this->hora;
	cin >> c;
	cin >> this->minuto;
	cin >> c;
	cin >> this->segundo;

	return true;

};

void Fecha::escribir(){

	cout << dia << "/" << mes << "/" << ano << " ";
	if (hora < 10){

		cout << "0" << hora << ":";
	}
	else{
		cout << hora << ":";
	}
	if (minuto < 10){

		cout << "0" << minuto << ":";
	}
	else{
		cout << minuto << ":";
	}
	if (segundo < 10){

		cout << "0" << segundo;
	}
	else{
		cout << segundo;
	}
};

bool Fecha::es_menor(Fecha &otra){

	if (this->ano < otra.ano) return true;
	else{

		if (this->ano > otra.ano) return false;
		else{

			if (this->mes < otra.mes) return true;
			else{

				if (this->mes > otra.mes) return false;
				else{

				if (this->dia < otra.dia) return true;
					else{

						if (this->dia > otra.dia) return false;
						else{

							if (this->hora < otra.hora) return true;
							else{

								if (this->hora > otra.hora) return false;
								else{

									if (this->minuto < otra.minuto) return true;
									else{

										if (this->minuto > otra.minuto) return false;
										else return this->segundo < otra.segundo;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

bool Fecha::es_igual(Fecha &otra){

	return ((this->ano == otra.ano)&&(this->mes == otra.mes)&&(this->dia == otra.dia)&&
			(this->hora == otra.hora)&&(this->minuto == otra.minuto)&&(this->segundo == otra.segundo));
}

void Fecha::asigna_fecha(Fecha &otra){

	this->dia = otra.dia;
	this->mes = otra.mes;
	this->ano = otra.ano;
	this->hora = otra.hora;
	this->minuto = otra.minuto;
	this->segundo = otra.segundo;
};
