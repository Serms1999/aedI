/*
 * 404.cpp
 *
 *  Created on: Dec 26, 2018
 *      Author: serms1999
 */

#include <stdlib.h>  // Funcion exit
#include <string.h>  // Funcion memset
#include <iostream>  // Variables cin y cout
#include <queue>
using namespace std;

#define MAX_NODOS 2000
#define infinito 1000000

//////////////////////////////////////////////////////////////
////////////        VARIABLES GLOBALES        ////////////////
//////////////////////////////////////////////////////////////

int nnodos;                   // Numero de nodos del grafo
int naristas;                 // Numero de aristas del grafo
int G[MAX_NODOS][MAX_NODOS];  // Matriz de adyacencia
bool visitado[MAX_NODOS];     // Marcas de nodos visitados
int D[MAX_NODOS-1];
int A, B, C;

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
	memset(G, infinito, sizeof(G));
	cin >> A >> B >> C;
	A = A - 1;
	B = B - 1;
	C = C - 1;
	int c1, c2, c;
	for (int i = 0; i < naristas; i++) {
		cin >> c1 >> c2 >> c;
		G[c1 - 1][c2 - 1] = c;
		G[c2 - 1][c1 - 1] = c;
	}
}

void dijkstra(int a, int b)
{
	for (int i = 0; i < nnodos; i++)
	{
		D[i] = G[a][i];
		visitado[i] = false;
	}
	visitado[a] = true;
	int v = 0;
	for (int i = 0; i < nnodos; i++)
	{
		int min = infinito;
		for (int j = 0; j < nnodos; j++)
		{
			if (D[j] < min && !visitado[j])
			{
				v = j;
				min = D[j];
			}
		}
		if (v != b)
		{
			visitado[v] = true;
			for (int w = 0; w < nnodos; w++)
			{
				if (!visitado[w] && G[v][w] != infinito)
				{
					if (D[w] > G[v][w] + D[v])
					{
						D[w] = G[v][w] + D[v];
					}
				}
			}
		}
		else return;
	}

}


//////////////////////////////////////////////////////////////
////////////        PROGRAMA PRINCIPAL        ////////////////
//////////////////////////////////////////////////////////////

int main (void){

	int ncasos;
	cin >> ncasos;
	int d1;
	for (int i = 0; i < ncasos; i++)
	{
		leeGrafo();
		dijkstra(A,C);
        d1 = D[C];
        dijkstra(C, B);
		if (D[B] < infinito && d1 < infinito && D[B] >= 0 && d1 >= 0)
		{
			cout << d1 + D[B] << endl;
		}
		else cout << "IMPOSIBLE" << endl;
	}
}

