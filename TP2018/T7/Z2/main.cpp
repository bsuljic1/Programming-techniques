/* 
    TP 16/17 (Tutorijal 7, Zadatak 2)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cstring>
#include <algorithm>

int main ()
{
	std::cout << "Koliko zelite recenica: ";
	int n;
	std::cin >> n;
	std::cin.ignore(10000, '\n');
	std::cout << "Unesite recenice:"  << std::endl;

	char **recenice = nullptr;
	try {
		recenice = new char*[n];
		for(int i = 0; i < n; i++) {
			char recenica[1000];
			std::cin.getline(recenica, 1000);
			char *pok = new char[std::strlen(recenica) + 1];
			recenice[i] =  pok;
			std::strcpy(pok, recenica);
		}
		std::cout << "Sortirane recenice: " << std::endl;
		std::sort(recenice, recenice + n, [](char *p1, char *p2){return std::strcmp(p2, p1) > 0;});
		for(int i = 0; i < n; i++)
			std::cout << recenice[i] << std::endl;
	} catch(std::bad_alloc) {
		std::cout << "Problemi s memorijom!";
	}

	if(recenice)
		for(int i = 0; i < n; i++) delete[] recenice[i];

	delete[] recenice;


	return 0;
}
