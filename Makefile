#Makefile

#ustawiamy kompilator i flagi
CC=g++
CFLAGS=-Wall -lm

all:macierz
macierz:macierz.o funkcje.o funk_plik.o err.o
	$(CC) -o macierz funkcje.o macierz.o funk_plik.o err.o $(CFLAGS)
funkcje.o:funkcje.cc funkcje.h 
	$(CC) -c funkcje.cc -o funkcje.o $(CFLAGS)
macierz.o:macierz.cc
	$(CC) -c macierz.cc -o macierz.o $(CFLAGS)
funk_plik.o:funk_plik.cc funk_plik.h
	$(CC) -c funk_plik.cc -o funk_plik.o $(CFLAGS)
err.o:err.cc err.h
	$(CC) -c err.cc -o err.o $(CFLAGS)
clean:
	rm -f *.o  *~

