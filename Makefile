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

$(EXCUTABLE) : main.o snake.o point.o setmap.o gameset.o item.o item_manager.o block.o gate.o block_manager.o
	$(CXX) $(VERSION) $(EXEC) $@ $^ $(LIB)

gameset.o : $(SRC)/gameset.cpp $(INCLUDE)/gameset.h $(INCLUDE)/setmap.h $(INCLUDE)/snake.h $(INCLUDE)/item_manager.h $(INCLUDE)/block_manager.h
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

block.o : $(SRC)/block.cpp $(INCLUDE)/block.h $(INCLUDE)/setmap.h $(INCLUDE)/point.h
	$(CXX) $(VERSION) $(OBJ) $(INCLUDES) $< $(LIB)

gate.o : $(SRC)/gate.cpp $(INCLUDE)/gate.h $(INCLUDE)/setmap.h $(INCLUDE)/point.h
	$(CXX) $(VERSION) $(OBJ) $(INCLUDES) $< $(LIB)

block_manager.o : $(SRC)/block_manager.cpp $(INCLUDE)/block_manager.h $(INCLUDE)/setmap.h $(INCLUDE)/point.h $(INCLUDE)/block.h $(INCLUDE)/gate.h
	$(CXX) $(VERSION) $(OBJ) $(INCLUDES) $< $(LIB)

main.o : $(SRC)/main.cpp $(INCLUDE)/gameset.h
	$(CXX) $(VERSION) $(OBJ) $(INCLUDES) $<

# % : $(SRC)/%.cpp
# 	$(CXX) $(EXEC) $@ $< $(LIB)
#
# %.o : %.cpp
# 	$(CXX) $(VERSION) -g -c $<
