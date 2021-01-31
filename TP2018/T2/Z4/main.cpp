//TP 2017/2018: Tutorijal 2, Zadatak 4
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
    while(i!=n) {
        double re, im;
        std::cout << "R"<< i+1 << " = ";
        std::cin >> re;
        std::cout << "X" << i+1 << " = ";
        std::cin >> im;
        std::cout << std::endl;
        z.real(re);
        z.imag(im);
        impedansa += 1./z;
        i++;
    }
    impedansa = 1./impedansa;
    std::cout << "\nParalelna veza ovih elemenata ima R = " << real(impedansa) << " i X = " << imag(impedansa) << ".";

    return 0;
}
