/*
 * 003.cpp
 *
 *  Created on: Oct 23, 2018
 *      Author: serms1999
 */

#include <iostream>
using namespace std;

const int NUM_MENSAJES = 30;

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

class Fecha {
	private:
		int dia, mes, ano;
		int hora, minuto, segundo;
	public:
		Fecha();
		bool leer();
		void escribir();
		bool es_menor(Fecha &otra);
		bool es_igual(Fecha &otra);
		void asigna_fecha(Fecha &otra);
};

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


int main(void){

	int N;
	cin >> N;

	Fecha factual;
	Fecha fanterior;

	cin.ignore();

	fanterior.leer();

	for(int i = 1; i < N; i++){

		factual.leer();

		if (factual.es_menor(fanterior)){

			factual.escribir(); cout << " ES ANTERIOR A ";fanterior.escribir(); cout << "\n";
		}
		else{

			if (factual.es_igual(fanterior)){

				factual.escribir(); cout << " ES IGUAL A "; fanterior.escribir(); cout << "\n";
			}
			else{

				factual.escribir(); cout << " ES POSTERIOR A "; fanterior.escribir(); cout << "\n";
			}
		}

		fanterior.asigna_fecha(factual);
	}
}
