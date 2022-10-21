#305 Mooshak
a.out: 305.o Arbol.o Cuac.o Dicc.o Fecha.o Interprete.o Nodo.o TablaHash.o Listaetiquetas.o
	g++ 305.o Arbol.o Cuac.o Dicc.o Fecha.o Interprete.o Nodo.o TablaHash.o Listaetiquetas.o

305.o: 305.cpp Dicc.h Interprete.h
	g++ -c 305.cpp 
Cuac.o: Cuac.cpp Cuac.h Fecha.h
	g++ -c Cuac.cpp
Dicc.o: Dicc.cpp Dicc.h Cuac.h TablaHash.h Arbol.h Listaetiquetas.h
	g++ -c Dicc.cpp
Nodo.o: Nodo.cpp Nodo.h Cuac.h
	g++ -c Nodo.cpp
Arbol.o: Arbol.cpp Arbol.h Nodo.h
	g++ -c Arbol.cpp
Fecha.o: Fecha.cpp Fecha.h
	g++ -c Fecha.cpp
Interprete.o: Interprete.cpp Interprete.h Cuac.h Fecha.h Dicc.h
	g++ -c Interprete.cpp
TablaHash.o: TablaHash.cpp TablaHash.h Cuac.h
	g++ -c TablaHash.cpp
Listaetiquetas.o: Listaetiquetas.cpp Listaetiquetas.h Cuac.h
	g++ -c Listaetiquetas.cpp
