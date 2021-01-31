//TP 2017/2018: Tutorijal 2, Zadatak 3
#include <iostream>
#include <complex>
#include <vector>

int main ()
{
    int n;
    std::complex<double> z;
    std::complex<double> impedansa;
    std::cout << "Unesite broj elemenata: ";
    std::cin >> n;
    std::cout << std::endl;
    
    int i = 0;
    while(i!=n){
        std::cout << "Z_" << i+1 << " = ";
        std::cin >> z;
        impedansa += 1./z;
        i++;
    }
    impedansa = 1./impedansa;
    std::cout << "\nParalelna veza ovih elemenata ima impedansu Z_ = " << impedansa << ".";
    
    
	return 0;
}
