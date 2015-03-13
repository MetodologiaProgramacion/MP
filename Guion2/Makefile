AR= ar
CXX= g++
CXXFLAGS= -Wall -g
LDFLAGS= -L$(LIB)
LDLIBS= -lformas
INC= ./include
SRC= ./src
BIN= ./bin
OBJ= ./obj
LIB= ./lib

all: $(BIN)/area $(BIN)/longitud $(BIN)/central $(BIN)/rectangulo_delimitador

$(BIN)/central: $(OBJ)/central.o $(LIB)/libformas.a
	$(CXX) -I$(INC) $(CXXFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

$(BIN)/area: $(OBJ)/area.o $(LIB)/libformas.a
	$(CXX) -I$(INC) $(CXXFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

$(BIN)/longitud: $(OBJ)/longitud.o $(LIB)/libformas.a
	$(CXX) -I$(INC) $(CXXFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

$(BIN)/rectangulo_delimitador: $(OBJ)/rectangulo_delimitador.o $(LIB)/libformas.a
	$(CXX) -I$(INC) $(CXXFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

$(LIB)/libformas.a: $(OBJ)/circulo.o $(OBJ)/punto.o $(OBJ)/rectangulo.o
	$(AR) -rvs $@ $?

$(OBJ)/central.o: $(SRC)/central.cpp $(INC)/circulo.h $(INC)/punto.h 
	$(CXX) -I$(INC) $(CXXFLAGS) -c -o $@ $<

$(OBJ)/area.o: $(SRC)/area.cpp $(INC)/circulo.h $(INC)/punto.h 
	$(CXX) -I$(INC) $(CXXFLAGS) -c -o $@ $<

$(OBJ)/longitud.o: $(SRC)/longitud.cpp $(INC)/punto.h 
	$(CXX) -I$(INC) $(CXXFLAGS) -c -o $@ $<

$(OBJ)/rectangulo_delimitador.o: $(SRC)/rectangulo_delimitador.cpp $(INC)/rectangulo.h $(INC)/punto.h 
	$(CXX) -I$(INC) $(CXXFLAGS) -c -o $@ $<
	
$(OBJ)/circulo.o: $(SRC)/circulo.cpp $(INC)/circulo.h 
	$(CXX) -I$(INC) $(CXXFLAGS) -c -o $@ $<

$(OBJ)/punto.o: $(SRC)/punto.cpp $(INC)/punto.h 
	$(CXX) -I$(INC) $(CXXFLAGS) -c -o $@ $<

$(OBJ)/rectangulo.o: $(SRC)/rectangulo.cpp $(INC)/rectangulo.h
	$(CXX) -I$(INC) $(CXXFLAGS) -c -o $@ $<

clean:
	-rm $(OBJ)/*.o $(LIB)/lib*.a

mrproper: clean
	-rm $(BIN)/*