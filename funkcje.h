//funkcje.h
//
//funkcje mnozace macierze i podnoszacy je do kwadratu...
//
//autor: Krzysztof Kolsut 
//       kolsut@antraes.astrouw.edu.pl
//
//program rozpowszechniany na zasadzie licencji GNU GPLzaca maciarze

double **macierz(double **mac1, double **mac2, int N, int M1, int M2);

//funkcja podnoszaca macierz do kwadratu  
double **macierz_kwad(double **mac, int N, int M);

//funkcja realizujaca rozklad LU (mam nadzieje:)))
double **LU(double **tab, int N);

//funkcja odwracajaca macierz
double **odwroc(double **tab,  int N);

//liczaca y przy roakladzie LU
double *oblicz_y(double **tab, double *b, int N);

//liczaca x przy roakladzie LU
double *oblicz_x(double **tab, double *b, int N);

//funkcja rozwiazujaca uklad rownan
double *rownanie(double **tab, double *wek, int N);

//funkcja liczaca wyznacznik
double wyznacznik(double **tab, int N);

//funkcja obliczajaca rownania warunkowe
double *row_war(double **tab, double *wek, int N, int M);

double *mac_wekt(double **tab, double *wek, int N, int M);
