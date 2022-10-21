/*
 * 404.cpp
 *
 *  Created on: Dec 24, 2018
 *      Author: serms1999
 */

#include <stdlib.h>  // Funcion exit
#include <string.h>  // Funcion memset
#include <iostream>  // Variables cin y cout
#include <queue>
using namespace std;

#define MAX_NODOS 20
#define MAX_INSTANTES 12

//////////////////////////////////////////////////////////////
////////////        VARIABLES GLOBALES        ////////////////
//////////////////////////////////////////////////////////////

int nnodos;                   // Numero de nodos del grafo
int naristas;                 // Numero de aristas del grafo
int G[MAX_NODOS][MAX_NODOS][MAX_INSTANTES];  // Matriz de adyacencia
bool visitado[MAX_NODOS];     // Marcas de nodos visitados
int D[MAX_NODOS];
int P[MAX_NODOS];

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
	int c1, c2, v, inst;
	for (int i = 0; i < naristas; i++) {
		cin >> c1 >> c2 >> v;
		for (int j = 0; j < v; j++) {

			cin >> inst;
			G[c1-1][c2-1][j] = inst;
		}
	}
}

void bpp(int v, int nodos[MAX_NODOS], int&cont)
// Procedimiento recursivo de la busqueda primero en profundidad
//   v - primer nodo visitado en la bpp
{
  visitado[v]= true;
  nodos[cont] = v + 1;
  cont++;
  for (int w = 0; w < nnodos; w++) {
	  if (!visitado[w] && G[v][w]) {
		  bpp(w, nodos, cont);
	  }
  }
}

void busquedaPP (void)
// Procedimiento principal de la busqueda en profundidad
{
  memset(visitado, 0, sizeof(visitado));
  int nodos[MAX_NODOS];
  int cont = 0;
  for (int v = 0; v < nnodos; v++) {
	  if (!visitado[v]) {
		  bpp(v, nodos, cont);
	  }
  }
  cout << cont << endl;
  for (int i = 0; i < nnodos; i++) {

	  cout << nodos[i] << endl;
  }
}

void bpa(int v){

	queue<int> C;
	int x,y;
	visitado[v] = true;
	C.push(v);
	while (!C.empty()){

		x = C.front();
		cout << char(x+'A');
		C.pop();
		for (y = 0; y < nnodos; y++){

			if (!visitado[y] && G[x][y]){

				visitado[y] = true;
				C.push(y);
			}
		}
	}
}

void busquedaPA (void){

	memset(visitado, 0, sizeof(visitado));
	  for (int v= 0; v<nnodos; v++)
	    if (!visitado[v])
	      bpa(v);
	  cout << endl;
}

void dijkstra(int C[MAX_NODOS][MAX_NODOS][MAX_INSTANTES], int D[MAX_NODOS], int P[MAX_NODOS]){

	bool T[MAX_NODOS];

	for (int i = 1; i < nnodos; i++){

		D[i] = C[0][i][0];
		P[i] = 0;
		T[i] = true;
	}
	for (int i = 1; i < nnodos; i++){

		int v = 1;
		for (int j = 1; j < nnodos; j++) {

			if (T[j] == true && D[j] < D[v]) v = j;
		}
		
		for (int w= 0; w<nnodos; w++){

			for (int t = 0; t < naristas; t++) {

				if (!visitado[w] && (D[v] + C[v][w][t] < D[w])) {

					D[w] = D[v] + C[v][w][t];
					P[w] = v;
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////
////////////        PROGRAMA PRINCIPAL        ////////////////
//////////////////////////////////////////////////////////////

int main (void)
{
  int ncasos;
  cin >> ncasos;
  for (int i= 0; i<ncasos; i++) {
		leeGrafo();
		dijkstra(G, D, P);
		int max = D[0];
		for (int j = 1; j < nnodos; j++) {

			if (D[j] > max) max = P[j];
		}
		cout << max << endl;
  }
}

