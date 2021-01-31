/*  *** Zadaci za samostalan rad (ZSR 1, Zadatak 2) *** */
#include <iostream>

int main ()
{
    const int morska = 1852;
    int bc;
    std::cout << "Unesite brzinu broda u cvorovima: ";
    std::cin >> bc;
    double bkm = double(morska)/1000 * bc;
    
    std::cout << "Brzina broda je " << bkm << " km/h.";
    
	return 0;
}