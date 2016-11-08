#
#	MAKEFILE DE LA SESION 5
#	
#	Alba Moreno Ontiveros
#	
######################################################################

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

all : inicio mr-proper $(BIN)/I_16_PosMayor $(BIN)/I_17_OrdenaConPunteros $(BIN)/I_19_Calificaciones_ArrayStruct_Ordenado fin

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
# SESION 5
#########################################################################

#########################################################################
# Ejercicio 16
#
#########################################################################

#ejecutable
$(BIN)/I_16_PosMayor : $(OBJ)/I_16_PosMayor.o $(OBJ)/PosMayor.o $(OBJ)/Random.o
	@echo Generando I_16_PosMayor
	g++ -o $(BIN)/I_16_PosMayor $(OBJ)/I_16_PosMayor.o $(OBJ)/PosMayor.o $(OBJ)/Random.o

#objetos

$(OBJ)/I_16_PosMayor.o : $(SRC)/I_16_PosMayor.cpp $(INCLUDE)/Random.h $(INCLUDE)/PosMayor.h
	@echo Generando I_16_PosMayor.o
	g++ -c -o $(OBJ)/I_16_PosMayor.o $(SRC)/I_16_PosMayor.cpp -I$(INCLUDE)	-std=c++11

$(OBJ)/PosMayor.o : $(SRC)/PosMayor.cpp $(INCLUDE)/PosMayor.h
	@echo Generando PosMayor.o
	g++ -c -o $(OBJ)/PosMayor.o $(SRC)/PosMayor.cpp -I$(INCLUDE)	-std=c++11

$(OBJ)/Random.o : $(SRC)/Random.cpp $(INCLUDE)/Random.h
	@echo Generando Random.o
	g++ -c -o $(OBJ)/Random.o $(SRC)/Random.cpp -I$(INCLUDE)	-std=c++11

#########################################################################
# Ejercicio 17
#
#########################################################################

#ejecutable
$(BIN)/I_17_OrdenaConPunteros : $(OBJ)/I_17_OrdenaConPunteros.o $(OBJ)/Ordena.o $(OBJ)/Random.o
	@echo Generando ejecutable I_17_OrdenaConPunteros
	g++ -o $(BIN)/I_17_OrdenaConPunteros $(OBJ)/I_17_OrdenaConPunteros.o $(OBJ)/Ordena.o $(OBJ)/Random.o

#objetos

$(OBJ)/I_17_OrdenaConPunteros.o : $(SRC)/I_17_OrdenaConPunteros.cpp $(INCLUDE)/Random.h $(INCLUDE)/Ordena.h
	@echo Generando I_17_OrdenaConPunteros.o
	g++ -c -o $(OBJ)/I_17_OrdenaConPunteros.o $(SRC)/I_17_OrdenaConPunteros.cpp -I$(INCLUDE)	-std=c++11

$(OBJ)/Ordena.o : $(SRC)/Ordena.cpp $(INCLUDE)/Ordena.h
	@echo Generando Ordena.o
	g++ -c -o $(OBJ)/Ordena.o $(SRC)/Ordena.cpp -I$(INCLUDE)	-std=c++11

$(OBJ)/Random.o : $(SRC)/Random.cpp $(INCLUDE)/Random.h
	@echo Generando Random.o
	g++ -c -o $(OBJ)/Random.o $(SRC)/Random.cpp -I$(INCLUDE)	-std=c++11

#########################################################################
# Ejercicio 18
#
#########################################################################

$(BIN)/I_18_Calificaciones_ArrayStruct : $(SRC)/I_18_Calificaciones_ArrayStruct.cpp
	@echo Generando I_18_Calificaciones_ArrayStruct
	g++ -o $(BIN)/I_18_Calificaciones_ArrayStruct $(SRC)/I_18_Calificaciones_ArrayStruct.cpp


#########################################################################
# Ejercicio 19
#
#########################################################################

$(BIN)/I_19_Calificaciones_ArrayStruct_Ordenado : $(OBJ)/I_19_Calificaciones_ArrayStruct_Ordenado.o $(OBJ)/Calificaciones_ArrayStruct.o
	@echo Generando I_19_Calificaciones_ArrayStruct_Ordenado ejecutable
	g++ -o $(BIN)/I_19_Calificaciones_ArrayStruct_Ordenado $(OBJ)/I_19_Calificaciones_ArrayStruct_Ordenado.o $(OBJ)/Calificaciones_ArrayStruct.o

#Objetos
$(OBJ)/I_19_Calificaciones_ArrayStruct_Ordenado.o : $(SRC)/I_19_Calificaciones_ArrayStruct_Ordenado.cpp $(INCLUDE)/Calificaciones_ArrayStruct.h
	@echo Generando I_19_Calificaciones_ArrayStruct_Ordenado.o
	g++ -c -o $(OBJ)/I_19_Calificaciones_ArrayStruct_Ordenado.o $(SRC)/I_19_Calificaciones_ArrayStruct_Ordenado.cpp -I$(INCLUDE)	-std=c++11

$(OBJ)/Calificaciones_ArrayStruct.o : $(SRC)/Calificaciones_ArrayStruct.cpp $(INCLUDE)/Calificaciones_ArrayStruct.h
	@echo Generando Calificaciones_ArrayStruct.o
	g++ -c -o $(OBJ)/Calificaciones_ArrayStruct.o $(SRC)/Calificaciones_ArrayStruct.cpp -I$(INCLUDE)	-std=c++11

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