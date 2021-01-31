/*
    TP 16/17 (Tutorijal 7, Zadatak 1)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cstring>

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
		for(int i = 0; i < n; i++) {
			int min = i;
			for(int j = i + 1; j < n; j++) {
				if(std::strcmp(recenice[min], recenice[j]) > 0) min = j;
			}
			char *temp = recenice[i];
			recenice[i] = recenice[min];
			recenice[min] = temp;
		}

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
