all: test_graphe

test_graphe: test_graphe.o graphe.o io_graphe.o file.o
	gcc -g -o test_graphe test_graphe.o graphe.o io_graphe.o file.o

graphe.o: graphe.c graphe.h file.h
	gcc -Wall -g -c graphe.c file.h

io_graphe.o: io_graphe.c graphe.h
	gcc -Wall -g -c io_graphe.c

test_graphe.o: test_graphe.c graphe.h
	gcc -g -Wall -c test_graphe.c

file.o: file.c file.h
	gcc -g -Wall -c file.c

clean:
	rm -f *.o test_graphe  *~ data/*~
