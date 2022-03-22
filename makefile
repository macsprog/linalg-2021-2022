default : linalg.a test.exe test_jacobi.exe

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

test_jacobi.o : test_jacobi.c
	gcc -Wall -g -c test_jacobi.c
	
test_jacobi.exe : test_jacobi.o linalg.a
	gcc -Wall -o test_jacobi.exe test_jacobi.o linalg.a



clean :
	rm -f *.o *.exe *.a