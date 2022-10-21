#006 Mooshak
a.out: 006.o Cuac.o Fecha.o Interprete.o Dicc.o
	g++ 006.o Cuac.o Fecha.o Interprete.o Dicc.o

006.o: 006.cpp Interprete.h Dicc.h
	g++ -c 006.cpp
Cuac.o: Cuac.cpp Cuac.h
	g++ -c Cuac.cpp 
Fecha.o: Fecha.cpp Fecha.h
	g++ -c Fecha.cpp
Interprete.o: Interprete.cpp Interprete.h Cuac.h Fecha.h Dicc.h
	g++ -c Interprete.cpp 
Dicc.o: Dicc.cpp Dicc.h Cuac.h
	g++ -c Dicc.cpp
