a.out: Interprete.o Lugar.o Mapa.o TablaHash.o Carretera.o Nodo.o ArbolAVL.o Main.o 
	g++ Interprete.o Lugar.o Mapa.o TablaHash.o Carretera.o Nodo.o ArbolAVL.o Main.o 

Interprete.o: Interprete.cpp Interprete.h Lugar.h Mapa.h 
	g++ -c Interprete.cpp

Lugar.o: Lugar.cpp Lugar.h Carretera.h
	g++ -c Lugar.cpp

Mapa.o: Mapa.cpp Mapa.h Lugar.h TablaHash.h
	g++ -c Mapa.cpp

TablaHash.o: TablaHash.cpp TablaHash.h Lugar.h 
	g++ -c TablaHash.cpp

Carretera.o: Carretera.cpp Carretera.h Lugar.h 
	g++ -c Carretera.cpp

Nodo.o: Nodo.cpp Nodo.h Carretera.h Lugar.h
	g++ -c Nodo.cpp

ArbolAVL.o: ArbolAVL.cpp ArbolAVL.h Nodo.h Carretera.h Lugar.h 
	g++ -c ArbolAVL.cpp

Main.o: Main.cpp Interprete.cpp Lugar.cpp Mapa.cpp TablaHash.cpp Carretera.cpp Nodo.cpp ArbolAVL.cpp
	g++ -c Main.cpp