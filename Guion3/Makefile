AR= ar
CXX= g++
CXXFLAGS= -Wall -g
INC= ./include
SRC= ./src
BIN= ./bin
OBJ= ./obj
LIB= ./lib


exe: $(BIN)/ocultar $(BIN)/revelar

all: documentacion $(BIN)/ocultar $(BIN)/revelar

$(BIN)/ocultar: $(OBJ)/ocultar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o
	$(CXX) -I$(INC) $(CXXFLAGS) -o $@ $^

$(BIN)/revelar: $(OBJ)/revelar.o $(OBJ)/codificar.o $(OBJ)/imagenES.o
	$(CXX) -I$(INC) $(CXXFLAGS) -o $@ $^

$(OBJ)/ocultar.o: $(SRC)/ocultar.cpp $(OBJ)/codificar.o $(OBJ)/imagenES.o 
	$(CXX) -I$(INC) $(CXXFLAGS) -c -o $@ $<

$(OBJ)/revelar.o: $(SRC)/revelar.cpp $(OBJ)/codificar.o $(OBJ)/imagenES.o
	$(CXX) -I$(INC) $(CXXFLAGS) -c -o $@ $<

$(OBJ)/codificar.o: $(SRC)/codificar.cpp $(INC)/codificar.h
	$(CXX) -I$(INC) $(CXXFLAGS) -c -o $@ $<

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) -I$(INC) $(CXXFLAGS) -c -o $@ $<


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean:
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper: clean
	-rm $(BIN)/* doc/html/*
