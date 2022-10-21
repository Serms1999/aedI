#200 Mooshak
a.out: 200.o Cuac.o Dicc.o Fecha.o Interprete.o TablaHash.o
	g++ 200.o Cuac.o Dicc.o Fecha.o Interprete.o TablaHash.o

200.o: 200.cpp Dicc.h Interprete.h
	g++ -c 200.cpp 
Cuac.o: Cuac.cpp Cuac.h Fecha.h
	g++ -c Cuac.cpp
Dicc.o: Dicc.cpp Dicc.h Cuac.h TablaHash.h
	g++ -c Dicc.cpp
Fecha.o: Fecha.cpp Fecha.h
	g++ -c Fecha.cpp
Interprete.o: Interprete.cpp Interprete.h Cuac.h Fecha.h Dicc.h
	g++ -c Interprete.cpp
TablaHash.o: TablaHash.cpp TablaHash.h Cuac.h
	g++ -c TablaHash.cpp
