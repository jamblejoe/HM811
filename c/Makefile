CC = gcc
OPTIONS = -ansi -pedantic -Wall -Wextra
LIBS = -lm

# sets the .exe ending on windows machines
ifdef COMSPEC
  PRG = lr.exe
  TEST = test.exe
else
  PRG = lr
  TEST = test
endif

$(PRG): lr.c LinearSystem.o Matrix.o Vector.o Tuple.o
	$(CC) $(OPTIONS) -c lr.c
	$(CC) -o lr.exe lr.o LinearSystem.o Matrix.o Vector.o Tuple.o $(LIBS)

$(TEST): test.c Matrix.o Vector.o Tuple.o
	$(CC) $(OPTIONS) -c test.c
	$(CC) -o test.exe test.o Matrix.o Vector.o Tuple.o $(LIBS)
	
Tuple.o: Tuple.c Tuple.h
	$(CC) $(OPTIONS) -c Tuple.c

Vector.o: Vector.c Vector.h Tuple.h
	$(CC) $(OPTIONS) -c Vector.c

Matrix.o: Matrix.c Matrix.h Tuple.h
	$(CC) $(OPTIONS) -c Matrix.c

LinearSystem.o: LinearSystem.c Matrix.h Vector.h Tuple.h
	$(CC) $(OPTIONS) -c LinearSystem.c

clean:
	del *.o
	del *.exe

	
