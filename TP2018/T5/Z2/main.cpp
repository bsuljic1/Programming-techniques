/*
    TP 2018/2019: Tutorijal 5, Zadatak 2

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
#include <string>


template <typename NekiTip, typename NekiTip2>
auto RazmijeniBlokove(NekiTip p1, NekiTip p2, NekiTip2 p3) -> NekiTip2
{
	while( p1 != p2) {
		auto temp = *p1;
		*p1 = *p3;
		*p3 = temp;
		p1++;
		p3++;
	}

	return p3;
}

int main ()
{
	std::string a = "asdfgh", b = "qwertz";
	RazmijeniBlokove(std::begin(a), std::end(a), std::begin(b));
	std::cout << "Prvi niz: " << a;
	
	std::cout << "\nDrugi niz: " << b;
	
	
	int a1[] {1, 2, 3, 4, 5}, b1[] {6, 7, 8, 9, 10};
	RazmijeniBlokove(std::begin(a1), std::end(a1), std::begin(b1));
	std::cout << "\nPrvi niz: ";
	for(int x : a1) std::cout << x << " ";
	std::cout << "\nDrugi niz: ";
	for(int x : b1) std::cout << x << " ";


	return 0;
}
