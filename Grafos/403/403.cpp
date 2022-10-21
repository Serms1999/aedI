/*
 * 403.cpp
 *
 *  Created on: Dec 23, 2018
 *      Author: serms1999
 */

#include <string>
#include <sstream>
#include <stdlib.h>  // Funcion exit
#include <string.h>  // Funcion memset
#include <iostream>  // Variables cin y cout
#include <list>
#include <queue>
using namespace std;

#define MAX_NODOS 20000

//////////////////////////////////////////////////////////////
////////////        VARIABLES GLOBALES        ////////////////
//////////////////////////////////////////////////////////////

int nnodos;                   // Numero de nodos del grafo
list<int> G[MAX_NODOS];       // Listas de adyacencia
bool visitado[MAX_NODOS];     // Marcas de nodos visitados
list<int> nodos;
bool salida, nocamino;

//////////////////////////////////////////////////////////////
////////////     FUNCIONES DEL PROGRAMA       ////////////////
//////////////////////////////////////////////////////////////

void leeGrafo(void)
// Procedimiento para leer un grafo de la entrada
{
	cin >> nnodos;
	cin.ignore();
	if (nnodos<0 || nnodos>MAX_NODOS) {
		cerr << "Numero de nodos (" << nnodos << ") no valido\n";
		exit(0);
	}
	for (int i = 0; i < MAX_NODOS; i++) {

		G[i].clear();
		visitado[i] = false;
	}
	string cadena;
	int c1;
	for (int i = 0; i < nnodos; i++) {

		getline(cin, cadena);

		istringstream iss;
		iss.str(cadena);
		for (int j = 0; j < 10; j++)
		{
			iss >> c1;
			G[i].push_back(c1);
		}
	}
}


void busquedaPP(int v) 
{
	if (v + 1 == nnodos) 
	{
		salida = true;
		nodos.push_back(v + 1);
		return;
	}
	if (!salida)
	{
		list<int> I = G[v];
		list<int>::iterator it;
		it = I.begin();
		visitado[v] = true;
		while (it != I.end() && !salida)
		{
			if (!visitado[*it - 1])
			{
				nodos.push_back(v + 1);
				busquedaPP(*it - 1);
			}
			else
			{
				if (v == 0)
				{
					it++;
					if (it == I.end())
					{
						nocamino = true;
						return;
					}
					else it--;
				}
			}
			it++;
		}
	}
	if (!salida) nodos.push_back(v + 1);
}

//////////////////////////////////////////////////////////////
////////////        PROGRAMA PRINCIPAL        ////////////////
//////////////////////////////////////////////////////////////

int main (void)
{
  int ncasos;
  cin >> ncasos;
  for (int i= 0; i<ncasos; i++)
  {
    nodos.clear();
	leeGrafo();
	salida = false;
	nocamino = false;
	cout << "Caso " << i + 1 << endl;
	busquedaPP(0);
	if (!nocamino)
	{
		list<int>::iterator it;
		it = nodos.begin();
		cout << nodos.size() << endl;
		while (it != nodos.end())
		{
			cout << *it << endl;
			it++;
		}
	}
	else cout << "INFINITO" << endl;
  }
}

