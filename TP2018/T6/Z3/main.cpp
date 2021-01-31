/*
    TP 2018/2019: Tutorijal 6, Zadatak 3

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
	try {
		matrica = new int*[n] {};

		for(int i = 0; i < n; i++) {
			int m = 2*i + 1;
			matrica[i] = new int[m];
			for(int j = 0; j < m; j++) {
				matrica[i][j] = abs(j - i) + 1;
			}
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

	if(matrica != nullptr)
		for(int i = 0; i < n; i++) delete[] matrica[i];
	delete[] matrica;

	return 0;
}
