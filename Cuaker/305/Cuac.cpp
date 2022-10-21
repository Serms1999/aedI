/*
 * Cuac.cpp
 *
 *  Created on: Oct 30, 2018
 *      Author: serms1999
 */

#include <iostream>
#include <string>
#include "Cuac.h"
using namespace std;

const int NUM_PCUACS = 30;

string cadenas_pcuac[NUM_PCUACS] = {
"Afirmativo.",
"Negativo.",
"Estoy de viaje en el extranjero.",
"Muchas gracias a todos mis seguidores por vuestro apoyo.",
"Enhorabuena, campeones!",
"Ver las novedades en mi pagina web.",
"Estad atentos a la gran exclusiva del siglo.",
"La inteligencia me persigue pero yo soy mas rapido.",
"Si no puedes convencerlos, confundelos.",
"La politica es el arte de crear problemas.",
"Donde estan las llaves, matarile, rile, rile...",
"Si no te gustan mis principios, puedo cambiarlos por otros.",
"Un dia lei que fumar era malo y deje de fumar.",
"Yo si se lo que es trabajar duro, de verdad, porque lo he visto por ahi.",
"Hay que trabajar ocho horas y dormir ocho horas, pero no las mismas.",
"Mi vida no es tan glamurosa como mi pagina web aparenta.",
"Todo tiempo pasado fue anterior.",
"El azucar no engorda... engorda el que se la toma.",
"Solo los genios somos modestos.",
"Nadie sabe escribir tambien como yo.",
"Si le molesta el mas alla, pongase mas aca.",
"Me gustaria ser valiente. Mi dentista asegura que no lo soy.",
"Si el dinero pudiera hablar, me diria adios.",
"Hoy me ha pasado una cosa tan increible que es mentira.",
"Si no tienes nada que hacer, por favor no lo hagas en clase.",
"Que nadie se vanaglorie de su justa y digna raza, que pudo ser un melon y salio una calabaza.",
"Me despido hasta la proxima. Buen viaje!",
"Cualquiera se puede equivocar, inclusivo yo.",
"Estoy en Egipto. Nunca habia visto las piramides tan solas.",
"El que quiera saber mas, que se vaya a Salamanca."
};

string pcuac_a_texto(int num)
{
	return cadenas_pcuac[num - 1];
}

int pcuac_a_numero(string cadena)
{
	for (int i = 1; i <= NUM_PCUACS; i++)
		if (cadena == cadenas_pcuac[i - 1])
			return i;
	return 0;   // 0 indica que el mensaje no se encuentra
}


bool Cuac::leer_mcuac()
{
	if (!(cin >> usuario)) return false;
	if (!fecha.leer()) return false;
	cin.ignore();
	getline(cin, texto);
	return true;
}

bool Cuac::leer_pcuac()
{
	if (!(cin >> usuario)) return false;
	if (!fecha.leer()) return false;
	int p;
	cin >> p;
	if (p < 1 || p>30) return false;
	texto = pcuac_a_texto(p);
	return true;
}

void Cuac::escribir()
{
	cout << usuario << " ";
	fecha.escribir();
	cout << endl;
	cout << "   " << texto << endl;
}

bool Cuac::es_anterior(Cuac otro)
{
	if (fecha == otro.fecha) {

		if (texto == otro.texto){
			return usuario < otro.usuario;}
		else{
			return texto < otro.texto;}
	}
	else
		return otro.fecha < fecha;
}
bool Cuac::es_anterior2(Cuac* otro)
{
	if (fecha == otro->fecha) {

		if (texto == otro->texto){
			return usuario < otro->usuario;}
		else{
			return texto < otro->texto;}
	}
	else
		return otro->fecha < fecha;
}

bool Cuac::es_igual(Cuac* otro)
{
	return (this->getFecha() == otro->getFecha() && this->getTexto() == otro->getTexto() && this->getUsuario() == otro->getUsuario());
}
