/*  *** Zadaci za samostalan rad (ZSR 1, Zadatak 3) *** */
#include <iostream>

int main ()
{
    double a;
    std::cout << "Unesite neki podatak: ";
    std::cin >> a;
    
    if(std::cin){
        if(a == int(a)) {
            if (a > 0.f) std::cout << "Uneseni podatak je prirodan broj.";
            else std::cout << "Uneseni podatak je cijeli broj, ali nije prirodan.";
        }
        else std::cout << "Uneseni podatak je realan broj, ali nije cijeli.";
    }
    
    else std::cout << "Uneseni podatak nije broj.";
	return 0;
}