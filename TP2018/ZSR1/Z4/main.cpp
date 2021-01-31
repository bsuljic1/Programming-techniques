/*  *** Zadaci za samostalan rad (ZSR 1, Zadatak 4) *** */
#include <iostream>

int main ()
{
    int sati;
    std::cout << "Unesite zeljeni broj sati: ";
    std::cin >> sati;
    double prva = 10 + sati * 0.5;
    double druga = sati * 0.8;
    if(prva < druga) std::cout << "Za " << sati << " sati isplatnija je prva firma.";
    else std::cout << "Za " << sati << " sati isplatnija je druga firma.";
	return 0;
}