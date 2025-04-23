#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 3;

class Macierz
{
    public:
        Macierz();
        Macierz(int tab[N][N]);
        int get(int i, int j);
        void set(int i, int j, int wartosc);
		void losuj();
		void wypisz();
		Macierz operator+(Macierz m);
		Macierz operator-(Macierz m);
		Macierz operator*(Macierz m);
		Macierz operator*(int a);
		Macierz operator~();

		friend ostream& operator<<(ostream &os, Macierz m);
		friend istream& operator<<(istream &is, Macierz m);
		
		int& operator() (int w, int k) { return mac[w][k];}

    private:
        int mac[N][N];
};

Macierz::Macierz()
{
    for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < N; j++)
	    {
	    	mac[i][j] = 0;
		}	
	}
}

Macierz::Macierz(int tab[N][N])
{
    for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < N; j++)
	    {
	    	mac[i][j] = tab[i][j];
		}	
	}
}

int Macierz::get(int i, int j)
{
    return mac[i][j];
}

void Macierz::set(int i, int j, int wartosc)
{
    mac[i][j] = wartosc;
}

void Macierz::losuj()
{
	
	
    for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < N; j++)
	    {
	    	mac[i][j] = rand() % 40 - 20;
		}	
	}
}
void Macierz::wypisz()
{
	cout << "Zawartosc macierzy: " << endl;
	
    for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < N; j++)
	    {
	    	cout << mac[i][j] << " ";
		}	
		cout << endl;
	}
}

Macierz Macierz::operator+(Macierz m)
{
	Macierz m3;
	for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < N; j++)
	    {
	    	m3.set(i,j, mac[i][j] + m.get(i, j));
		}	
	}
	return m3;
}

Macierz Macierz::operator-(Macierz m)
{
	Macierz m3;
	for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < N; j++)
	    {
	    	m3.set(i,j, mac[i][j] - m.get(i, j));
		}	
	}
	return m3;
}

Macierz Macierz::operator*(Macierz m)
{
	Macierz m3;
	for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < N; j++)
	    {
	    	m3.set(i,j, mac[i][j] * m.get(i, j));
		}	
	}
	return m3;
}

Macierz Macierz::operator*(int a)
{
	Macierz m3;
	for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < N; j++)
	    {
	    	m3.set(i,j, mac[i][j] * a);
		}	
	}
	return m3;
}
Macierz Macierz::operator~()
{
	Macierz m3;
	for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < N; j++)
	    {
	    	m3.set(j,i, mac[i][j]);
		}	
	}
	return m3;
}

ostream& operator<<(ostream &os, Macierz m)
{
	os << "Zawartosc macierzy: " << endl;
	
    for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < N; j++)
	    {
	    	os << m.get(i,j) << " ";
		}	
		os << endl;
	}
}

istream& operator>>(istream &is, Macierz &m)
{
	int val;
    for(int i = 0; i < N; i++)
    {
    	for(int j = 0; j < N; j++)
	    {
	    	is >> val;
			m.set(i, j, val);
		}	
	}
}
int main(){
    system("cls");
	srand(time(NULL));
	
	Macierz m1;
	m1.losuj();
    m1.wypisz();
    Macierz m2;
	m2.losuj();
	m2.losuj();
    m2.wypisz();

	Macierz m3;
	m3 = m1+m2;
	m3.wypisz();

	m3 = m1-m2;
	m3.wypisz();

	m3 = m1*m2;
	m3.wypisz();
	m3 = m1*2;
	m3.wypisz();

	m3 = ~m1;
	cout << m3;

	cin >> m3;
	cout << m3;
	
	m3(0,0) = 5;
	int x = m3(0, 0);
	cout << "x = " << x << endl;
    system("pause");

    return 0;
}
