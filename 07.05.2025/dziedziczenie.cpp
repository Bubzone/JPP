#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 3;

class Bryla
{
    public:
        Bryla(double rr, double hh) : r(rr), h(hh) { }
        ~Bryla() {cout << "Destruktor klasy bryla" << endl;}
        virtual void wypiszInfo();
        
    protected:
        double r;
        double h;
        static const double PI;
};

const double Bryla::PI = 3.14;

void Bryla::wypiszInfo()
{
    cout << "Promien: " << r << " | wysokosc: " << h << endl;
}

class Walec : public Bryla
{
    public: 
        Walec(double rr, double hh) : Bryla(rr, hh) { }
        ~Walec() {cout << "Destruktor klasy walec" << endl;}
        void wypiszInfo();
        double ObliczObj() {return PI*r*r*h;}
};
void Walec::wypiszInfo()
{
	cout << "Walec: " << endl;
	Bryla::wypiszInfo();
}


class Stozek : public Bryla
{
    public:
        Stozek(double rr, double hh) : Bryla(rr, hh) { }
        ~Stozek() {cout << "Destruktor klasy stozek" << endl;}
        double ObliczObj() {return (PI*r*r*h)*(1.00/3.00);}
        void wypiszInfo();
};
void Stozek::wypiszInfo()
{
	cout << "Stozek: " << endl;
	Bryla::wypiszInfo();
}


class StozekSciety : public Stozek
{
    public:
        StozekSciety(double rr, double hh, double RR): Stozek(rr, hh) {R = RR;}
    	~StozekSciety() {cout << "Destruktor klasy stozekSciety" << endl;}
    	double ObliczObj() {return ((r*r)+(r*R)+(R*R))*h*PI*(1.00/3.00);}
        void wypiszInfo();
	private:
        double R;
};

void StozekSciety::wypiszInfo()
{
	cout << "Stozek: " << endl;
	cout << "promien scietej czesci: " << R << " | ";
	Bryla::wypiszInfo();
}

int main(){
    system("cls");
    Walec w1(4, 3);
    w1.wypiszInfo();
    cout << "Objetosc: " << w1.ObliczObj() << endl;
    Stozek s1(2, 1);
    s1.wypiszInfo();
    cout << "Objetosc: " << s1.ObliczObj() << endl;
    StozekSciety s2(5, 4, 2);
    s2.wypiszInfo();
    cout << "Objetosc: " << s2.ObliczObj() << endl;
    system("pause");

    return 0;
}
