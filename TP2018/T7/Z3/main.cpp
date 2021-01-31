/* 
    TP 16/17 (Tutorijal 7, Zadatak 3)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

int main ()
{
	std::cout << "Koliko zelite recenica: ";
	int n;
	std::cin >> n;
	std::cin.ignore(10000, '\n');
	std::cout << "Unesite recenice:"  << std::endl;

	std::string **recenice = nullptr;
	try {
		recenice = new std::string*[n]{};
		for(int i = 0; i < n; i++) {
			recenice[i] = new std::string();
			std::getline(std::cin, *recenice[i]);
		}
		std::cout << "Sortirane recenice: " << std::endl;
		std::sort(recenice, recenice + n, [](std::string *p1, std::string *p2){return (*p1) < (*p2);});
		for(int i = 0; i < n; i++)
			std::cout << *recenice[i] << std::endl;
	} catch(std::bad_alloc) {
		std::cout << "Problemi s memorijom!";
	}

	if(recenice)
		for(int i = 0; i < n; i++) delete recenice[i];

	delete[] recenice;


	return 0;
}
