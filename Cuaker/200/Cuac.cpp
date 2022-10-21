/*
 * Cuac.cpp
 *
 *  Created on: Oct 30, 2018
 *      Author: serms1999
 */

#include <iostream>
#include "Cuac.h"
using namespace std;

const int NUM_MENSAJES = 30;

string getPcuac(int c){
	string send = " ";
	string mensajes[NUM_MENSAJES] = {
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

	if ( (c>0) && (c <=30)){
		send = mensajes[c-1];

	}
	else{
		send = "";
	}
	return send;
}


bool Cuac::leer_mcuac(){

	this->tipo = "pcuac";

	cin >> usuario;

	fecha.leer();
	cin.ignore();
	getline(cin, texto);

	return true;
}

bool Cuac::leer_pcuac(){

	this->tipo = "pcuac";

	cin >> usuario;
	cin.ignore();

	fecha.leer();

	int n;
	cin >> n;
	this->texto = getPcuac(n);

	return true;
}

void Cuac::escribir(){

	cout << this->usuario << " ";
	this->fecha.escribir();
	cout << endl;

	cout << "   " << this->texto << endl;
}

bool Cuac::es_anterior(Cuac &otro){
	if (this->fecha.es_menor(otro.fecha)) return true;
	else{
		if(this->fecha.es_igual(otro.fecha)){
			if(this->texto < otro.texto){
			return true;   
			}else{
				if(this->texto == otro.texto){
					return this->usuario < otro.usuario;
				}else{
					return false;
				}
			  
			}
		}else{
		return false;
	}
            
    }
}

void Cuac::asignar_cuac(Cuac &otro){

	this->fecha = otro.fecha;
	this->texto = otro.texto;
	this->tipo = otro.tipo;
	this->usuario = otro.usuario;
}

bool Cuac::operator!= (Cuac &otro){

	return !((this->fecha.es_igual(otro.fecha)) && (this->texto == otro.texto) &&
			(this->usuario == otro.usuario) && (this->tipo == otro.tipo));
}

bool Cuac::operator< (Cuac &otro){

	return this->es_anterior(otro);
}

Fecha Cuac::getFecha(){

	Fecha f;
	f.asigna_fecha(this->fecha);
	return f;
}

string Cuac::getTexto(){

	return this->usuario;
}

string Cuac::getUsuario(){

	return this->usuario;
}
