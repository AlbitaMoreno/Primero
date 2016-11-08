#
#Alba Moreno Ontiveros
#
# METODOLOGIA DE LA PROGRAMACION
# 
# CURSO 2014-2015
#
# makefile_sesion4.mak
#
#Se corresponde con el makefile del ejercicio resumen de la sesión 1
#####################################################################

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

all : inicio mr-proper $(BIN)/DemosCadenasClasicas fin

inicio : 
	@echo ------------------------------------------------------------
	@echo METODOLOGIA DE LA PROGRAMACIÓN
	@echo Grado en Ingenieria Informatica - Grupo B3
	@echo
	@echo Alba Moreno Ontiveros
	@echo ------------------------------------------------------------

fin : 
	@echo Se han realizado las operaciones con éxito

#########################################################################
# Ejercicio 7
#########################################################################

$(BIN)/I_07_PosicionPrimerBlanco : $(SRC)/I_07_PosicionPrimerBlanco.cpp
	@echo generando ejecutable I_07_PosicionPrimerBlanco
	g++ -o $(BIN)/I_07_PosicionPrimerBlanco $(SRC)/I_07_PosicionPrimerBlanco.cpp

#########################################################################
# Ejercicio 8
#########################################################################

$(BIN)/I_08_SaltaPrimeraPalabra : $(SRC)/I_08_SaltaPrimeraPalabra.cpp
	@echo generando ejecutable I_08_SaltaPrimeraPalabra
	g++ -o $(BIN)/I_08_SaltaPrimeraPalabra $(SRC)/I_08_SaltaPrimeraPalabra.cpp

#########################################################################
# Ejercicio DemosCadenasClasicas.cpp
#########################################################################

#Ejecutable..............................................................

$(BIN)/DemosCadenasClasicas : $(OBJ)/DemosCadenasClasicas.o $(OBJ)/MiCadenaClasica.o 
	@echo Generando ejecutable DemosCadenasClasicas
	g++ -o $(BIN)/DemosCadenasClasicas $(OBJ)/DemosCadenasClasicas.o $(OBJ)/MiCadenaClasica.o 

#Archivos objeto..........................................................

$(OBJ)/DemosCadenasClasicas.o : $(SRC)/DemosCadenasClasicas.cpp $(INCLUDE)/MiCadenaClasica.h
	@echo Generando objeto MiCadenaClasica.o
	g++ -c -o $(OBJ)/DemosCadenasClasicas.o $(SRC)/DemosCadenasClasicas.cpp -I$(INCLUDE)  

$(OBJ)/MiCadenaClasica.o : $(SRC)/MiCadenaClasica.cpp $(INCLUDE)/MiCadenaClasica.h
	@echo Generando objeto MiCadenaClasica.o
	g++ -c -o $(OBJ)/MiCadenaClasica.o $(SRC)/MiCadenaClasica.cpp -I$(INCLUDE) 

#########################################################################
# Limpia
#########################################################################
clean:
	@echo Borrando objetos ...
	-rm $(OBJ)/*
	@echo Borrados

mr-proper:
	@echo Borrando obj y ejecutables ...
	-rm $(OBJ)/* $(BIN)/*
	@echo Borrados
