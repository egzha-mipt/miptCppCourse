lib.o: lib.cpp
	clang++ -c lib.cpp -o lib.o

main.o: main.cpp
	clang++ -c main.cpp -o main.o

main: main.o lib.o
	clang++ main.o lib.o -o onegin.exe

launch: onegin.exe
	./onegin.exe

clean: lib.o main.o onegin.exe
	rm -f lib.o main.o onegin.exe
