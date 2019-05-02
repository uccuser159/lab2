lab2: lab2.o data.o
	g++ -o lab2 lab2.o data.o

data.o: data.h data.cpp
	g++ -c data.cpp

lab2.o: lab2.cpp data.h
	g++ -c lab2.cpp

clean:
	rm lab2 *.o
