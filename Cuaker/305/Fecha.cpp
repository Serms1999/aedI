/*
 * Fecha.cpp
 *
 *  Created on: Oct 30, 2018
 *      Author: serms1999
 */

#include <iostream>
#include "Fecha.h"
using namespace std;

Fecha::Fecha()
{
	dia = mes = ano = hora = minuto = segundo = 0;
}

bool Fecha::leer()
{
	char c;
	return (bool)(cin >> dia >> c >> mes >> c >> ano >> hora >> c >> minuto >> c >> segundo);
}

void Fecha::escribir()
{
	cout << dia << "/" << mes << "/" << ano << " ";
	if (hora < 10) cout << "0";
	cout << hora << ":";
	if (minuto < 10) cout << "0";
	cout << minuto << ":";
	if (segundo < 10) cout << "0";
	cout << segundo;
}

long long Fecha::convierte_a_segundos()
{
	return segundo + 60 * (minuto + 60 * (hora + 24 * (dia + 31 * ((long long)mes + 12 * ano))));
}

bool Fecha::es_menor(Fecha otra)
{
	return convierte_a_segundos() < otra.convierte_a_segundos();
}

bool Fecha::es_igual(Fecha otra)
{
	return convierte_a_segundos() == otra.convierte_a_segundos();
}
