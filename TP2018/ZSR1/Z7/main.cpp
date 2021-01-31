//TP 2017/2018: ZSR 1, Zadatak 7
#include <iostream>
#include <iomanip>

int main ()
{
    double g, k;
    std::cout << "Unesite iznos glavnice i kamatne stope: ";
    std::cin >> g >> k;
    double kamata = g * k / 100;
    double nova_svota = g + kamata;
    
    std::cout << "Glavnica:" << std::right << std::setw(11) << int(g) << std::left << std::endl
              << "Kamatna stopa:" << std::right << std::setw(6) << int(k) << std::left << std::endl
              << "Kamata:" << std::right << std::setw(13) << int(kamata) << std::left << std::endl
              << "Nova svota:" << std::right << std:: setw(9) << int(nova_svota) << std::endl;
    
	return 0;
}
