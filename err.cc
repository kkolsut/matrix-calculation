//err.cc
//
//w budowie - moze sie kiedys powiekszy:)
//
//funkcje do obslogi bledow
//
//autor: Krzysztof Kolsut 
//       kolsut@antraes.astrouw.edu.pl
//
//program rozpowszechniany na zasadzie licencji GNU GPL

//wypisywanie komunikatu

#include <stdio.h>
#include "err.h"

void argumenty()
{
  printf("Zla liczba argumentow lub argumenty sa blednie podane\n");
  printf("Sprobuj ./macierz --help lub ./macierz -h aby usyskac wiecej informacji\n");
  
}


void pomoc()
{
  printf("Program wykonuje dzialania na macierzach. Wywolanie:\n");
  printf("./macierz <opcje> [<plik1>] [<plik2>]\n");
  printf("W zalezlosci od opcji program wymaga podania jednej lub dwoch\n");
  printf("nazw plikow ktore zawieraja macierz (format danych opisany w README)");
  printf("\nOpcje:\n");
  printf(" -h,  --help         wyswietla te informacje\n");
  printf(" -v,  --version      wyswietla wersje programu\n");
  printf(" -k,  --kwadrat      podnosi macierz wczytana z \"plik1\" do kwadratu\n");
  printf("                     opcja ta wymaga podania tylko jednego pliku;\n");
  printf(" -o,  --odwroc       odwraca macierz wczytana z \"plik1\",\n");
  printf("                     opcja ta wymaga podania tylko jednego pliku;\n");
  printf(" -w,  --wyznacznik   liczy wyznacznik macierz z \"plik1\",\n");
  printf("                     opcja ta wymaga podania tylko jednego pliku;\n");
  printf(" -m,  --mnozenie     mnozy macierz wczytana z \"plik1\" przez macierz\n");
  printf("                     wczytana z \"plik2\", opcja ta wymaga podania\n");
  printf("                     dwoch plikow;\n");
  printf(" -r,  --rownanie     rozwiazuje uklad rownan, gdzie w \"plik1\"\n");
  printf("                     znajduja sie wspolczynniki przy niewiadomych,\n");
  printf("                     a w \"plik2\" wyrazy wolne, opcja ta wymaga\n");
  printf("                     podania dwoch plikow;\n\n");
  printf(" -rw, --row_war      rozwiazuje uklad rownan warunkowych (tzn jest\n");
  printf("                     wiecej rownan niz niewiadomych), w \"plik1\"\n");
  printf("                     znajduja sie wspolczynniki przy niewiadomych,\n");
  printf("                     a w \"plik2\" wyrazy wolne, opcja ta wymaga\n");
  printf("                     podania dwoch plikow;\n\n");
  printf("autor:  Krzysztof Kolsut\n");
  printf("        kolsut@antares.astrouw.edu.pl\n\n");
  printf("<zglaszanie bladow na w/w adres>\n");

  
}

void wersja()
{
  printf("Wersja 0.6.9-5 beta\n");
}

