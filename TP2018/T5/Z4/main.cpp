/*
    TP 2018/2019: Tutorijal 5, Zadatak 4

	Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
	mozete slati na mail nslamnik1@etf.unsa.ba.

	NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
			  da se koristi indeksiranje niz[i] ili simulacija indeksiranja
			  npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.

			  To ce tutori rucno pregledati u toku tutorijala te ako
			  student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se da
			  za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	std::cout << "Unesite elemente: ";
	std::deque<int> niz(n);

	std::for_each(niz.begin(), niz.end(), [] (int &a) {
		std::cin >> a;
	});

	std::cout << "Najveci element deka je " << *std::max_element(niz.begin(), niz.end()) << std::endl;

	std::cout << "Najmanji element deka se pojavljuje " << std::count(niz.begin(), niz.end(), *std::min_element(niz.begin(), niz.end())) << " puta u deku" << std::endl;

	std::cout << "U deku ima " << std::count_if(niz.begin(), niz.end(), [] (int a) {
		return int(sqrt(a)) == sqrt(a);
	}) << " brojeva koji su potpuni kvadrati" << std::endl;

	std::cout << "Prvi element sa najmanjim brojem cifara je " << *std::min_element(niz.begin(), niz.end(), [](int a, int b) {
		return int(log10(abs(a))) < int(log10(abs(b)));
	}) << std::endl;

	int niz2[1000];
	auto kraj = std::remove_copy_if(niz.begin(), niz.end(), niz2, [] (int a) {
		return int(log10(abs(a)) + 1) == 3;
	});

	std::cout << "Elementi koji nisu trocifreni su:";
	std::for_each(niz2, kraj, [](int a) {
		std::cout << " " << a;
	});
	return 0;
}
