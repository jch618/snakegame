CXX := g++
CPPFLAGS := -g
EXCUTABLE := bin
INCLUDES := -I/include
INCLUDE := include
SRC := src
VERSION := -std=c++11
LIB := -lncursesw
OBJ := -g -c
EXEC := -g -o
# g++ -std=c++11 -g -o bin main.cpp snake.cpp point.cpp setmap.cpp gameset.cpp -lncursesw
# snakegame: snakegame.cpp
# 	g++ -std=c++11 -g -o $@ $< -lncursesw

$(EXCUTABLE) : main.o snake.o point.o setmap.o gameset.o item.o item_manager.o
	$(CXX) $(VERSION) $(EXEC) $@ $^ $(LIB)

gameset.o : $(SRC)/gameset.cpp $(INCLUDE)/gameset.h $(INCLUDE)/setmap.h $(INCLUDE)/snake.h
	$(CXX) $(VERSION) $(OBJ) $(INCLUDES) $< $(LIB)

snake.o : $(SRC)/snake.cpp $(INCLUDE)/snake.h $(INCLUDE)/point.h $(INCLUDE)/setmap.h $(INCLUDE)/gameset.h
	$(CXX) $(VERSION) $(OBJ) $(INCLUDES) $< $(LIB)

setmap.o : $(SRC)/setmap.cpp $(INCLUDE)/setmap.h $(INCLUDE)/point.h
	$(CXX) $(VERSION) $(OBJ) $(INCLUDES) $< $(LIB)

point.o : $(SRC)/point.cpp $(INCLUDE)/point.h
	$(CXX) $(VERSION) $(OBJ) $(INCLUDES) $<

item.o : $(SRC)/item.cpp $(INCLUDE)/item.h $(INCLUDE)/setmap.h $(INCLUDE)/point.h
	$(CXX) $(VERSION) $(OBJ) $(INCLUDES) $< $(LIB)

item_manager.o : $(SRC)/item_manager.cpp $(INCLUDE)/item_manager.h $(INCLUDE)/item.h
	$(CXX) $(VERSION) $(OBJ) $(INCLUDES) $< $(LIB)

main.o : $(SRC)/main.cpp $(INCLUDE)/gameset.h
	$(CXX) $(VERSION) $(OBJ) $(INCLUDES) $<

# % : $(SRC)/%.cpp
# 	$(CXX) $(EXEC) $@ $< $(LIB)
#
# %.o : %.cpp
# 	$(CXX) $(VERSION) -g -c $<
