/* 
    TP 16/17 (Tutorijal 12, Zadatak 5)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main ()
{
	std::cout << "Koliko zelite elemenata: ";
	int n;
	std::cin >> n;
	std::vector<double> v(n);
	std::cout << "Unesite elemente: ";
	for(double &x : v) std::cin >> x;
	std::transform(v.begin(), v.end(), v.begin(), std::bind1st(std::divides<double>(), 1));
	std::cout << "Transformirani elementi: ";
	for(auto x : v) std::cout << x << " ";
	return 0;
}