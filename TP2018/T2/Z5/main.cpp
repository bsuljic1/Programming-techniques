//TP 2017/2018: Tutorijal 2, Zadatak 5

#include <iostream>
#include <complex>
#include <vector>

const double pi = 4*atan(1);

int main ()
{
    int n;
    std::complex<double> z;
    std::complex<double> impedansa;
    std::cout << "Unesi broj elemenata: ";
    std::cin >> n;
    std::cout << std::endl;

    int i = 0;
    while(i!=n) {
        long double prividni, pomak;
        std::cout << "Z"<< i+1 << " = ";
        std::cin >> prividni;
        std::cout << "fi" << i+1 << " = ";
        std::cin >> pomak;
        std::cout << std::endl;
        z = std::polar(prividni, (pomak*pi)/180);
        impedansa += 1./z;
        i++;
    }
    impedansa = 1./impedansa;
    std::cout << "Paralelna veza ovih elemenata ima Z = " << abs(impedansa) << " i fi = " << arg(impedansa)*180/pi<< ".";

    return 0;
}