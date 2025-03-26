#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <new>  //bad_alloc
using namespace std;

class Tablica
{
    public:
        Tablica();
        Tablica(int rozmiar);
        Tablica(const Tablica &t);
        ~Tablica();
        int get(int index);
        void set(int index, int wartosc);
        void losuj();
        void wypisz();
        float avg();
        float geom();
        int minimum();
        int maksimum();
        void sortuj();
        int mediana();

    private:
        int n;
        int *wsk;
};

Tablica::Tablica()
{
    n=10;
    try
    {
        wsk = new int[n];
    }
    catch (bad_alloc &e)
    {
        cout << "Przydzielenie pamiêci nieudane" << endl;
        cout << e.what() << endl;
        exit(-1);
    }

    for (int i=0; i<n; i++)
    {
        wsk[i]=0;
    }
}

Tablica::Tablica(int rozmiar)
{
    n=rozmiar;
    try
    {
        wsk = new int[n];
    }
    catch (bad_alloc &e)
    {
        cout << "Przydzielenie pamiêci nieudane" << endl;
        cout << e.what() << endl;
        exit(-1);
    }

    for (int i=0; i<n; i++)
    {
        wsk[i]=0;
    }
}

Tablica::Tablica(const Tablica &t)
{
    n = t.n;

    try
    {
        wsk = new int[n];
    }
    catch (bad_alloc &e)
    {
        cout << "Przydzielenie pamiêci nieudane" << endl;
        cout << e.what() << endl;
        exit(-1);
    }

    for (int i=0; i<n; i++)
    {
        wsk[i]=t.wsk[i];
    }
}

Tablica::~Tablica()
{
    delete [] wsk;
}

int Tablica::get(int index)
{
    return wsk[index];
}

void Tablica::set(int index, int wartosc)
{
    wsk[index] = wartosc;
}

void Tablica::losuj()
{
    
    for (int i=0; i<n; i++)
    {
        wsk[i] = (rand()%10)+1;
    }
}

void Tablica::wypisz()
{
    cout<<"Zawartosc tablicy: ";
    for(int i=0; i<n; i++)
    {
        cout << wsk[i] << " | ";
    }
    cout << endl;
}

float Tablica::avg()
{
    float suma=0;
    for(int i=0; i<n; i++)
    {
        suma+=wsk[i];
    }
    return suma/n;
}

float Tablica::geom()
{
    float iloczyn = 1;
    for(int i=0; i<n; i++)
    {
        iloczyn*=wsk[i];
    }
    return pow(iloczyn, 1.0/n);
}

int Tablica::minimum()
{
    int min = wsk[0];
    for (int i = 1; i<n; i++)
    {
        if (wsk[i]<min)
        {
            min = wsk[i];
        }
    }
    return min;
}

int Tablica::maksimum()
{
    int max = wsk[0];
    for (int i = 1; i<n; i++)
    {
        if (wsk[i]>max)
        {
            max = wsk[i];
        }
    }
    return max;
}

void Tablica::sortuj()
{
    int temp=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if (wsk[j]>wsk[j+1])
            {
                temp = wsk[j+1];
                wsk[j+1]=wsk[j];
                wsk[j]=temp;
            }
        }
    }
}

int Tablica::mediana()
{
    this->sortuj();
    if (n%2==1)
    {
        return wsk[(n-1)/2];
    }
    else
    {
        return (wsk[(n+2)/2]+wsk[n/2])/2.0;
    }
    
}
int main(){
    system("cls");
	srand(time(NULL));
    Tablica t1, t2(7);
    cout<<"t1 domyslne: " << endl;
    t1.wypisz();
    cout<<"t1 po losowaniu: " << endl;
    t1.losuj();
    t1.wypisz();
    cout<<"t1 po sortowaniu: " << endl;
    t1.sortuj();
    t1.wypisz();

    cout<<"t2: " << endl;
    t2.losuj();
    t2.sortuj();
    t2.wypisz();
    cout<< "t2 min: " << t2.minimum() << "| max: "<< t2.maksimum() << " | avg: " << t2.avg() << endl;
    cout<< "t2 srednia geometryczna: " << t2.geom() << " | mediana: " << t2.mediana() << endl;
    system("pause");
    return 0;
}
