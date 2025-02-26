#include <iostream>
#include <cstdlib>
using namespace std;

class czlowiek
{
    public:
        czlowiek();
        int getWiek() {return starosc;}
        void setWiek(int wiek) {starosc = wiek;}
    private:
        int starosc;
};

czlowiek::czlowiek()
{
    starosc = 0;
}

int main(){
    system("cls");
    
    int starosc;
    czlowiek jacob;
    cout << "Wiek Jacoba: " << jacob.getWiek() << endl;
    
    cin >> starosc;
    jacob.setWiek(starosc);
    cout << "Wiek Jacoba: " << jacob.getWiek() << endl;
    
    system("pause");
    return 0;
}