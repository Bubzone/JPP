#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class uklad
{
    public:
        uklad(float a, float b, float c, float d, float e, float f);
        void wczytajWartosci();
        void wypiszUklad();
        void rozwiazUklad();

    private:
        float A, B, C, D, E, F;
};

uklad::uklad(float a, float b, float c, float d, float e, float f)
{
    A = a; 
    B = b;
    C = c;
    D = d;
    E = e;
    F = f;
}

void uklad::wczytajWartosci()
{
    cout << "\nPodaj A: ";
    cin >> A;
    cout << "\nPodaj B: ";
    cin >> B;
    cout << "\nPodaj C: ";
    cin >> C;
    cout << "\nPodaj D: ";
    cin >> D;
    cout << "\nPodaj E: ";
    cin >> E;
    cout << "\nPodaj F: ";
    cin >> F;

}

void uklad::wypiszUklad()
{
    cout << A << "x + " << B << "y = " << C << endl;
    cout << D << "x + " << E << "y = " << F << endl;
}

void uklad::rozwiazUklad()
{
    float W, Wx, Wy;
    W = A * E - B * D;
    Wx = B * F - C * E;
    Wy =  A * F - C * D;
    if (W == 0)
    {
        if (Wx == 0 && Wy == 0)
        {
            cout << "Uklad rownan nieoznaczony" << endl;
        }
        else
        {
            cout << "Uklad rownan sprzeczny" << endl;
        }
    }
    else
    {
        cout << "\n\nRozwiazanie rownania:\nx = " << Wx/W << "\ny = " << Wy/W << endl;
    }
}

int main(){
    system("cls");

    uklad u1(2, 3, 4, 5, 6, 7);

    cout << "Postac rownania: ";
    u1.wypiszUklad();

    u1. wczytajWartosci();
    cout << "Postac rownania: " << endl;
    u1.wypiszUklad();

    u1.rozwiazUklad();
    system("pause");
    return 0;
}