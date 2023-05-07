#include <iostream>
#include <fstream>
using namespace std;

bool CzyPierwsza(int k)
{
    int n =2;
    while(n*n<=k)
    {
        if(k%n==0)
        {
            return false;
        }
        n++;
    }
    return true;
}

int main()
{
    int liczba;
    ifstream plik;
    cout << "4.1 "<< endl;
    plik.open("liczby.txt");
    for(int i=0; i<300; i++)
    {
        plik>>liczba;
        if(liczba>=100&&liczba<=5000)
        {
            if(CzyPierwsza(liczba))
            {
                cout << liczba<< endl;
            }
        }
    }

    ifstream plik1;
    cout << "4.2 "<< endl;
    plik1.open("pierwsze.txt");
    string drliczba, kopia;
    for(int j =0; j<200; j++)
    {
        plik1>>drliczba;
        kopia = drliczba;
        for(int k =0; k<drliczba.length(); k++)
        {
            kopia[k] = drliczba[drliczba.length()-1-k];
        }
        int number =0;
        for(int o =0; o<kopia.length(); o++)
        {
            number = number *10 + (kopia[o]- '0');
        }
        if(CzyPierwsza(number))
        {
            cout << drliczba << endl;
        }
    }
    ifstream plik2;
    int liczbanow, nowa = 0, kop =0, sum;
    string liczjaka;
    plik2.open("pierwsze.txt");
    for(int i =0; i<200; i++)
    {
        nowa = 0;
        plik2>>liczbanow;

        while(liczbanow>0)
        {
            nowa =nowa + liczbanow%10;
            liczbanow= liczbanow/10;

        }
        while (nowa>=10)
        {
            sum =0;
            while (nowa>0)
            {
                sum = sum + nowa%10;
                nowa= nowa/10;
            }
        nowa = sum;
        }

        if (nowa ==1 )
        {
            kop++;
        }
    }
    cout <<"4.3 " <<kop << endl;
}

