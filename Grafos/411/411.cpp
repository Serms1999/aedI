/*
 * 411.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: serms1999
 */

#include <stdlib.h>  // Funcion exit
#include <string.h>  // Funcion memset
#include <iostream>  // Variables cin y cout
using namespace std;

#define MAX_NODOS 2000

//////////////////////////////////////////////////////////////
////////////        VARIABLES GLOBALES        ////////////////
//////////////////////////////////////////////////////////////

int nnodos;                   // Numero de nodos del grafo
int naristas;                 // Numero de aristas del grafo
bool G[MAX_NODOS][MAX_NODOS]; // Matriz de adyacencia
int marcas[MAX_NODOS];		  // Marcas de nodos
int numcomponentes;

//////////////////////////////////////////////////////////////
////////////     FUNCIONES DEL PROGRAMA       ////////////////
//////////////////////////////////////////////////////////////

void leeGrafo(void)
// Procedimiento para leer un grafo de la entrada
{
	cin >> nnodos >> naristas;
	if (nnodos<0 || nnodos>MAX_NODOS) {
		cerr << "Numero de nodos (" << nnodos << ") no valido\n";
		exit(0);
	}
	memset(G, 0, sizeof(G));
	int c1, c2;
	for (int i = 0; i < naristas; i++) {
		cin >> c1 >> c2;
		G[c1 - 1][c2 - 1] = true;
		G[c2 - 1][c1 - 1] = true;
	}
}

void bpp(int v)
{
	for (int w = 0; w < nnodos; w++)
	{
		if (marcas[w] == 0 && G[v][w])
		{
			marcas[w] = numcomponentes;
			bpp(w);
		}
	}
}

void calculaComponentesConexos(void)
{
	memset(marcas, 0, sizeof(marcas));
	numcomponentes = 0;
	for (int v = 0; v < nnodos; v++)
	{
		if (marcas[v] == 0)
		{
			numcomponentes++;
			marcas[v] = numcomponentes;
			bpp(v);
		}
	}
}




//////////////////////////////////////////////////////////////
////////////        PROGRAMA PRINCIPAL        ////////////////
//////////////////////////////////////////////////////////////

int main (void){

	int ncasos;
	cin >> ncasos;
	
	for (int i = 0; i < ncasos; i++)
	{
		leeGrafo();
		calculaComponentesConexos();
		cout << "Caso " << i + 1 << endl;
		cout << numcomponentes << endl;
		for (int j = 0; j < nnodos; j++)
		{
			cout << marcas[j] << endl;
		}
	}
	
}

