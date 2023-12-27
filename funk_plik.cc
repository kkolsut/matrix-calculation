//funk_plik.cc
//
//funkcje zwiazane z czytaniem i pisaniem
//oraz do obslugi plikow
//
//autor: Krzysztof Kolsut
//       kolsut@antares.astrouw.edu.pl
//
//program rozpowszechniany na zasadzie licencji GNU GPL

#include <stdio.h>
#include "funk_plik.h"

//funkcja czytajaca macierz do tablicy
void czytanie(FILE *file, double **tab, int N, int M)
{
  //M - kolumny; N - wiersze
  
  for(int i=0; i<N; i++)
    {
      
      for(int n=0; n<M; n++)
	fscanf(file, "%lf", &tab[i][n]);
    }

  //przewijamy plik
  rewind(file);
}

//czytanie wektora
void czytanie_wek(FILE *file, double *tab, int N)
{
  // N - wiersze
  
  for(int i=0; i<N; i++)    
    fscanf(file, "%lf", &tab[i]);

  //przewijamy plik
  rewind(file);
}


//funkcja wypisujaca 
void wypisz(double **tab, int N1, int M2)
{
  
  for(int i=0;i<N1;i++)
    {
      for(int ii=0;ii<M2;ii++)
	{
	  //zeby zawinac macierz:)))
	  if(ii==M2-1)
	    printf("%g\n",tab[i][ii]);
	  else
	    printf("%g\t",tab[i][ii]);
	  
	}
    }
}

//wypisanie wektora
void wypisz_wek(double *tab, int N)
{
  
  for(int i=0;i<N;i++)    
    printf("%g\n",tab[i]);
  
}
//funkcja sprawdzajaca liczbe wierszy w pliku
int wiersze(FILE *file)
{
  //zerujemy licznik
  int licznik = 0;
  int c;
  //sprawdzamy po koleii znaki
  while(c!=EOF)
    {
      c = getc(file);
      if(c=='\n')
	licznik++;
     }
  //przewijamy plik
  rewind(file);
  //zwracamy licznik
  return licznik;
}

//funkcja zliczajaca ilosc kolumn (oddzielonych tabulatorem)
int kolumny(FILE *file)
{
  //zawsze jest jedna kolumna wiecej niz tabulacji:)))
  int licznik = 1;
  int c;
  //i sprawdzamy znaki w pierwszym wierszu
  while(c!='\n')
    {
      c=getc(file);
      if(c=='\t')
	licznik++;
     }
  //przywijemy plik do poczatku
  rewind(file);
  //zwracamy licznik
  return licznik;
}





