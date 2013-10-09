bSTDriver: main.o CHAR.o INT.o
	g++ -g -o bSTDriver main.o CHAR.o INT.o

main.o: main.cpp BinaryTree.h BNode.h
	g++ -g -c main.cpp

INT.o: INT.cpp INT.h
	g++ -g -c INT.cpp

CHAR.o: CHAR.cpp CHAR.h
	g++ -g -c CHAR.cpp