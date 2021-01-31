/*  *** Zadaci za samostalan rad (ZSR 1, Zadatak 5) *** */
#include <iostream>
#include <cmath>

int main ()
{
    std::cout << "Unesite koeficijente a, b i c: ";
    std::cin << a;
    cin.ignore();
    std::cin << b;
    cin.ignore();
    std::cin << c;
    cin.ignore();
    int d = b * b - 4 * a * c;
    
    if(d >= 0){
        if(a = 0){
            if (b !=0 && c != 0) {
                double x = (-1 * c) / b;
                std::cout << "Rjesenje jednacine je: " << x;
            else if (b == 0 && c != 0) std::cout << "Jednacina nema rjesenja.";
            else std::cout << "Jednacina identicki zadovoljena za svaku vrijednost x.";
        }
    }
    else {
        
    }
    
	return 0;
}