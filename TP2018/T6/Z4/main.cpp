/*
    TP 2018/2019: Tutorijal 6, Zadatak 4

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <cmath>

int **KreirajTrougao (int n)
{
	if(n <= 0) throw std::domain_error("Broj redova mora biti pozitivan");
	int **matrica = nullptr;

	int br_el = 0;
	for(int i = 0; i < n; i++)
		br_el += 2*i + 1;
	try {
		matrica = new int*[n] {};
		matrica[0] = new int[br_el];

		for(int i = 0; i < n; i++) {
			if(i != 0) matrica[i] = matrica[i - 1] + 2*(i-1) + 1;
			for(int j = 0; j < 2*i + 1; j++)
				matrica[i][j] = abs(j - i) + 1;
		}

	} catch(std::bad_alloc e) {
		if(matrica != nullptr)
			for(int i = 0; i < n; i++) delete[] matrica[i];
		delete[] matrica;
		throw e;
	}

	return matrica;

}


int main ()
{
	int n;
	std::cout << "Koliko zelite redova: ";
	std::cin >> n;
	int **matrica = nullptr;
	try {
		matrica = KreirajTrougao(n);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < 2*i + 1; j++)
				std::cout << matrica[i][j] << " ";
			std::cout << std::endl;
		}
	} catch(std::bad_alloc e) {
		std::cout << "Izuzetak: Nedovoljno memorije!";
	} catch(std::domain_error greska) {
		std::cout << "Izuzetak: " << greska.what() << std::endl;
	}
	
	if(matrica != nullptr) delete[] matrica[0];
	delete[] matrica;

	return 0;
}
