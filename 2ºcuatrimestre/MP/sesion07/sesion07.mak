#
#	MAKEFILE DE LA SESION 7
#	
#	Alba Moreno Ontiveros
#	
######################################################################

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

all : inicio mr-proper $(BIN)/II_04_Demo-Matriz2D_1 $(BIN)/II_05_Demo-Matriz2D_2 $(BIN)/II_06_Demo-Conversiones-Matriz2D fin

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
# SESION 7
#########################################################################

#########################################################################
# Ejercicio 4
#
#########################################################################
$(BIN)/II_04_Demo-Matriz2D_1 : $(OBJ)/II_04_Demo-Matriz2D_1.o $(OBJ)/Matriz2D_1.o $(OBJ)/Random.o
	@echo Generando ejecutables
	g++ -o $(BIN)/II_04_Demo-Matriz2D_1 $(OBJ)/II_04_Demo-Matriz2D_1.o $(OBJ)/Matriz2D_1.o $(OBJ)/Random.o

$(OBJ)/II_04_Demo-Matriz2D_1.o : $(SRC)/II_04_Demo-Matriz2D_1.cpp $(INCLUDE)/Matriz2D_1.h $(INCLUDE)/Random.h
	@echo Generando objetos
	g++ -c -o $(OBJ)/II_04_Demo-Matriz2D_1.o $(SRC)/II_04_Demo-Matriz2D_1.cpp -I$(INCLUDE)

$(OBJ)/Matriz2D_1.o : $(SRC)/Matriz2D_1.cpp $(INCLUDE)/Matriz2D_1.h $(INCLUDE)/Random.h
	@echo Generando objetos
	g++ -c -o $(OBJ)/Matriz2D_1.o $(SRC)/Matriz2D_1.cpp -I$(INCLUDE)

$(OBJ)/Random.o : $(SRC)/Random.cpp $(INCLUDE)/Random.h
	@echo Generando objetos
	g++ -c -o $(OBJ)/Random.o $(SRC)/Random.cpp -I$(INCLUDE)

#########################################################################
# Ejercicio 5
#
#########################################################################

$(BIN)/II_05_Demo-Matriz2D_2 : $(OBJ)/II_05_Demo-Matriz2D_2.o $(OBJ)/Matriz2D_2.o $(OBJ)/Random.o
	@echo Generando ejecutables
	g++ -o $(BIN)/II_05_Demo-Matriz2D_2 $(OBJ)/II_05_Demo-Matriz2D_2.o $(OBJ)/Matriz2D_2.o $(OBJ)/Random.o 	-std=c++11

$(OBJ)/II_05_Demo-Matriz2D_2.o : $(SRC)/II_05_Demo-Matriz2D_2.cpp $(INCLUDE)/Matriz2D_2.h $(INCLUDE)/Random.h 	
	@echo Generando objetos
	g++ -c -o $(OBJ)/II_05_Demo-Matriz2D_2.o $(SRC)/II_05_Demo-Matriz2D_2.cpp -I$(INCLUDE)	-std=c++11

$(OBJ)/Matriz2D_2.o : $(SRC)/Matriz2D_2.cpp $(INCLUDE)/Matriz2D_2.h $(INCLUDE)/Random.h
	@echo Generando objetos
	g++ -c -o $(OBJ)/Matriz2D_2.o $(SRC)/Matriz2D_2.cpp -I$(INCLUDE)	-std=c++11

#########################################################################
# Ejercicio 6
#
#########################################################################
$(BIN)/II_06_Demo-Conversiones-Matriz2D : $(OBJ)/II_06_Demo-Conversiones-Matriz2D.o $(OBJ)/Convertir_Matriz.o $(OBJ)/Matriz2D_2.o $(OBJ)/Matriz2D_1.o $(OBJ)/Random.o
	@echo Generando ejecutables
	g++ -o $(BIN)/II_06_Demo-Conversiones-Matriz2D $(OBJ)/II_06_Demo-Conversiones-Matriz2D.o $(OBJ)/Convertir_Matriz.o $(OBJ)/Random.o $(OBJ)/Matriz2D_2.o $(OBJ)/Matriz2D_1.o

$(OBJ)/II_06_Demo-Conversiones-Matriz2D.o : $(SRC)/II_06_Demo-Conversiones-Matriz2D.cpp $(INCLUDE)/Convertir_Matriz.h $(INCLUDE)/Random.h 
	@echo Generando objetos
	g++ -c -o $(OBJ)/II_06_Demo-Conversiones-Matriz2D.o $(SRC)/II_06_Demo-Conversiones-Matriz2D.cpp -I$(INCLUDE)

$(OBJ)/Convertir_Matriz.o : $(SRC)/Convertir_Matriz.cpp $(INCLUDE)/Convertir_Matriz.h
	@echo Generando objetos
	g++ -c -o $(OBJ)/Convertir_Matriz.o $(SRC)/Convertir_Matriz.cpp -I$(INCLUDE)
	
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