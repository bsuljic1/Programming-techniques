//TP 2016/2017: Tutorijal 1, Zadatak 4
#include <iostream>
#include <cmath>

int main ()
{
    for(;;){
        double n;
        int suma = 0;
        std::cout << "\nUnesite prirodan broj ili 0 za kraj: ";
        std::cin >> n;
        
        if (n < 0){
            std::cout << "Niste unijeli prirodan broj!";
            continue;
        }
        
        if(int(n)!=n){
            std::cout << "Niste unijeli prirodan broj!";
            continue;
        }
        
        if(std::cin){
            if (n == 0.f) {
            std::cout << "Dovidjenja!";
            return 0;
        }
        for(int i = 1; i < n; i++)
            if (int(n)%i==0) suma += i;
    
        if (suma == n){
            std::cout << "Broj " << n << " je savrsen!";
        }
        else if (suma < n){
            std::cout << "Broj " << n << " je manjkav!";
        }
        else{
            std::cout << "Broj " << n << " je obilan!";
        }
        }
        else{
            std::cout << "Niste unijeli prirodan broj!";
        }
        
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
	return 0;
}