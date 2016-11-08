#
#	MAKEFILE DE LA SESION 10
#	
#	Alba Moreno Ontiveros
#	
######################################################################


BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

all : inicio mr-proper $(BIN)/Demo-VectorDinamico_Asignacion-Acceso $(BIN)/Demo-Matriz2D_1_Asignacion-Acceso $(BIN)/Demo-Matriz2D_2_Asignacion_Acceso $(BIN)/Demo-Lista_Asignacion_Acceso fin

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

$(OBJ)/VectorDinamico_Asignacion-Acceso.o : $(SRC)/VectorDinamico_Asignacion-Acceso.cpp $(INCLUDE)/VectorDinamico_Asignacion_Acceso.h
	@echo Generando VectorDinamico_Asignacion-Acceso objeto
	g++ -c -o $@ $(SRC)/VectorDinamico_Asignacion-Acceso.cpp -I$(INCLUDE)	-std=c++11

$(OBJ)/Matriz2D_1_Asignacion-Acceso.o : $(SRC)/Matriz2D_1_Asignacion-Acceso.cpp $(INCLUDE)/Matriz2D_1_Asignacion_Acceso.h
	@echo Generando Matriz2D_1_Asignacion_Acceso objeto
	g++ -c -o $@ $(SRC)/Matriz2D_1_Asignacion-Acceso.cpp -I$(INCLUDE)

$(OBJ)/Matriz2D_2_Asignacion_Acceso.o : $(SRC)/Matriz2D_2_Asignacion_Acceso.cpp $(INCLUDE)/Matriz2D_2_Asignacion_Acceso.h
	@echo Generando Matriz2D_2_Asignacion_Acceso objeto
	g++ -c -o $@ $(SRC)/Matriz2D_2_Asignacion_Acceso.cpp -I$(INCLUDE)

$(OBJ)/Lista_Asignacion_Acceso.o : $(SRC)/Lista_Asignacion_Acceso.cpp $(INCLUDE)/Lista_Asignacion_Acceso.h
	@echo Generando Lista_Asignacion_Acceso objeto
	g++ -c -o $@ $(SRC)/Lista_Asignacion_Acceso.cpp -I$(INCLUDE)

#########################################################################
# Main 1, VectorDinámico
#
#########################################################################

$(OBJ)/Demo-VectorDinamico_Asignacion-Acceso.o : $(SRC)/Demo-VectorDinamico_Asignacion-Acceso.cpp $(INCLUDE)/VectorDinamico_Asignacion_Acceso.h
	@echo Generando objeto main ejercicio 1
	g++ -c -o $@ $(SRC)/Demo-VectorDinamico_Asignacion-Acceso.cpp -I$(INCLUDE)	-std=c++11

$(BIN)/Demo-VectorDinamico_Asignacion-Acceso : $(OBJ)/VectorDinamico_Asignacion-Acceso.o $(OBJ)/Demo-VectorDinamico_Asignacion-Acceso.o
	@echo Generando ejecutable ejercicio 1
	g++ -o $@ $^	-std=c++11

#########################################################################
# Main 2,Matriz2D_1
#
#########################################################################

$(OBJ)/Demo-Matriz2D_1_Asignacion-Acceso.o : $(SRC)/Demo-Matriz2D_1_Asignacion_Acceso.cpp $(INCLUDE)/Matriz2D_1_Asignacion_Acceso.h
	g++ -c -o $@ $(SRC)/Demo-Matriz2D_1_Asignacion_Acceso.cpp -I$(INCLUDE)

$(BIN)/Demo-Matriz2D_1_Asignacion-Acceso : $(OBJ)/Demo-Matriz2D_1_Asignacion-Acceso.o $(OBJ)/Matriz2D_1_Asignacion-Acceso.o
	g++ -o $@ $^

#########################################################################
# Main 3,Matriz2D_2
#
#########################################################################

$(OBJ)/Demo-Matriz2D_2_Asignacion_Acceso.o : $(SRC)/Demo-Matriz2D_2_Asignacion_Acceso.cpp $(INCLUDE)/Matriz2D_2_Asignacion_Acceso.h
	g++ -c -o $@ $(SRC)/Demo-Matriz2D_2_Asignacion_Acceso.cpp -I$(INCLUDE)

$(BIN)/Demo-Matriz2D_2_Asignacion_Acceso : $(OBJ)/Demo-Matriz2D_2_Asignacion_Acceso.o $(OBJ)/Matriz2D_2_Asignacion_Acceso.o
	g++ -o $@ $^

#########################################################################
# Main 4, MiLista
#
#########################################################################

$(OBJ)/Demo-Lista_Asignacion_Acceso.o : $(SRC)/Demo-Lista_Asignacion_Acceso.cpp $(INCLUDE)/Lista_Asignacion_Acceso.h
	g++ -c -o $@ $(SRC)/Demo-Lista_Asignacion_Acceso.cpp -I$(INCLUDE)

$(BIN)/Demo-Lista_Asignacion_Acceso : $(OBJ)/Lista_Asignacion_Acceso.o $(OBJ)/Demo-Lista_Asignacion_Acceso.o
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