/* 
    TP 16/17 (Tutorijal 7, Zadatak 5)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <memory>

typedef std::shared_ptr<std::string> pok;

int main ()
{
	std::cout << "Koliko zelite recenica: ";
	int n;
	std::cin >> n;
	std::cin.ignore(10000, '\n');
	std::cout << "Unesite recenice:"  << std::endl;

	
	try {
		std::shared_ptr<pok> recenice(new pok[n], [](pok *p){delete[] p;});
		auto niz = recenice.get();
		for(int i = 0; i < n; i++) {
			niz[i] = std::make_shared<std::string>();
			std::getline(std::cin, *niz[i]);
		}
		std::cout << "Sortirane recenice: " << std::endl;
		std::sort(niz, niz + n, [](pok p1, pok p2){return (*p1) < (*p2);});
		for(int i = 0; i < n; i++)
			std::cout << *niz[i] << std::endl;
	} catch(std::bad_alloc) {
		std::cout << "Problemi s memorijom!";
	}

	return 0;
}
