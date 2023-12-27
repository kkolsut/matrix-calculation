//funk_plik.h
//
//funkcje zwiazane z czytaniem i pisaniem
//oraz do obslugi plikow
//
//autor: Krzysztof Kolsut 
//       kolsut@antraes.astrouw.edu.pl
//
//program rozpowszechniany na zasadzie licencji GNU GPL
//funkcja czytajaca macierz do tablicy
#include <stdio.h>

void czytanie(FILE *file, double **tab, int N, int M);

//funkcja wypisujaca 
void wypisz(double **tab, int N1, int M2);

//funkcja zliczajaza kolumny (oddzielone tabulacja)
int kolumny(FILE *file);

//funkcja sprawdzajaca liczbe wierszy w pliku
int wiersze(FILE *file);

//funkcja czytajaca wektor z pliku
void czytanie_wek(FILE *file, double *tab, int N);

//funkcja wypisujaca wektor na ekran
void wypisz_wek(double *tab, int N);
