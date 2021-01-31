/*
    TP 2018/2019: Tutorijal 6, Zadatak 2

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <vector>

template <typename Itertip>
auto KreirajIzvrnutiNiz (Itertip p1, Itertip p2) -> typename std::remove_reference<decltype(*p1)>::type*
{
	int n = 0;
	Itertip pok = p1;
	while(pok != p2) {
		pok++;
		n++;
	}

	auto niz = new typename std::remove_reference<decltype(*p1)>::type[n];
	auto p = niz + n;

	while(p1 != p2) {
		p--;
		*p = *p1;
		p1++;
	}


	return niz;


}

int main ()
{
	try {
		int n;
		std::cout << "Koliko zelite elemenata: ";
		std::cin >> n;

		std::vector<double> v(n);
		std::cout << "Unesite elemente: ";
		for(int i = 0; i < n; i++) std::cin >> v.at(i);

		auto niz = KreirajIzvrnutiNiz(v.begin(), v.end());
		std::cout << "Kreirani niz: ";
		for(int i = 0; i < n; i++) std::cout << niz[i] << " ";
		delete[] niz;
	} catch (...) {
		std::cout << "Nedovoljno memorije!";
	}
	return 0;
}
