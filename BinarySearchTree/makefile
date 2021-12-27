a.out: BinarySearch.o Node.o
	g++ BinarySearch.o Node.o

Node.o: Node.cc Node.h BinarySearch.h
	g++ -c Node.cc BinarySearch.cc

BinarySearch.o: BinarySearch.cc BinarySearch.h Node.cc Node.h
	g++ -c BinarySearch.cc Node.cc