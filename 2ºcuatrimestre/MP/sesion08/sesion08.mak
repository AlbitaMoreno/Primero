#
#	MAKEFILE DE LA SESION 8
#	
#	Alba Moreno Ontiveros
#	
######################################################################


BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include

all : inicio mr-proper $(BIN)/II_07_ListasBasicos $(BIN)/II_08_CalculoListas $(BIN)/II_09_ListaOrdenada $(BIN)/II_10_OrdenarLista $(BIN)/II_11_InsertarEliminarEnListaOrdenada $(BIN)/II_12_MezclarListas fin

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
# BIBLIOTECA
#
#########################################################################
$(LIB)/liblista.a : $(OBJ)/ListasBasicos.o $(OBJ)/Random.o
	@echo Generand biblioteca
	ar rvs 	$(LIB)/liblista.a $(OBJ)/ListasBasicos.o $(OBJ)/Random.o

#########################################################################
# OBJETOS

#########################################################################
$(OBJ)/Random.o : $(SRC)/Random.cpp $(INCLUDE)/Random.h
	g++ -c -o $(OBJ)/Random.o $(SRC)/Random.cpp -I$(INCLUDE)

$(OBJ)/ListasBasicos.o : $(SRC)/ListasBasicos.cpp $(OBJ)/Random.o $(INCLUDE)/ListasBasicos.h
	g++ -c -o $(OBJ)/ListasBasicos.o $(SRC)/ListasBasicos.cpp -I$(INCLUDE)

#########################################################################
# 
#SESION 7
#
#########################################################################

#########################################################################
# Ejercicio 7
#
#########################################################################

$(BIN)/II_07_ListasBasicos : $(LIB)/liblista.a $(SRC)/II_07_ListasBasicos.cpp $(INCLUDE)/ListasBasicos.h
	@echo Generando ejecutable
	g++ -o $@ $^ -I$(INCLUDE) -L$(LIB) -llista

#########################################################################
# Ejercicio 8
#
#########################################################################

$(BIN)/II_08_CalculoListas : $(SRC)/II_08_CalculoListas.cpp $(LIB)/liblista.a $(INCLUDE)/ListasBasicos.h
	@echo Generando ejecutable
	g++ -o $@ $^ -I$(INCLUDE) -L$(LIB) -llista

#########################################################################
# Ejercicio 9
#
#########################################################################

$(BIN)/II_09_ListaOrdenada : $(SRC)/II_09_ListaOrdenada.cpp $(LIB)/liblista.a $(INCLUDE)/ListasBasicos.h
	@echo Generando ejecutable
	g++ -o $@ $^ -I$(INCLUDE) -L$(LIB) -llista

#########################################################################
# Ejercicio 10
#
#########################################################################

$(BIN)/II_10_OrdenarLista : $(SRC)/II_10_OrdenarLista.cpp $(LIB)/liblista.a $(INCLUDE)/ListasBasicos.h
	@echo Generando ejecutable
	g++ -o $@ $^ -I$(INCLUDE) -L$(LIB) -llista

#########################################################################
# Ejercicio 11
#
#########################################################################

$(BIN)/II_11_InsertarEliminarEnListaOrdenada : $(SRC)/II_11_InsertarEliminarEnListaOrdenada.cpp $(LIB)/liblista.a
	@echo Generando ejecutable
	g++ -o $@ $^ -I$(INCLUDE) -L$(LIB) -llista

#########################################################################
# Ejercicio 12
#
#########################################################################

$(BIN)/II_12_MezclarListas : $(SRC)/II_12_MezclarListas.cpp $(LIB)/liblista.a $(INCLUDE)/ListasBasicos.h
	@echo Generando ejecutable
	g++ -o $@ $^ -I$(INCLUDE) -L$(LIB) -llista 

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