# Con un código tan simple, usemos un makefile simplificado
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++03 -pedantic -g
INC=./include
SRC=./src
OBJ=./obj
BIN=./bin
TEST=./test

# ************ Generación de ejecutable ************

$(BIN)/calcular: $(OBJ)/calcular.o $(OBJ)/matriz_bit.o $(OBJ)/matriz_operaciones.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ)/calcular.o: $(SRC)/calcular.cpp $(INC)/matriz_bit.h $(INC)/matriz_operaciones.h
	$(CXX) -I$(INC) $(CXXFLAGS) -c -o $@ $<

$(OBJ)/matriz_bit.o: $(INC)/matriz_bit.h $(SRC)/matriz_bit.cpp $(INC)/matriz_bit1.h $(SRC)/matriz_bit1.cpp $(INC)/matriz_bit2.h $(SRC)/matriz_bit2.cpp  $(INC)/matriz_bit3.h $(SRC)/matriz_bit3.cpp $(INC)/matriz_bit4.h $(SRC)/matriz_bit4.cpp
	$(CXX) -I$(INC) $(CXXFLAGS) -c -o $@ $(SRC)/matriz_bit.cpp

$(OBJ)/matriz_operaciones.o: $(SRC)/matriz_operaciones.cpp $(INC)/matriz_operaciones.h
	$(CXX) -I$(INC) $(CXXFLAGS) -c -o $@ $<

# ************ Limpieza ************
clean:
	-rm $(BIN)/calcular $(INC)/~* $(OBJ)/*.o

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Generación de tests ******************
tests: $(TEST)/*.cpp
	$(TEST)/compilar_tests.sh $(TEST) $(INC) $(SRC)
