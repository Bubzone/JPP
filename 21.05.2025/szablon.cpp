#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <new>  //bad_alloc
using namespace std;

template <typename T> class Tablica
{
    public:
        Tablica();
        Tablica(int rozmiar);
        Tablica(const Tablica<T> &t); // konstruktor kopiujacy
        ~Tablica();
        T get(int index);
        void set(int index, T wartosc);
        void wypisz();
        T minimum();
        T maksimum();
        
        friend ostream& operator<<(ostream &os, Tablica<T> t); // nie dziala
		friend istream& operator>>(istream &is, Tablica<T> t); // to tez
		int getn() {return n;}
  
		T& operator [] (int i);
		
    private:
        int n;
        T* wsk;
};

template <typename T> Tablica<T>::Tablica()
{
    n=10;
    try
    {
        wsk = new T[n];
    }
    catch (bad_alloc &e)
    {
        cout << "Przydzielenie pamiêci nieudane" << endl;
        cout << e.what() << endl;
        exit(-1);
    }
}

template <typename T> Tablica<T>::Tablica(int rozmiar)
{
    n=rozmiar;
    try
    {
        wsk = new T[n];
    }
    catch (bad_alloc &e)
    {
        cout << "Przydzielenie pamiêci nieudane" << endl;
        cout << e.what() << endl;
        exit(-1);
    }
}

template <typename T> Tablica<T>::Tablica(const Tablica &t)
{
    n = t.n;

    try
    {
        wsk = new T[n];
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

template <typename T> Tablica<T>::~Tablica()
{
    delete [] wsk;
}

template <typename T> T Tablica<T>::get(int index)
{
    return wsk[index];
}

template <typename T> void Tablica<T>::set(int index, T wartosc)
{
    wsk[index] = wartosc;
}
template <typename T> T& Tablica<T>::operator [] (int i)
{
	return wsk[i];
}
template <typename T> void Tablica<T>::wypisz()
{
    cout<<"Zawartosc tablicy: ";
    for(int i=0; i<n; i++)
    {
        cout << wsk[i] << " | ";
    }
    cout << endl;
}

template <typename T> T Tablica<T>::minimum()
{
    T min = wsk[0];
    for (int i = 1; i<n; i++)
    {
        if (wsk[i]<min)
        {
            min = wsk[i];
        }
    }
    return min;
}

template <typename T> T Tablica<T>::maksimum()
{
    T max = wsk[0];
    for (int i = 1; i<n; i++)
    {
        if (wsk[i]>max)
        {
            max = wsk[i];
        }
    }
    return max;
}


/*
void Tablica::losuj()
{
    
    for (int i=0; i<n; i++)
    {
        wsk[i] = (rand()%10)+1;
    }
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
*/
template <typename T> ostream& operator<<(ostream &os, Tablica<T> t)
{
	os << "Zawartosc tablicy: " << endl;
	
    for(int i = 0; i < t.getn(); i++)
    {
	    os << t.get(i) << " ";
	}
	os << endl;
}

template <typename T> istream& operator>>(istream &is, Tablica<T> &t)
{
	int val;
    for(int i = 0; i < t.getn(); i++)
    {
	    is >> val;
		t.set(i, val);
	}
}

int main(){
    system("cls");
    Tablica <int>t1;
    cout<<"t1 domyslne: " << endl;
    t1.set(1, 5);
    t1.wypisz();
    int x = t1[1];
    t1[1] = 9;
    cout << "X: " << x << "| T1: " << t1.get(1) << endl;
    t1[4] = -1000;
    cout << "min: " << t1.minimum() << "| max: " << t1.maksimum() << endl;
    
    Tablica <char>t2;
    t2[2] = 'a';
    t2[1] = 'b';
    t2[0] = 'z';
    t2[3] = 'z';
    t2[4] = 'z';
    t2[5] = 'z';
    t2[6] = 'z';
    t2[7] = 'z';
    t2[8] = 'z';
    t2[9] = 'z';
    t2.wypisz();
    cout << "min: " << t2.minimum() << "| max: " << t2.maksimum() << endl;
    //cin >> t2;
    //cout << t2;
	//cin >> t1;
	//cout << t1;
    /*cout<<"t2: " << endl;
    t2.losuj();
    t2.sortuj();
    t2.wypisz();
    cout<< "t2 min: " << t2.minimum() << "| max: "<< t2.maksimum() << " | avg: " << t2.avg() << endl;
    cout<< "t2 srednia geometryczna: " << t2.geom() << " | mediana: " << t2.mediana() << endl;
    */
	system("pause");
    return 0;
}
