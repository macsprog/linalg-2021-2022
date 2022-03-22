default : linalg.a test.exe

linalg.a : matrix.o vect.o
	ar -crs linalg.a matrix.o vect.o

matrix.o : matrix.c
	gcc -Wall -g -c matrix.c

vect.o : vect.c
	gcc -Wall -g -c vect.c

test.o : test.c
	gcc -Wall -g -c test.c

test.exe : test.o linalg.a
	gcc -Wall -o test.exe test.o linalg.a

clean :
	rm -f *.o *.exe *.a