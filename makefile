game: Shapes.o Board.o main.o
	g++ Shapes.o Board.o main.o -o tetris -framework CoreGraphics

Shapes.o: src/Shapes.cpp
	g++ -c src/Shapes.cpp

Board.o: src/Board.cpp
	g++ -c src/Board.cpp

main.o: src/main.cpp
	g++ -c src/main.cpp

clean:
	rm *.o