/*  *** Zadaci za samostalan rad (ZSR 1, Zadatak 8) *** */
#include <iostream>
#include <cmath>

int main ()
{
    int b1, b2, b3, b4, b5, b6;
    std::cout << "Unesite 6 brojeva: ";
    std::cin >> b1 >> b2 >> b3 >> b4 >> b5 >> b6;
    
    int b1n = abs(b1)%2;
    int b2n = abs(b2)%2;
    int b3n = abs(b3)%2;
    int b4n = abs(b4)%2;
    int b5n = abs(b5)%2;
    int b6n = abs(b6)%2;
    
    int broj_neparnih = b1n + b2n + b3n + b4n + b5n + b6n;
    
    if( b1 > 0 && b2 > 0 && b3 > 0 && b4 > 0 && b5 > 0 && b6 > 0){
        std::cout << "Svi brojevi su pozitivni." << std::endl
                  << "Broj neparnih brojeva je " << broj_neparnih << std::endl;
        
    }
    else {
        std::cout << "Svi brojevi nisu pozitivni." << std::endl
                  << "Broj neparnih brojeva je " << broj_neparnih << std::endl;
    }
	return 0;
}