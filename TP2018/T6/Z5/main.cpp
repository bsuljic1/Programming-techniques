/*
    TP 2018/2019: Tutorijal 6, Zadatak 5

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <vector>
#include <deque>

template <typename NekiTip>
auto KreirajDinamickuKopiju2D (NekiTip a) -> typename std::remove_reference<decltype(a[0][0])>::type**
{
	typename std::remove_reference<decltype(a[0][0])>::type** matrica = nullptr;
	try {
		matrica = new typename std::remove_reference<decltype(a[0][0])>::type*[a.size()] {};
		for(int i = 0; i < a.size(); i++) {
			matrica[i] = new typename std::remove_reference<decltype(a[0][0])>::type[a[i].size()];
			for(int j = 0; j < a[i].size(); j++)
				matrica[i][j] = a[i][j];
		}

	} catch(std::bad_alloc e) {
		if(matrica != nullptr)
			for(int i = 0; i < a.size(); i++) delete[] matrica[i];
		delete[] matrica;
		throw e;
	}
	return matrica;
}

int main ()
{
	int n;
	std::cout << "Unesite broj redova kvadratne matrice: ";
	std::cin >> n;
	try {
		std::vector<std::deque<double>> matrica(n, std::deque<double>(n));
		std::cout << "Unesite elemente matrice: ";
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				std::cin >> matrica.at(i).at(j);

		double **dinamicka = nullptr;

		dinamicka = KreirajDinamickuKopiju2D(matrica);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				std::cout << dinamicka[i][j] << " ";
			std::cout << std::endl;
		}
		if(dinamicka != nullptr)
			for(int i = 0; i < n; i++) delete[] dinamicka[i];
		delete[] dinamicka;

	} catch(std::bad_alloc) {
		std::cout << "Nedovoljno memorije";
	}


	return 0;
}
