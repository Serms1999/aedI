/*
 * 004.cpp
 *
 *  Created on: Oct 23, 2018
 *      Author: serms1999
 */

#include <iostream>
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

	if ( (c > 0) && (c <= 30)){
		send = mensajes[c - 1];

	}
	else{
		send = "";
	}
	return send;
}

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

	string fecha;

	getline(cin, fecha);

	int barra = fecha.find("/");
	dia = atoi(fecha.substr(0, barra).c_str());
	fecha.erase(0, barra+1);

	barra = fecha.find("/");
	mes = atoi(fecha.substr(0, barra).c_str());
	fecha.erase(0, barra+1);

	barra = fecha.find(" ");
	ano = atoi(fecha.substr(0, barra).c_str());
	fecha.erase(0, barra + 1);

	barra = fecha.find(":");
	hora = atoi(fecha.substr(0, barra).c_str());
	fecha.erase(0, barra+1);

	barra = fecha.find(":");
	minuto = atoi(fecha.substr(0, barra).c_str());
	fecha.erase(0, barra+1);

	segundo = atoi(fecha.c_str());

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

class Cuac{

	private:

		Fecha fecha;
		string usuario;
		string texto;
	public:

		bool leer_mcuac();
		bool leer_pcuac();
		void escribir(string comando);
		bool es_anterior(Cuac &otro);
};

bool Cuac::leer_mcuac(){

	cin >> usuario;
	cin.ignore();

	fecha.leer();

	getline(cin, texto);

	return true;
}

bool Cuac::leer_pcuac(){

	cin >> usuario;
	cin.ignore();

	fecha.leer();

	getline(cin, texto);

	return true;
}

void Cuac::escribir(string comando){

	cout << this->usuario << " ";
	this->fecha.escribir();
	cout << endl;

	if (comando == "pcuac"){

		int num = atoi(this->texto.c_str());
		cout << "   " <<getPcuac(num) << endl;
	}
	else cout << "   " << this->texto << endl;
}

bool Cuac::es_anterior(Cuac &otro){

	if (this->fecha.es_menor(otro.fecha)) return true;
	else{

		if (this->fecha.es_igual(otro.fecha)){

			if (this->texto.compare(otro.texto) > 0 ) return true;
			else{

				if (this->texto.compare(otro.texto) == 0){

					return this->usuario.compare(otro.usuario) > 0;
				}
				else return false;
			}
		}
		else return false;
	}
}

int main(void){

	string comando;
	int num = 0;

	while (cin >> comando) {

		Cuac cuac;
		if (comando == "mcuac") cuac.leer_mcuac();
		else if (comando == "pcuac") cuac.leer_pcuac();
		cout << ++num << " cuac" << endl;
		cuac.escribir(comando);
	}
}
