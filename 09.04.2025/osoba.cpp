#include <iostream>
#include <cstdlib>

using namespace std;

class Osoba
{
    public:
        Osoba(string im, string nazw);
        string getImie();
        string getNazwisko();


    private:
        string imie;
        string nazwisko;
};

Osoba::Osoba(string im, string nazw)
{
    imie = im;
    nazwisko = nazw;
}

string Osoba::getImie()
{
    return imie;
}

string Osoba::getNazwisko()
{
    return nazwisko;
}

class Konto
{
    public:
        Konto(Osoba kl) : klient(kl), saldo(0) { }
        void setSaldo(float kwota);
        float getSaldo();
        friend void wypisz(Konto k);
        friend void wplata(Konto &k, float kwota);
        friend void wyplata(Konto &k, float kwota);
        friend void przelew(Konto &z, Konto &d, float kwota);

    private:
        Osoba klient;
        float saldo;
};


float Konto::getSaldo()
{
    return saldo;
}

void Konto::setSaldo(float kwota)
{
    saldo = kwota;
}

void wypisz(Konto k)
{
    cout << "Wlasciciel: " << k.klient.getImie() << " " << k.klient.getNazwisko() << " | saldo: " << k.saldo << endl;
}

void wplata(Konto &k, float kwota)
{
    k.saldo = k.saldo + kwota;
}

void wyplata(Konto &k, float kwota)
{
    k.saldo = k.saldo - kwota;
}

void przelew(Konto &k, Konto &d, float kwota)
{
    k.saldo = k.saldo - kwota;
    d.saldo = d. saldo + kwota;
}


int main(){
    system("cls");

    Osoba o1("Marek", "Kowal"), o2("Michal", "Paz");

    cout<<"o1: " << o1.getImie() << " " << o1.getNazwisko() << endl;
    cout<<"o2: " << o1.getImie() << " " << o1.getNazwisko() << endl;

    Konto k1(o1), k2(o2);
    cout<<"k1: "<< endl;
    wypisz(k1);
    cout<<"k2: "<< endl;
    wypisz(k2);

    wplata(k1, 1000);
    cout<<"k1: "<< endl;
    wypisz(k1);

    wyplata(k1, 100);
    cout<<"k1: "<< endl;
    wypisz(k1);

    przelew(k1, k2, 200);
    cout<<"k1: "<< endl;
    wypisz(k1);
    cout<<"k2: "<< endl;
    wypisz(k2);

    cout << endl << endl;

    Konto *wsk;
    wsk = new Konto(o1);
    cout<<"k3" << endl;
    wypisz(*wsk);
    wplata(*wsk, 250);
    wypisz(*wsk);
    wyplata(*wsk, 200);
    wypisz(*wsk);
    przelew(*wsk, k2, 50);
    wypisz(*wsk);
    wypisz(k2);

    system("pause");

    return 0;
}
