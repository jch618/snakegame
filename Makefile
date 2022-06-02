CXX := g++
CPPFLAGS := -g
EXCUTABLE := bin
INCLUDE := -I/include
SRC := src
VERSION := -std=c++11
LIB := -lncursesw
OBJ := -g -c
EXEC := -g -o
# g++ -std=c++11 -g -o bin main.cpp snake.cpp point.cpp setmap.cpp gameset.cpp -lncursesw
# snakegame: snakegame.cpp
# 	g++ -std=c++11 -g -o $@ $< -lncursesw

$(EXCUTABLE) : main.o snake.o point.o setmap.o gameset.o item.o $(LIB)
	$(CXX) $(VERSION) $(EXEC) $@ $^

gameset.o : $(SRC)/gameset.cpp
	$(CXX) $(VERSION) $(OBJ) $(INCLUDE) $< $(LIB)

snake.o : $(SRC)/snake.cpp $(LIB)
	$(CXX) $(VERSION) $(OBJ) $(INCLUDE) $<

setmap.o : $(SRC)/setmap.cpp  $(LIB)
	$(CXX) $(VERSION) $(OBJ) $(INCLUDE) $<

point.o : $(SRC)/point.cpp
	$(CXX) $(VERSION) $(OBJ) $(INCLUDE) $<

main.o : $(SRC)/main.cpp
	$(CXX) $(VERSION) $(OBJ) $(INCLUDE) $<

% : $(SRC)/%.cpp
	$(CXX) $(EXEC) $@ $< $(LIB)

%.o : %.cpp
	$(CXX) $(VERSION) -g -c $<
