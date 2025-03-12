#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class rownanie
{
    public:
        rownanie(float a, float b, float c);
        void wczytajWartosci();
        void wypiszRownanie();
        void rozwiazRownanie();

    private:
        float A, B, C;
};

rownanie::rownanie(float a, float b, float c)
{
    A = a; 
    B = b;
    C = c;
}

void rownanie::wczytajWartosci()
{
    cout << "\nPodaj A: ";
    cin >> A;
    cout << "\nPodaj B: ";
    cin >> B;
    cout << "\nPodaj C: ";
    cin >> C;

}

void rownanie::wypiszRownanie()
{
    cout << A << "x^2 + " << B << "x + " << C << endl;
}

void rownanie::rozwiazRownanie()
{
    float delta = B*B-4*A*C;
    if(delta < 0)
    {
        cout << "Delta mniejsza niz 0 --> Brak rozwiazan w dziedzinie liczb R" << endl;

    }
    else if (delta == 0)
    {
        cout << "Delta = 0 --> jedno rozwiazanie x = " << ((-1)*B)/(2*A) << endl;
    }
    else
    {
        cout << "Delta > 0 --> dwa rozwiazania:" << endl;
        cout << " x1 = " << ((-1)*B-sqrt(delta))/(2*A) << endl;
        cout << " x2 = " << ((-1)*B+sqrt(delta))/(2*A) << endl;
    }
    
}

int main(){
    system("cls");

    rownanie r1(2, 3, 4);

    cout << "Postac rownania: ";
    r1.wypiszRownanie();

    r1. wczytajWartosci();
    cout << "Postac rownania: ";
    r1.wypiszRownanie();

    r1.rozwiazRownanie();
    system("pause");
    return 0;
}