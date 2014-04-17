all: tm

tm: ./bin/tm.o ./bin/Reader.o ./bin/Processor.o ./bin/Machine.o
	g++ ./bin/tm.o ./bin/Reader.o ./bin/Processor.o ./bin/Machine.o -o tm

./bin/tm.o: ./src/tm.cpp
	g++ -g -c ./src/tm.cpp -o ./bin/tm.o

./bin/Reader.o: ./src/Reader.cpp
	g++ -g -c ./src/Reader.cpp -o ./bin/Reader.o

./bin/Processor.o: ./src/Processor.cpp
	g++ -g -c ./src/Processor.cpp -o ./bin/Processor.o

./bin/Machine.o: ./src/Machine.cpp
	g++ -g -c ./src/Machine.cpp -o ./bin/Machine.o

clean:
	rm -f tm ./bin/*.o
