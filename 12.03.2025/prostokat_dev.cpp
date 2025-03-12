#include <iostream>
#include <cstdlib>
using namespace std;

class prostokat
{
    public:
        prostokat();
        prostokat(float x, float y);
        ~prostokat() {cout << "Zniszczono obiekt" << endl;}
        float getSzer() {return szer;}
        float getWys() {return wys;}
        void setSzer(int x) {szer = x;}
        void setWys(int y) {wys = y;}
        
        float obliczPole();
        float obliczObwod();

    private:
        float szer, wys;
};

prostokat::prostokat()
{
    szer = 1;
    wys = 1;
    cout << "Utworzono obiekt konstruktorem bezargumentowym" << endl;
}

prostokat::prostokat(float x, float y)
{
    szer = x; 
    wys = y;
    cout << "Utworzono obiekt konstruktorem z argumentami" << endl;
}

float prostokat::obliczPole()
{
    return szer*wys;
}

float prostokat::obliczObwod()
{
    return 2*szer+2*wys;
}

int main(){
    system("cls");

    prostokat p1(2, 3);
    prostokat p2;
    prostokat *wsk = new prostokat(3, 4);

    cout << "P1(arg)  |   szerokosc: " << p1.getSzer() << " | wysokosc:  " << p1.getWys() << endl;
    cout << "pole: " << p1.obliczPole() << endl;
    cout << "obwod: " << p1.obliczObwod() << endl;
    
    cout << "P2(bez arg) |   szerokosc: " << p2.getSzer() << " | wysokosc:  " << p2.getWys() << endl;
    cout << "pole: " << p2.obliczPole() << endl;
    cout << "obwod: " << p2.obliczObwod() << endl;
    
    cout << "P3(dynamiczny)  |   szerokosc: " << wsk->getSzer() << " | wysokosc:  " << wsk->getWys() << endl;
    cout << "pole: " << wsk->obliczPole() << endl;
    cout << "obwod: " << wsk->obliczObwod() << endl;
    
    p2.prostokat::~prostokat();
    delete wsk;
    system("pause");
    return 0;
}
