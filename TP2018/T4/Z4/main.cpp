//TP 2018/2019: Tutorijal 4, Zadatak 4
#include <iostream>
#include <string>

template <typename Nesto>
    void UnosBroja (std::string s1, std::string s2, Nesto &broj){
        Nesto br;
        do{
            std::cout << s1 << std::endl;
            std::cin >> br;
            if(!std::cin || std::cin.peek() != '\n'){
                std::cout << s2 << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }while(!std::cin || std::cin.peek() != '\n');
        broj = br;
    }

int main ()
{
    double x;
    int n;
    UnosBroja("Unesite bazu: ", "Neispravan unos, pokusajte ponovo...", x);
    UnosBroja("Unesite cjelobrojni eksponent: ", "Neispravan unos, pokusajte ponovo...", n);
    double rezultat = 1;
    for(int i = 0; i < abs(n); i++){
        rezultat *= x;
    }
    if(n < 0){
        rezultat = 1/rezultat;
    }
    std::cout << x << " na " << n << " iznosi " << rezultat;
	return 0;
}