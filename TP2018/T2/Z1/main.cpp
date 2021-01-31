//TP 2017/2018: Tutorijal 2, Zadatak 1
#include <iostream>
#include <vector>
#include <cmath>

bool DaLiJeProst (int n){
    if(n < 2) return false;
    for(int i = 2; i <= std::sqrt(n); i++)
        if(n % i == 0)
            return false;
    return true;
    
}

std::vector<int> ProstiBrojeviUOpsegu (int a, int b){
    std::vector<int> prosti;
    if (a < 2) a = 2;
    
    for(int i = a; i <= b && i > 0; i++)
        if(DaLiJeProst(i)) prosti.push_back(i);
    
    return prosti;
}

int main ()
{
    std::vector<int> brojevi;
    int a, b;
    std::cout << "Unesite pocetnu i krajnju vrijednost: ";
    std::cin >> a >> b;
    brojevi = ProstiBrojeviUOpsegu(a,b);
    if(brojevi.size()!=0){
        std::cout << "Prosti brojevi u rasponu od " << a << " do " << b << " su: ";
        for(int i = 0; i < brojevi.size(); i++){
            if(i < (brojevi.size()-1)) std::cout << brojevi[i] << ", ";
            else std::cout << brojevi[i] << std::endl;
        }
    }
    else{
        std::cout << "Nema prostih brojeva u rasponu od " << a << " do " << b << "!";
    }
	return 0;
}
