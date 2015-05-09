AR= ar
CXX= g++
CXXFLAGS= -Wall -g
INC= ./include
SRC= ./src
BIN= ./bin
OBJ= ./obj
LIB= ./lib


all: documentacion $(BIN)/buscaminas

$(BIN)/buscaminas: $(OBJ)/tablero.o $(OBJ)/CampoMinas.o
	$(CXX) -I$(INC) $(CXXFLAGS) -o $@ $^

$(OBJ)/tablero.o: $(SRC)/tablero.cpp $(INC)/tablero.h
	$(CXX) -I$(INC) $(CXXFLAGS) -c -o $@ $<

$(OBJ)/CampoMinas.o: $(SRC)/CampoMinas.cpp $(INC)/CampoMinas.h
	$(CXX) -I$(INC) $(CXXFLAGS) -c -o $@ $<


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean:
	-rm $(OBJ)/*.o

mrproper: clean
	-rm $(BIN)/* ./doc/html/*
