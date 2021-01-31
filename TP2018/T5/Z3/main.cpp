/*
    TP 2018/2019: Tutorijal 5, Zadatak 3

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

bool JeLiPotpunKvadrat(int a)
{
	return int(sqrt(a)) == sqrt(a);
}

bool ManjiBrojCifara (int a, int b)
{
	return int(log10(abs(a))) < int(log10(abs(b)));
}

bool JeLiTrocifren (int a)
{
	return int(log10(abs(a)) + 1) == 3;
}

void Ispis(int a)
{
	std::cout << " " << a;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata (max. 1000): ";
	std::cin >> n;
	std::cout << "Unesite elemente: ";
	int niz[1000];

	std::for_each(niz, niz+n, [] (int &a) {
		std::cin >> a;
	});


	std::cout << "Najveci element niza je " << *std::max_element(niz, niz+n) << std::endl;

	std::cout << "Najmanji element niza se pojavljuje " << std::count(niz, niz+n, *std::min_element(niz, niz+n)) << " puta u nizu" << std::endl;

	std::cout << "U nizu ima " << std::count_if(niz, niz+n, JeLiPotpunKvadrat) << " brojeva koji su potpuni kvadrati" << std::endl;

	std::cout << "Prvi element sa najmanjim brojem cifara je " << *std::min_element(niz, niz+n, ManjiBrojCifara) << std::endl;

	int niz2[1000];

	auto kraj = std::remove_copy_if(niz, niz+n, niz2, JeLiTrocifren);

	std::cout << "Elementi koji nisu trocifreni su:";
	std::for_each(niz2, kraj, Ispis);


	return 0;
}
