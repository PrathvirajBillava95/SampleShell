VERSION = 0.0.1
CXX= g++
INC = -Iinclude/
BIN = bin/MyShell-$(VERSION)

output: src/main.o src/command.o src/functions.o
	$(CXX) src/main.o src/command.o src/functions.o -o $(BIN)

src/main.o: src/main.cpp
	$(CXX) -c src/main.cpp -o src/main.o $(INC)
src/command.o: src/command.cpp
	$(CXX) -c src/command.cpp -o src/command.o $(INC)
src/functions.o: src/functions.cpp
	$(CXX) -c src/functions.cpp -o src/functions.o $(INC)

clean:
	rm -f src/*.o bin/*
