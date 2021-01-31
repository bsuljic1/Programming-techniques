/* 
    TP 2018/2019: Tutorijal 6, Zadatak 6
	
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
		int broj_elemenata = 0;
		for(int i = 0; i < a.size(); i++) broj_elemenata += a.at(i).size();
			
		matrica[0] = new typename std::remove_reference<decltype(a[0][0])>::type[broj_elemenata];
		
		for(int i = 1; i < a.size(); i++)
			matrica[i] = matrica[i-1] + a.at(i-1).size();
		
		
		for(int i = 0; i < a.size(); i++) {
			for(int j = 0; j < a[i].size(); j++)
				matrica[i][j] = a[i][j];
		}

	} catch(std::bad_alloc e) {
		if(matrica != nullptr)
			delete[] matrica[0];
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
			delete[] dinamicka[0];
		delete[] dinamicka;

	} catch(std::bad_alloc) {
		std::cout << "Nedovoljno memorije";
	}


	return 0;
}
