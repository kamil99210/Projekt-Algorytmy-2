#include <iostream>
#include <iomanip>
#include <time.h>
#include <chrono>
#include <fstream>
using namespace std;

int sortowanie_kubelkowe(int  MAX,int  MIN,int  N)
{
    auto startA = chrono::steady_clock::now();      //<-- zaczęcia liczenia czasu

int  d[N],lw[MAX - MIN + 1],i,j;


srand((unsigned)time(NULL));
cout<<"\n1 sortowanie - sortowanie kubelkowe"<<endl;
  for(i = 0; i < N; i++)
    d[i] = MIN + rand() % (MAX - MIN + 1);

// wyswietlamy zawartosc zbioru przed sortowaniem

  cout <<"\nliczby przed sortowaniem:\n";
  for(i = 0; i < N; i++)cout << setw(4) << d[i];
  cout << endl;

// najpierw zerujemy liczniki

 for(i = MIN; i <= MAX; i++) lw[i - MIN] = 0;

// zliczamy w odpowiednich licznikach wystapienia
// wartosci elementów sortowanego zbioru

  for(i = 0; i < N; i++) lw[d[i] - MIN]++;

// zapisujemy do zbioru wynikowego numery niezerowych liczników
// tyle razy, ile wynosi ich zawartoœæ

  j = 0;
  for(i = MIN; i <= MAX; i++) while(lw[i - MIN]--) d[j++] = i;

// wyswietlamy zawartosc zbioru po sortowaniu

    fstream wyn1;
    wyn1.open("wyn1.txt");
  cout << "Po sortowaniu:\n";
  for(i = 0; i < N; i++) {cout << setw(4) << d[i];}

   auto stopA = chrono::steady_clock::now();     //< -- stop zegara
    auto durationA = stopA - startA;                //<-- roznica czasów miedzy start i stop
    auto duration_microseconds = chrono::duration_cast<std::chrono::microseconds> (durationA).count();      //< --konwersja różnicy czasu na mikro sekundy
    cout << endl <<"__________________"<<endl<< "Czas wykonania algorytmu w mikrosekundach: " << endl << duration_microseconds << endl;  // <-- wypisanie czasu w mikro sakundach
     wyn1<<endl<<"Czas trwania algorytmu w mikrosekudnach: "<<duration_microseconds;
    wyn1.close();
    return 0;
}

int sorto_wybor(int MAX,int MIN,int N)
{

    auto startA = chrono::steady_clock::now();      //<-- zaczęcia liczenia czasu

    int d[N],i,j,pmin;
cout<<endl<<endl<<endl<<endl;
cout<<"Teraz 2 sortowanie - sortowanie przez wybieranie \n\n";
// losowanie i wyswietlanie zawartosci

  srand((unsigned)time(NULL));
  for(i = 0; i < N; i++) d[i] = MIN + rand() % (MAX - MIN + 1);
  for(i = 0; i < N; i++) cout << setw(4) << d[i];
  cout << endl;
// Sortowanie
  for(j = 0; j < N - 1; j++)
  {
    pmin = j;
    for(i = j + 1; i < N; i++)
      if(d[i] < d[pmin]) pmin = i;
    swap(d[pmin], d[j]);
  }

    fstream wyn2;
    wyn2.open("wyn2.txt");

// Wyswietlanie wyniku
  cout << "Po sortowaniu:\n\n";
  for(i = 0; i < N; i++) {cout << setw(4) << d[i];}
  cout << endl;


   auto stopA = chrono::steady_clock::now();     //< -- stop zegara
    auto durationA = stopA - startA;                //<-- roznica czasów miedzy start i stop
    auto duration_microseconds = chrono::duration_cast<std::chrono::microseconds> (durationA).count();      //< --konwersja różnicy czasu na mikro sekundy
    cout << endl <<"__________________"<<endl<< "Czas wykonania algorytmu w mikrosekundach: " << endl << duration_microseconds << endl;  // <-- wypisanie czasu w mikro sakundach
    wyn2<<endl<<"Czas trwania algorytmu w mikrosekudnach: "<<duration_microseconds;
    wyn2.close();
    return 0;


}
int main()
{

  int  MIN,MAX,N;
  cout<<"Podaj poczatek zakresu\n";cin>>MIN;
  cout<<"Podaj koniec zakrsu\n";cin>>MAX;
  cout<<"Podaj ilosc liczb do posortowania\n";cin>>N;

    sortowanie_kubelkowe(MAX,MIN,N);
    sorto_wybor(MAX,MIN,N);

  return 0;
}
