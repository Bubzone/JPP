#include <iostream>
#include <cstdlib>
using namespace std;

class kula
{
    public:
        kula(float promien) {r = promien;}

        int getPromien() {return r;}
        void setPromien(int promien) {r = promien;}
        
        float obliczPole();
        float obliczObj();
    private:
        int r;
};

float kula::obliczPole()
{
    return 4*3.14*r*r;
}

float kula::obliczObj()
{
    return (4/3.0)*(r*r*r);
}

int main(){
    system("cls");
    
    int promien;
    kula k1(1);
    //cout << "Podaj pole kuli" << endl;
    //cin >> promien;
    //k1.setPromien(promien);
    cout << "promien: " << k1.getPromien() << endl;
    cout << "pole: " << k1.obliczPole() << endl;
    cout << "objetosc: " << k1.obliczObj() << endl;
    system("pause");
    return 0;
}