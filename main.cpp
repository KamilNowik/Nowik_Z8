#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;

const int n=5;

void wypelnianie_tablicy(int T[][n],int dol, int gora)
{
    srand(time(0));

    for(int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            T[i][j]=dol+rand()%(gora+1-dol);
        }
    }
}

void drukowanie_tablicy(string nazwa, int T[][n])
{
    cout <<nazwa<<endl<<endl;

    for(int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << setw(5)<<T[i][j];
        }
        cout<<endl<<endl;
    }

}

int Zamiany_i_zwroty(int T[][n], int dzielnik)
{
    int najmniejszy_przek, licznik=0, koordynat=0;

   najmniejszy_przek=T[0][0];

    for(int i=1; i<n; i++)
    {
        if(T[i][i]<najmniejszy_przek)
        {
            najmniejszy_przek=T[i][i];
            koordynat=i;
        }
    }

    for(int i=0; i<n; i++)
    {
        if(T[0][i]%dzielnik==0)
        {
            licznik++;
        }

        if(T[n-1][i]%dzielnik==0)
        {
            licznik++;
        }
    }

    for(int i=1; i<n-1;i++)
    {
        if(T[i][0]%dzielnik==0)
        {
            licznik++;
        }
        if(T[i][n-1]%dzielnik==0)
        {
            licznik++;
        }
    }

    T[koordynat][koordynat]=licznik;


    return licznik;

}

int main()
{

    int B1=30, B2=60, A[n][n], B[n][n];

    wypelnianie_tablicy(A, 0, 30);
    wypelnianie_tablicy(B, B1, B2);

    drukowanie_tablicy("Tablica A",A);
    drukowanie_tablicy("Tablica B",B);

    Zamiany_i_zwroty(A,3);
    Zamiany_i_zwroty(B,2);

    drukowanie_tablicy("Tablica A",A);
    drukowanie_tablicy("Tablica B",B);

    cout<< "Roznica w tak wyznaczonych elementach wynosi: "<< Zamiany_i_zwroty(A,3)- Zamiany_i_zwroty(B,2)<<endl;

    return 0;
}
