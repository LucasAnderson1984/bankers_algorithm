project: main.o process.o resource.o
	g++ -std=c++11 main.o process.o resource.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

process.o: ./class/process.cpp ./header/process.h
	g++ -std=c++11 -c ./class/process.cpp

resource.o: ./class/resource.cpp ./header/resource.h
	g++ -std=c++11 -c ./class/resource.cpp

clean:
	rm *.o project *.out header/*.gch
