/*  *** Zadaci za samostalan rad (ZSR 1, Zadatak 6) *** */
#include <iostream>
#include <cmath>

int main ()
{
    double a, b, c;
    std::cout << "Unesite tri realna broja: ";
    std::cin >> a >> b >> c;
    
    if(c == sqrt(a*a+b*b) || a == sqrt(b*b+c*c) || b == sqrt(a*a + c*c))
        std::cout << "Mogu.";
    else std::cout << "Ne mogu.";
	return 0;
}