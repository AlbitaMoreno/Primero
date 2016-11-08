#
#	MAKEFILE DE LA SESION 6
#	
#	Alba Moreno Ontiveros
#	
######################################################################

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

all : inicio mr-proper $(BIN)/II_02_II_02_Calificaciones_ArrayStruct_ordenado fin

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
# SESION 6
#########################################################################

#########################################################################
# Ejercicio 1
#
#########################################################################

$(BIN)/II_01_RedimensionarArrayDinamico : $(OBJ)/II_01_RedimensionarArrayDinamico.o $(OBJ)/RedimensionarArrayDinamico.o
	@echo Generando ejecutable II_01_RedimensionarArrayDinamico
	g++ -o $(BIN)/II_01_RedimensionarArrayDinamico $(OBJ)/II_01_RedimensionarArrayDinamico.o $(OBJ)/RedimensionarArrayDinamico.o

$(OBJ)/II_01_RedimensionarArrayDinamico.o :$(SRC)/II_01_RedimensionarArrayDinamico.cpp $(INCLUDE)/RedimensionarArrayDinamico.h
	@echo Generando objeto II_01_RedimensionarArrayDinamico.o
	g++ -c -o $(OBJ)/II_01_RedimensionarArrayDinamico.o $(SRC)/II_01_RedimensionarArrayDinamico.cpp -I$(INCLUDE)	-std=c++11

$(OBJ)/RedimensionarArrayDinamico.o : $(SRC)/RedimensionarArrayDinamico.cpp $(INCLUDE)/RedimensionarArrayDinamico.h
	@echo Generando RedimensionarArrayDinamico.o 
	g++ -c -o $(OBJ)/RedimensionarArrayDinamico.o $(SRC)/RedimensionarArrayDinamico.cpp -I$(INCLUDE)	-std=c++11


#########################################################################
# Ejercicio 2
#
#########################################################################
$(BIN)/II_02_II_02_Calificaciones_ArrayStruct_ordenado : $(SRC)/II_02_Calificaciones_ArrayStruct_ordenado.cpp 
	@echo Generando ejecutable II_02_Calificaciones_ArrayStruct_ordenado
	g++ -o $(BIN)/II_02_Calificaciones_ArrayStruct_ordenado $(SRC)/II_02_Calificaciones_ArrayStruct_ordenado.cpp 

#########################################################################
# Ejercicio 3
#
#########################################################################

$(BIN)/PoligonoRegular : $(SRC)/PoligonoRegular.cpp
	@echo Generando ejecutable PoligonoRegular
	g++ -o $(BIN)/PoligonoRegular $(SRC)/PoligonoRegular.cpp	-std=c++11
	
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