VERSION = -std=c++11
LIB = -lncursesw
# g++ -std=c++11 -g -o bin main.cpp snake.cpp point.cpp setmap.cpp gameset.cpp -lncursesw
# snakegame: snakegame.cpp
# 	g++ -std=c++11 -g -o $@ $< -lncursesw

bin : main.o snake.o point.o setmap.o gameset.o $(LIB)
	g++ $(VERSION) -g -o $@ $^

gameset.o : gameset.cpp snake.h gameset.h $(LIB)
	g++ $(VERSION) -g -c $< $(LIB)

snake.o : snake.cpp setmap.h snake.h point.h $(LIB)
	g++ $(VERSION) -g -c $<

setmap.o : setmap.cpp setmap.h point.h gameset.h $(LIB)
	g++ $(VERSION) -g -c $<

point.o : point.cpp point.h
	g++ $(VERSION) -g -c $<

main.o : main.cpp gameset.h
	g++ $(VERSION) -g -c $<

% : %.cpp
	g++ -g -o $@ $< $(LIB)

%.o : %.cpp
	g++ $(VERSION) -g -c $<
