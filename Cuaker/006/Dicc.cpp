/*
 * Dicc.cpp
 *
 *  Created on: Nov 13, 2018
 *      Author: amm1999
 */

#include <iostream>
#include "Cuac.h"
#include "Dicc.h"
#include <list>
using namespace std;

DiccionarioCuacs::DiccionarioCuacs(){
	this->contador = 0;
}
void DiccionarioCuacs::insertar (Cuac nuevo) {
	if(this->contador == 0){
        this->lista.push_front(nuevo);
        this->contador++;
        cout << numElem() << " cuac"<< endl;
	}else{
	list<Cuac>::iterator itLista= lista.begin();
	Cuac actual = *itLista;
	while (itLista!=lista.end() && !actual.es_anterior(nuevo)){ 
	itLista++;
	if(itLista!=lista.end()){actual = *itLista;}
	} // end while
	
	if(itLista==lista.end()){
    lista.push_back(nuevo);
	this->contador++;
	}else{
	lista.insert(itLista, nuevo);
	this->contador++;
	}

	cout << numElem() << " cuac"<< endl;

}
}
void DiccionarioCuacs::last(int N){
	int i;
	list<Cuac>::iterator itLista;
	itLista= lista.begin();

	if(N > this->contador){
		N = this->contador;
	}
	for(i = 0; i < N; i++){
	Cuac actual = *itLista;
	cout << i+1 <<". ";
	actual.escribir();
	itLista++;
	}
	cout <<"Total: "<< i <<" cuac"<< endl ;
}
void DiccionarioCuacs::follow(string nombre){
	list<Cuac>::iterator itLista;
	int n=1;
	itLista= lista.begin();
	while(itLista!=lista.end()){
		Cuac actual = *itLista;
		if(actual.getUsuario() == nombre){
			cout << n <<". ";
			actual.escribir();
			n++;
		}
	itLista++;
	}
	cout <<"Total: "<< n-1 <<" cuac"<< endl ;
}
void DiccionarioCuacs::date(Fecha f1, Fecha f2){
    list<Cuac>::iterator itLista;
	int n=1;
	itLista= lista.begin();
	while(itLista!=lista.end()){
		Cuac actual = *itLista;
		Fecha comp = actual.getFecha();
		if((comp.es_igual(f2) || comp.es_menor(f2))
            && (comp.es_igual(f1) || !comp.es_menor(f1))  ){
			cout << n <<". ";
			actual.escribir();
			n++;
		}
	itLista++;
	}
	cout <<"Total: "<< n-1 <<" cuac"<< endl ;
}
