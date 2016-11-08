#
#	MAKEFILE DE LA SESION 11
#	
#	Alba Moreno Ontiveros
#	
######################################################################


BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

all : inicio mr-proper $(BIN)/Demo-VectorDinamico $(BIN)/Demo-Matriz2D_1 $(BIN)/Demo-Lista fin

inicio : 
	@echo ------------------------------------------------------------
	@echo METODOLOGIA DE LA PROGRAMACIÓN
	@echo Grado en Ingenieria Informatica - Grupo B3
	@echo
	@echo Alba Moreno Ontiveros
	@echo ------------------------------------------------------------

fin : 
	@echo Se han realizado las operaciones con exito

#########################################################################
# OBJETOS CLASES
#
#########################################################################

$(OBJ)/VectorDinamico.o : $(SRC)/VectorDinamico.cpp $(INCLUDE)/VectorDinamico.h
	@echo Generando VectorDinamico objeto
	g++ -c -o $@ $(SRC)/VectorDinamico.cpp -I$(INCLUDE)	-std=c++11

$(OBJ)/Matriz2D_1.o : $(SRC)/Matriz2D_1.cpp $(INCLUDE)/Matriz2D_1.h
	@echo Generando Matriz2D_1_objeto
	g++ -c -o $@ $(SRC)/Matriz2D_1.cpp -I$(INCLUDE)

$(OBJ)/Lista.o : $(SRC)/Lista.cpp $(INCLUDE)/Lista.h
	@echo Generando Lista objeto
	g++ -c -o $@ $(SRC)/Lista.cpp -I$(INCLUDE)

#########################################################################
# Main 1, VectorDinámico
#
#########################################################################

$(OBJ)/Demo-VectorDinamico.o : $(SRC)/Demo-VectorDinamico.cpp $(INCLUDE)/VectorDinamico.h
	@echo Generando objeto main ejercicio 1
	g++ -c -o $@ $(SRC)/Demo-VectorDinamico.cpp -I$(INCLUDE)	-std=c++11

$(BIN)/Demo-VectorDinamico : $(OBJ)/VectorDinamico.o $(OBJ)/Demo-VectorDinamico.o
	@echo Generando ejecutable ejercicio 1
	g++ -o $@ $^	-std=c++11

#########################################################################
# Main 2,Matriz2D_1
#
#########################################################################

$(OBJ)/Demo-Matriz2D_1.o : $(SRC)/Demo-Matriz2D_1.cpp $(INCLUDE)/Matriz2D_1.h
	g++ -c -o $@ $(SRC)/Demo-Matriz2D_1.cpp -I$(INCLUDE)	

$(BIN)/Demo-Matriz2D_1 : $(OBJ)/Demo-Matriz2D_1.o $(OBJ)/Matriz2D_1.o
	g++ -o $@ $^

#########################################################################
# Main 4, MiLista
#
#########################################################################

$(OBJ)/Demo-Lista.o : $(SRC)/Demo-Lista.cpp $(INCLUDE)/Lista.h
	g++ -c -o $@ $(SRC)/Demo-Lista.cpp -I$(INCLUDE)

$(BIN)/Demo-Lista : $(OBJ)/Lista.o $(OBJ)/Demo-Lista.o
	g++ -o $@ $^


#########################################################################
# Limpia
#########################################################################
clean:
	@echo borrando objetos ...
	-rm $(OBJ)/*
	@echo borrados

mr-proper:
	@echo borrando obj y ejecutables ...
	-rm $(OBJ)/* $(BIN)/*
	@echo borrados
