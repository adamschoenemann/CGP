all: main.exe

main.exe: main.o
	g++ main.o -o main.exe -lglut32win -lopengl32

main.o: main.cpp
	g++ -c main.cpp -o main.o

clean:
	del main.o main.exe