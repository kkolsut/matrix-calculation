//funkcje.cc
//
//funkcje mnozace macierze, oraz podnoszace je do kwadratu
//
//autor: Krzysztof Kolsut 
//       kolsut@antraes.astrouw.edu.pl
//
//program rozpowszechniany na zasadzie licencji GNU GPL

#include <stdio.h>
#include "funkcje.h"



//funkcja mnozaca maciarze
double **macierz(double **mac1, double **mac2, int N, int M1, int M2)
{
  //mac1 - pierwsza maciarz; mac2 - druga
  //M1 -liczba kolumn w pierwszej i wierszy w drugiej maciarzy
  //N - liczba kolumn w pierszwj
  //M2 liczba kolumn w drugiej

  //alokacja pamieci na wynik
  double **wynik;
  wynik = new double*[N];
  for(int i=0;i<N;i++)
    wynik[i] = new double[M2];
  
  //zerowanie tablicy
  for(int i = 0; i < N; i++)
    for(int j=0; j < M2; j++)
      wynik[i][j]=0;

  //pomocnicza tablica, aby nie gmatwac kodu
  double *kol;
  kol = new double[M1];
  
  //zerowanie tablicy
  for(int i = 0; i < M1; i++)
    kol[i] = 0;


  //trzy petelki mnozace macierze:))
  for(int i=0;i<N;i++)
    {
      for(int n=0;n<M2;n++)
	{
	  for(int j=0;j<M1;j++)
	    {
	      kol[n]=mac1[i][j]*mac2[j][n];
	      wynik[i][n]=wynik[i][n]+kol[n];
	    }
	}
    }
  //zwalniamy pamiec
  delete [] kol;

  //zwracamy wynik:)))
  return wynik;
}

//funkcja podnoszaca macierz do kwadratu  
double **macierz_kwad(double **mac, int N, int M)
{
  //mac - pierwsza maciarz
  //N - liczba kolumn
  //M liczba wierszy

  //alokacja pamieci na wynik
  double **wynik;
  wynik = new double*[N];
  for(int i=0;i<N;i++)
    wynik[i] = new double[N];
  
  for(int i =0; i<N;i++)
    for(int j=0; j<N;j++)
      wynik[i][j]=0.0;
  
  //pomocnicza tablica, aby nie gmatwac kodu
  double *kol;
  kol = new double[N];
  
  //zerowanie tablicy
  for(int i = 0; i < N; i++)
    kol[i] = 0;


  //trzy petelki mnozace macierze:))
  for(int i=0;i<N;i++)
    {
      for(int n=0;n<N;n++)
	{
	  for(int j=0;j<M;j++)
	    {
	      kol[n]=mac[j][i]*mac[j][n];
	    
	      wynik[i][n]=wynik[i][n]+kol[n];
	      // printf("%g \t %g \t %d\n", wynik[i][n],kol[n], n);
	    }
	}
    }
  //zwalniamy pamiec
  delete [] kol;

  //zwracamy wynik:)))
  return wynik;
}

//funkcja realizujaca rozklad LU (mam nadzieje:)))
double **LU(double **tab, int N)
{
 //tablica na wynik
  double **wynik;
  wynik = new double*[N];
  for(int i=0; i < N; i++)
    wynik[i] = new double[N];
  
  //przepisujemy tablice aby nie mazac po wejsciowej
  for(int i = 0; i < N; i++)
    for(int n = 0; n < N; n++)
      wynik[i][n] = tab[i][n];
  
  //dwie pomocnicze zmienne
  double pomoc_1, pomoc_2;
  
  //pierwsza penteka
  for(int i =0; i < N; i++)
    {
      //druga pierwsza...na U
      for(int n = 0; n <= i; n++)
	{
	  //zerujemy zmienna pomocnicza
	  pomoc_1 = 0;
	  
	  //i trzecia petla
	  for(int j = 0; j < n ; j++)
	  {
	    if(n==j)
	      pomoc_1 = pomoc_1 + wynik[j][i];
	    else
	      pomoc_1 = pomoc_1 + wynik[n][j]*wynik[j][i];
	    }
	  
	  //przypisyjemy wynik
	  wynik[n][i] = wynik[n][i] - pomoc_1;
	}

      //druga druga...a L
      for(int n = i + 1; n < N; n++)
	{
	  //zerujemy zmienna pmocnicza
	  pomoc_2 = 0;
	  
	  //trzecia petla
	  for(int j =0; j < i  ; j++)
	    {
	      //na diagonalii sa '1'
	      if(n==j)
		pomoc_2 = pomoc_2 + wynik[j][i];
	      else
		pomoc_2 = pomoc_2 + wynik[n][j]*wynik[j][i];    
	    } 
	  //aby nie mazac po diagonalii (sa tu wartosci U)
	  if(n!=i)
	  wynik[n][i] = (wynik[n][i] - pomoc_2) / wynik[i][i];
	 
	}
    }

  //zwracamy wynik
  return wynik;

}

//funkcja raelizyjaca odwracanie macierzy
double **odwroc(double **tab, int N)
{
  //pomocnicze wektory
  double *wek_x, *wek_y, *wek_jed;
  
  //dwie tablice jedna na wynik druga na rozklad LU
  double **lu, **wynik;
  wynik = new double*[N];
  for(int i =0; i < N; i++)
    wynik[i] = new double[N];
  wek_jed = new double[N];
  
  //obliczamy rozkal LU
  lu = LU(tab, N);
  
//pentelka liczaca
  for(int i = 0; i < N; i++)
    {
      //robimy wektor z 1 na odpowiednim miejscu
      for(int n = 0; n < N; n++)
	if(n==i)
	  wek_jed[n] = 1;
	else
	  wek_jed[n] = 0;
     
      //znajdujemy wektory y i x
      wek_y = oblicz_y(lu, wek_jed, N);
      wek_x = oblicz_x(lu, wek_y, N);
      
      //przypisujemy wektor do odpowiedniej kolumny w macierzy
      for(int n =0; n < N; n++)
	wynik[n][i] = wek_x[n];
    }
      
  return wynik;
}

//obliczanie wektora y dla LU
double *oblicz_y(double **tab, double *b, int N)
{
  //tablica na wynik
  double *wynik;
  wynik = new double[N];
  
  //zerujemy tablice
  for(int i = 0; i < N; i++)
    wynik[i] = b[i];
  
  //obliczamy wektor
  for(int i=0; i < N; i++)
    {
     
      for(int n = i-1 ; n >= 0 ; n--)
	{
	  //warunek bo na diagonalii nie ma jedynek:)
	  if(i!=n)
	    wynik[i]=wynik[i]-wynik[n]*(tab[i][n]);
	  else
	    wynik[i]=wynik[i]-wynik[n];
	}
     
    }
  //zwracamy wynik
  return wynik;
}

//obliczanie wekrora x dla LU
double *oblicz_x(double **tab, double *wek, int N)
{
  //tablica na wynik
  double *wynik;
  wynik = new double[N];
  
  //przypisanie wektowa do wyniku
  for(int i = 0; i < N; i++)
    wynik[i] = wek[i];
  
  //pierwszy element
  wynik[N-1] = wek[N-1]/tab[N-1][N-1];
  
  //zmienna pomocnicza
  double pomoc;

  //pentelka liczaca wektor
  for(int i =N-2; i >= 0; i--)
    {
      pomoc = 0;
      for(int j = i+1; j < N; j++)
	pomoc = pomoc + tab[i][j]*wynik[j]; 
	
      wynik[i] = (wek[i] - pomoc)/tab[i][i];
      
    }
  //zwracamy wynik
  return wynik;
}

//rozwiazanie ukladu rownan
double *rownanie(double **tab, double *wek, int N)
{
  //miejsce na wynik i wektor pomocniczy
  double *wynik, *y;

  //miejsce na rozrlad LU
  double **lu;
  lu = new double*[N];
  for(int i = 0; i < N; i++)
    lu[i] = new double[N];

  //obliczamy LU
  lu = LU(tab, N);
  
  //i liczymy wektory
  y = oblicz_y(lu, wek, N);
  wynik = oblicz_x(lu, y, N);
  
  //zwracamy wynik
  return wynik;
}

double wyznacznik(double **tab, int N)
{
  //miejsce na macierz LU
  double **lu;
  
  //liczymy LU
  lu = LU(tab, N);
  double wynik=1;
  //liczymy wyznacznik
  for(int i =0; i < N; i++)
    wynik = wynik * lu[i][i];
  
  return wynik;
}

//fnukcja mnozaca macierz transponowana i wektor
double *mac_wekt(double **tab, double *wek, int N, int M)
{
  double *wynik;
  wynik = new double[M];
  
  for(int i = 0; i < M; i++)
    { wynik[i] = 0;
      for(int n = 0; n < N; n++)
	wynik[i] = wynik[i] + tab[n][i]*wek[n];
    }
  
  return wynik;
}


//funkcja obliczajaca rownania warunkowe
double *row_war(double **tab, double *wek, int N, int M)
{
  //N wiersze kolumn; M kolumny wierszy
  double **kwad;
  double *wek_pom, *wynik;;
  
  kwad = macierz_kwad(tab, M, N);

  wek_pom = mac_wekt(tab, wek, N, M);

  wynik = rownanie(kwad, wek_pom, M);

  return wynik;
}












