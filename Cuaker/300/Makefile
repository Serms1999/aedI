#300 Mooshak
a.out: 300.o Arbol.o Cuac.o Dicc.o Fecha.o Interprete.o Nodo.o TablaHash.o
	g++ 300.o Arbol.o Cuac.o Dicc.o Fecha.o Interprete.o Nodo.o TablaHash.o

300.o: 300.cpp Dicc.h Interprete.h
	g++ -c 300.cpp 
Cuac.o: Cuac.cpp Cuac.h Fecha.h
	g++ -c Cuac.cpp
Dicc.o: Dicc.cpp Dicc.h Cuac.h TablaHash.h Arbol.h
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

