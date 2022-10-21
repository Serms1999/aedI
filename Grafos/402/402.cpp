/*
 * 402.cpp
 *
 *  Created on: Dec 11, 2018
 *      Author: serms1999
 */

#include <stdlib.h>  // Funcion exit
#include <string.h>  // Funcion memset
#include <iostream>  // Variables cin y cout
#include <queue>
using namespace std;

#define MAX_NODOS 26

//////////////////////////////////////////////////////////////
////////////        VARIABLES GLOBALES        ////////////////
//////////////////////////////////////////////////////////////

int nnodos;                   // Numero de nodos del grafo
int naristas;                 // Numero de aristas del grafo
bool G[MAX_NODOS][MAX_NODOS]; // Matriz de adyacencia
bool visitado[MAX_NODOS];     // Marcas de nodos visitados

//////////////////////////////////////////////////////////////
////////////     FUNCIONES DEL PROGRAMA       ////////////////
//////////////////////////////////////////////////////////////

void leeGrafo (void)
// Procedimiento para leer un grafo de la entrada
{
  cin >> nnodos >> naristas;
  if (nnodos<0 || nnodos>MAX_NODOS) {
    cerr << "Numero de nodos (" << nnodos << ") no valido\n";
    exit(0);
  }
  memset(G, 0, sizeof(G));
  char c1, c2;
  for (int i= 0; i<naristas; i++) {
    cin >> c1 >> c2;
    G[c1-'A'][c2-'A']= true;
  }
}

void bpp(int v)
// Procedimiento recursivo de la busqueda primero en profundidad
//   v - primer nodo visitado en la bpp
{
  visitado[v]= true;
  cout << char(v+'A');
  for (int w= 0; w<nnodos; w++)
    if (!visitado[w] && G[v][w])
      bpp(w);
}

void busquedaPP (void)
// Procedimiento principal de la busqueda en profundidad
{
  memset(visitado, 0, sizeof(visitado));
  for (int v= 0; v<nnodos; v++)
    if (!visitado[v])
      bpp(v);
  cout << endl;
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

//////////////////////////////////////////////////////////////
////////////        PROGRAMA PRINCIPAL        ////////////////
//////////////////////////////////////////////////////////////

int main (void)
{
  int ncasos;
  cin >> ncasos;
  for (int i= 0; i<ncasos; i++) {
    leeGrafo();
    busquedaPA();
  }
}

