basicIO: main.o
	g++ main.o -o basicIO
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm main.o basicIO
