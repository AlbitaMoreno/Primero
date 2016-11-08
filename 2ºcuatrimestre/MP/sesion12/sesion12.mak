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

all : inicio mr-proper $(BIN)/Gestion-Lista fin

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
# OBJETOS
#########################################################################

$(OBJ)/ClaseAlumno.o : $(SRC)/ClaseAlumno.cpp $(INCLUDE)/Utils.h $(INCLUDE)/ClaseAlumno.h $(INCLUDE)/ClaseGrupoDeAlumnos-ClaseAlumno-Lista.h
	@echo Generando ClaseAlumno
	g++ -c -o $@ $(SRC)/ClaseAlumno.cpp -I$(INCLUDE)
	
$(OBJ)/ClaseGrupoDeAlumnos-ClaseAlumno-Lista.o : $(SRC)/ClaseGrupoDeAlumnos-ClaseAlumno-Lista.cpp $(INCLUDE)/ClaseGrupoDeAlumnos-ClaseAlumno-Lista.h $(INCLUDE)/ClaseAlumno.h $(INCLUDE)/Utils.h
	@echo Generando ClaseGrupoDeAlumnos-ClaseAlumno-Lista
	g++ -c -o $@ $(SRC)/ClaseGrupoDeAlumnos-ClaseAlumno-Lista.cpp -I$(INCLUDE)

$(OBJ)/Gestion-Lista.o : $(SRC)/Gestion-Lista.cpp $(INCLUDE)/ClaseGrupoDeAlumnos-ClaseAlumno-Lista.h $(INCLUDE)/Utils.h
	@echo Generando ejecutable
	g++ -c -o $@ $(SRC)/Gestion-Lista.cpp -I$(INCLUDE)

$(OBJ)/Utils.o : $(SRC)/Utils.cpp $(INCLUDE)/Utils.h
	g++ -c -o $@ $(SRC)/Utils.cpp -I$(INCLUDE)
	
#########################################################################
# Ejecutable
#########################################################################

$(BIN)/Gestion-Lista : $(OBJ)/ClaseAlumno.o $(OBJ)/ClaseGrupoDeAlumnos-ClaseAlumno-Lista.o $(OBJ)/Gestion-Lista.o $(OBJ)/Utils.o
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
