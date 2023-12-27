//macierz.cc
//
//program mnozacy macierze i podnoszacy je do kwadratu...
//
//autor: Krzysztof Kolsut 
//       kolsut@antraes.astrouw.edu.pl
//
//program rozpowszechniany na zasadzie licencji GNU GPL


#include "funkcje.h"
#include "funk_plik.h"
#include "err.h"
#include <string.h>

int main(int argc, char *argv[])
{
  char *arg;
  arg = argv[1];
  //sprawdzamy liczbe argumentow
  switch(argc)
    {
    case 2:
      if(strcmp(arg,"-h")==0 || strcmp(arg,"--help")==0)
	pomoc();
      else if(strcmp(arg,"-v")==0 || strcmp(arg,"--version")==0)
	wersja();
      else
	argumenty();
      break;
    case 3:
      //jesli podnosimy do kwadratu
      if(strcmp(arg,"-k")==0 || strcmp(arg,"--kwadrat")==0)
	{
	  //otwieramy plik
	  FILE *file;
	  file = fopen(argv[2], "r");
	  //jesli sie nie uda otworzyc
	  if(!file)
	    {
	      printf("nie moge otwerzyc pliku pliku %s\n", argv[2]);
	      break;
	    }
	  
	  //rozmiar macierzy...
	  int N;
	  N = wiersze(file);
	  int M;
	  M = kolumny(file);
	  
	  //przydzielenie pamieci dla macierzy
	  double **mac;
	  mac = new double*[N];
	  for(int i=0;i<N;i++)
	    {
	      mac[i] = new double[M];
	    }
	  
	  //tu wczytujemy macierz do tablicy
	  czytanie(file, mac, N, M);  
	  
	  //deklaracja wskaznika do koncawej tablicy
	  double **wyn;
	  if(N!=M)
	    {
	      //jesli nie jest kwadratowa to transponujemy i mnozymy
	      wyn = macierz_kwad(mac, M, N);  
	    }
	  else
	    {
	      //jesli jest kwadratowo to po prost mnozymy
	    wyn = macierz(mac, mac, M, M, M);
	    }
	  //...i wypisanie jej na ekran
	  wypisz(wyn, M, M);	  
	}
      else if(strcmp(arg,"-o")==0 || strcmp(arg,"--odwroc")==0)
	{
	   //otwieramy plik
	  FILE *file;
	  file = fopen(argv[2], "r");
	  //jesli sie nie uda otworzyc
	  if(!file)
	    {
	      printf("nie moge otwerzyc pliku pliku %s\n", argv[2]);
	  break;
	    }
	  
	  //rozmiar macierzy... 
	  int N;
	  N = wiersze(file);
	  int M;
	  M = kolumny(file);
	  
	  //jesli macierz nie jest kwadratowa
	  if(N!=M)
	    {
	      printf("to nie jest macierz kwadratowa - nie moge jej odwrocic\n");
	      break;
	    }
	  
	  //przydzielenie pamieci dla macierzy
	  double **mac;
	  mac = new double*[N];
	  for(int i=0;i<N;i++)
	    {
	      mac[i] = new double[M];
	    }
	  
	  //tu wczytujemy macierz do tablicy
	  czytanie(file, mac, N, M);  
	  
	  //deklaracja wskaznika do koncawej tablicy
	  double **wyn;
	  
	  //obliczanie macierzy odwrotnej...
	  wyn = odwroc(mac, M);
	  
	  //wypisywanie
	  wypisz(wyn,N,N);
	}
      else if(strcmp(arg,"-w")==0 || strcmp(arg,"--wyznacznik")==0)
	{
	   //otwieramy plik
	  FILE *file;
	  file = fopen(argv[2], "r");
	  //jesli sie nie uda otworzyc
	  if(!file)
	    {
	      printf("nie moge otwerzyc pliku pliku %s\n", argv[2]);
	  break;
	    }
	  
	  //rozmiar macierzy... 
	  int N;
	  N = wiersze(file);
	  int M;
	  M = kolumny(file);
	  
	  //jesli macierz nie jest kwadratowa
	  if(N!=M)
	    {
	      printf("to nie jest macierz kwadratowa - nie moge jej policzyc wyzncznika");
	      break;
	    }
	  
	  //przydzielenie pamieci dla macierzy
	  double **mac;
	  mac = new double*[N];
	  for(int i=0;i<N;i++)
	    {
	      mac[i] = new double[M];
	    }
	  
	  //tu wczytujemy macierz do tablicy
	  czytanie(file, mac, N, M);  
	  
	  //deklaracja zmiennej na wynik
	  double wyn;
	  
	  //obliczanie macierzy odwrotnej...
	  wyn = wyznacznik(mac, M);
	  
	  //wypisywanie
	  printf("%g\n",wyn);
	}
      else
	argumenty();
      
      break;
      
      //jesli 2...
    case 4:
      if(strcmp(arg,"-m")==0 || strcmp(arg,"--mnozenie")==0)
	{
	  //to nasze pliki z macierzami:))
	  FILE *file1, *file2;
	  //otwieramy je
	  file1 = fopen(argv[2], "r");
	  file2 = fopen(argv[3], "r");
	  
	  //jesli sie nie uda otwarcie
	  if(!file1)
	{
	  printf("nie moge otworzyc pliku %s\n", argv[2]);
	  break;
	}
	  if(!file2)
	    {
	      printf("nie moge otworzyc pliku %s\n", argv[3]);
	      break;
	    } 
	  
	  //tutaj obliczamy rozmiary macierzy w plikach
	  int N1;
	  N1 = wiersze(file1);
	  int M1;
	  M1 = kolumny(file1);
	  int N2;
	  N2 = wiersze(file2);
	  int M2;
	  M2 = kolumny(file2);
	  
	  
	  //zobaczmy czy macierze sa dobre:))
	  if(M1!=N2)
	    {
	      printf("zle wymiary plikow!!!\n");
	      break;
	    }
	  
	  //przydzielenie pamieci dla macierzy pierwszej...
	  double **mac1;
	  mac1 = new double*[N1];
	  for(int i=0;i<N1;i++)
	    {
	      mac1[i] = new double[M1];
	    }
	  
	  //i drugiej
	  double **mac2;
	  mac2 = new double*[N2];
	  for(int i=0;i<N2;i++)
	    {
	      mac2[i] = new double[M2];
	    }
	  
	  //deklaracja wskaznika do koncawej tablicy
	  double **wyn1;//[NN][NN];
	  
	  
	  
	  //tu wczytujemy macierze do tablic
	  czytanie(file2, mac2, N2, M2);  
	  czytanie(file1, mac1, N1, M1);
	  
	  
	  //obliczamy maciarz koncowa
	  wyn1 =  macierz(mac1, mac2, N1, M1, M2);
	  
	  //wypisanie wynikow
	  wypisz(wyn1, N1, M2);  
	}
      
      else if(strcmp(arg,"-r")==0 || strcmp(arg,"--rownania")==0)
	{
	  //to nasze pliki z macierza i wekrorem:))
	  FILE *file1, *file2;
	  //otwieramy je
	  file1 = fopen(argv[2], "r");
	  file2 = fopen(argv[3], "r");
	  
	  //jesli sie nie uda otwarcie
	  if(!file1)
	    {
	      printf("nie moge otworzyc pliku %s\n", argv[2]);
	      break;
	    }
	  if(!file2)
	    {
	      printf("nie moge otworzyc pliku %s\n", argv[3]);
	      break;
	    } 
	  
	  //tutaj obliczamy rozmiary macierzy w plikach
	  int N1;
	  N1 = wiersze(file1);
	  int M1;
	  M1 = kolumny(file1);
	  int N2;
	  N2 = wiersze(file2);
	  
	  
	  
	  //zobaczmy czy macierze sa dobre:))
	  if(M1!=N2 || N1!=M1)
	    {
	      printf("zle wymiary macierzy!!!\n");
	      break;
	    }
	  
	  //przydzielenie pamieci dla macierzy pierwszej...
	  double **mac1;
	  mac1 = new double*[N1];
	  for(int i=0;i<N1;i++)
	    {
	      mac1[i] = new double[M1];
	    }
	  
	  //i drugiej
	  double *mac2;
	  mac2 = new double[N2];
	  
	  
	  //deklaracja wskaznika do koncawej tablicy
	  double *wyn1;//[NN][NN];	 
	  
	  //tu wczytujemy macierze do tablic
	  czytanie(file1, mac1, N1, M1);  
	  czytanie_wek(file2, mac2, N2);
	  
	  
	  //obliczamy maciarz koncowa
	  wyn1 =  rownanie(mac1, mac2, N1);
	  
	  //wypisanie
	  wypisz_wek(wyn1, N1);

	}
      else if(strcmp(arg,"-rw")==0 || strcmp(arg,"--row_war")==0)
	{
	  //to nasze pliki z macierza i wekrorem:))
	  FILE *file1, *file2;
	  //otwieramy je
	  file1 = fopen(argv[2], "r");
	  file2 = fopen(argv[3], "r");
	  
	  //jesli sie nie uda otwarcie
	  if(!file1)
	    {
	      printf("nie moge otworzyc pliku %s\n", argv[2]);
	      break;
	    }
	  if(!file2)
	    {
	      printf("nie moge otworzyc pliku %s\n", argv[3]);
	      break;
	    } 
	  
	  //tutaj obliczamy rozmiary macierzy w plikach
	  int N1;
	  N1 = wiersze(file1);
	  int M1;
	  M1 = kolumny(file1);
	  int N2;
	  N2 = wiersze(file2);
	  
	  if(N1!=N2 || N1 < M1)
	    {
	      printf("zle wymiary macierzy\n");
	      break;
	    }
	      
	  //przydzielenie pamieci dla macierzy pierwszej...
	  double **mac1;
	  mac1 = new double*[N1];
	  for(int i=0;i<N1;i++)
	    {
	      mac1[i] = new double[M1];
	    }
	  
	  //i drugiej
	  double *mac2;
	  mac2 = new double[N2];
	  
	  //printf("%d\t%d\n",N1, M1);
	  //deklaracja wskaznika do koncawej tablicy
	  double *wyn1;//[NN][NN];	 
	  
	  //tu wczytujemy macierze do tablic
	  czytanie(file1, mac1, N1, M1);  
	  czytanie_wek(file2, mac2, N2);
	  
	  
	  //obliczamy maciarz koncowa
	  wyn1 =  row_war(mac1, mac2, N1, M1);
	  
	  //wypisanie
	  wypisz_wek(wyn1, M1);
	  
	}
      //jesli nie pasuje do wzorca
      else
	argumenty();
      break;
      
      //jesli zero lub wiecej niz cztery
    default:
      argumenty();
    }
  

  return 0;
}










