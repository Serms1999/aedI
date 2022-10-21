/*
 * 412.cpp
 *
 *  Created on: Dec 26, 2018
 *      Author: serms1999
 */

#include <stdlib.h>  // Funcion exit
#include <string.h>  // Funcion memset
#include <iostream>  // Variables cin y cout
#include <list>
#include <math.h>
#include <queue>
using namespace std;

#define MAX_NODOS 1000
#define infinito 1000000

//////////////////////////////////////////////////////////////
////////////        VARIABLES GLOBALES        ////////////////
//////////////////////////////////////////////////////////////

int nnodos;                   // Numero de nodos del grafo
int naristas;                 // Numero de aristas del grafo
int G[MAX_NODOS][MAX_NODOS];  // Matriz de costes
bool visitado[MAX_NODOS];     // Marcas de nodos visitados
int D[MAX_NODOS];			  // Pesos minimos necesarios desde un nodo
bool primero = true;

//////////////////////////////////////////////////////////////
////////////     FUNCIONES DEL PROGRAMA       ////////////////
//////////////////////////////////////////////////////////////

void leeGrafo(void)
// Procedimiento para leer un grafo de la entrada
{
	cin >> nnodos >> naristas;
	if (nnodos != 0 && naristas != 0) 
	{
		if (nnodos<0 || nnodos>MAX_NODOS) 
		{
			cerr << "Numero de nodos (" << nnodos << ") no valido\n";
			exit(0);
		}
		if (!primero) cout << endl;
        primero = false;
		memset(G, infinito, sizeof(G));
        for (int i = 0; i < MAX_NODOS; i++)
        {
            G[i][i] = 0;
        }
		int c1, c2, c;
		for (int i = 0; i < naristas; i++) 
		{
			cin >> c1 >> c2 >> c;
			G[c1][c2] = c;
			G[c2][c1] = c;
		}
	}
	else exit(0);
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
					if (D[w] > max(G[v][w], D[v]))
					{
						D[w] = max(G[v][w], D[v]);
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

  while (true){
	  leeGrafo();
	  int A,B,Q;
	  bool nocamino;
	  cin >> Q;
	  for (int i = 0; i < Q; i++) {

		  cin >> A >> B;
		  memset(D, infinito, sizeof(D));
		  nocamino = true;
		  dijkstra(A, B);
		  cout << D[B] << endl;
	  }
  }
}

