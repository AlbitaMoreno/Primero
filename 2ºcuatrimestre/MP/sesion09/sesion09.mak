#
#	MAKEFILE DE LA SESION 9
#	
#	Alba Moreno Ontiveros
#	
######################################################################


BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

all : inicio mr-proper $(BIN)/Demo-VectorDinamico_ConstructorCopia $(BIN)/Demo-Matriz2D_1_ConstructorCopia $(BIN)/Demo-Matriz2D_2_ConstructorCopia $(BIN)/Demo-Lista_ConstructorCopia $(BIN)/Demo-MiPila $(BIN)/Demo-Cola fin

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

$(OBJ)/VectorDinamico_ConstructorCopia.o : $(SRC)/VectorDinamico_ConstructorCopia.cpp $(INCLUDE)/VectorDinamico_ConstructorCopia.h
	@echo Generando VectorDinamico_ConstructorCopia 
	g++ -c -o $@ $(SRC)/VectorDinamico_ConstructorCopia.cpp -I$(INCLUDE)

$(OBJ)/Matriz2D_1_ConstructorCopia.o : $(SRC)/Matriz2D_1_ConstructorCopia.cpp $(INCLUDE)/Matriz2D_1_ConstructorCopia.h
	@echo Generando Matriz2D_1_ConstructorCopia 
	g++ -c -o $@ $(SRC)/Matriz2D_1_ConstructorCopia.cpp -I$(INCLUDE)

$(OBJ)/Matriz2D_2_ConstructorCopia.o : $(SRC)/Matriz2D_2_ConstructorCopia.cpp $(INCLUDE)/Matriz2D_2_ConstructorCopia.h
	@echo Generando Matriz2D_2_ConstructorCopia 
	g++ -c -o $@ $(SRC)/Matriz2D_2_ConstructorCopia.cpp -I$(INCLUDE)

$(OBJ)/Lista_ConstructorCopia.o : $(SRC)/Lista_ConstructorCopia.cpp $(INCLUDE)/Lista_ConstructorCopia.h
	@echo Generando Lista_ConstructorCopia 
	g++ -c -o $@ $(SRC)/Lista_ConstructorCopia.cpp -I$(INCLUDE)

$(OBJ)/MiPila.o : $(SRC)/MiPila.cpp $(INCLUDE)/MiPila.h
	@echo Generando MiPila 
	g++ -c -o $@ $(SRC)/MiPila.cpp -I$(INCLUDE)

$(OBJ)/Cola.o : $(SRC)/Cola.cpp $(INCLUDE)/Cola.h
	@echo Generando Cola 
	g++ -c -o $@ $(SRC)/Cola.cpp -I$(INCLUDE)

#########################################################################
# Main 1, VectorDinámico
#
#########################################################################

$(OBJ)/Demo-VectorDinamico_ConstructorCopia.o : $(SRC)/Demo-VectorDinamico_ConstructorCopia.cpp $(INCLUDE)/VectorDinamico_ConstructorCopia.h
	g++ -c -o $@ $(SRC)/Demo-VectorDinamico_ConstructorCopia.cpp -I$(INCLUDE)

$(BIN)/Demo-VectorDinamico_ConstructorCopia : $(OBJ)/VectorDinamico_ConstructorCopia.o $(OBJ)/Demo-VectorDinamico_ConstructorCopia.o
	g++ -o $@ $^

#########################################################################
# Main 2,Matriz2D_1
#
#########################################################################

$(OBJ)/Demo-Matriz2D_1_ConstructorCopia.o : $(SRC)/Demo-Matriz2D_1_ConstructorCopia.cpp $(INCLUDE)/Matriz2D_1_ConstructorCopia.h
	g++ -c -o $@ $(SRC)/Demo-Matriz2D_1_ConstructorCopia.cpp -I$(INCLUDE)

$(BIN)/Demo-Matriz2D_1_ConstructorCopia : $(OBJ)/Demo-Matriz2D_1_ConstructorCopia.o $(OBJ)/Matriz2D_1_ConstructorCopia.o
	g++ -o $@ $^

#########################################################################
# Main 3,Matriz2D_2
#
#########################################################################

$(OBJ)/Demo-Matriz2D_2_ConstructorCopia.o : $(SRC)/Demo-Matriz2D_2_ConstructorCopia.cpp $(INCLUDE)/Matriz2D_2_ConstructorCopia.h
	g++ -c -o $@ $(SRC)/Demo-Matriz2D_2_ConstructorCopia.cpp -I$(INCLUDE)

$(BIN)/Demo-Matriz2D_2_ConstructorCopia : $(OBJ)/Demo-Matriz2D_2_ConstructorCopia.o $(OBJ)/Matriz2D_2_ConstructorCopia.o
	g++ -o $@ $^

#########################################################################
# Main 4, MiLista
#
#########################################################################

$(OBJ)/Demo-Lista_ConstructorCopia.o : $(SRC)/Demo-Lista_ConstructorCopia.cpp $(INCLUDE)/Lista_ConstructorCopia.h
	g++ -c -o $@ $(SRC)/Demo-Lista_ConstructorCopia.cpp -I$(INCLUDE)

$(BIN)/Demo-Lista_ConstructorCopia : $(OBJ)/Lista_ConstructorCopia.o $(OBJ)/Demo-Lista_ConstructorCopia.o
	g++ -o $@ $^

#########################################################################
# Main 5, MiPila
#
#########################################################################

$(OBJ)/Demo-MiPila.o : $(SRC)/Demo-MiPila.cpp $(INCLUDE)/MiPila.h
	g++ -c -o $@ $(SRC)/Demo-MiPila.cpp -I$(INCLUDE)

$(BIN)/Demo-MiPila : $(OBJ)/Demo-MiPila.o $(OBJ)/MiPila.o
	g++ -o $@ $^

#########################################################################
# Main 6, Cola
#
#########################################################################

$(OBJ)/Demo-Cola.o : $(SRC)/Demo-Cola.cpp $(INCLUDE)/Cola.h
	g++ -c -o $@ $(SRC)/Demo-Cola.cpp -I$(INCLUDE)

$(BIN)/Demo-Cola : $(OBJ)/Demo-Cola.o $(OBJ)/Cola.o
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