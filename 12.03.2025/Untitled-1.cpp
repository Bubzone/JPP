#include <iostream>
#include <cstdlib>

using namespace std;

class prostokat
{
	public:
		prostokat();
		prostokat(float s, float w);
		~prostokat();
		float getSzer() {return szer; }
		float getWys(){return wys; }
		void setSzer(float s){ szer = s; }
		void setWys(float w){ wys = w; }	
		float obliczPole();
		float obliczObwod();
	private:
		float szer, wys;
};

prostokat::prostokat()
{
	szer=1; wys=1;
}

prostokat::prostokat(float s, float w)
{
	szer=s; wys=w;
}

prostokat::~prostokat(){
	
}


float prostokat::obliczPole()
{
	return szer*wys;
}

float prostokat::obliczObwod()
{
	return 2*(szer+wys);
}

int main()
{
	system("cls");
	
	prostokat p(2, 3);
	
	p.setSzer(4);
	p.setWys(5);
	cout << "Szerokosc = " << p.getSzer() << endl;
	cout << "Wysokos = " << p.getWys() << endl;
	cout << "Pole = " << p.obliczPole() << endl;
	cout << "Obwod = " << p.obliczObwod() << endl;
	
	system("pause");
	return 0;
}