/* 
    TP 2018/2019: Tutorijal 5, Zadatak 7
	
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
#include <deque>
#include <algorithm>

template <typename NekiTip>
	auto SumaBloka (NekiTip a, NekiTip b) -> decltype(*a + *a){
		if(a == b)	
			throw std::range_error ("Blok je prazan");
		decltype(*a + *a) suma{};
		while( a != b){
			suma += *a;
			a++;
		}
		return suma;
	}

int main ()
{
	std::cout << "Unesite broj elemenata: ";
	int n;
	std::cin >> n;
	std::cout << "Unesite elemente:";
	std::deque<double> d(n);
	std::for_each(d.begin(), d.end(), [](double &a){std::cin >> a;});
	
	std::cout << "Suma svih elemenata u deku: " << SumaBloka(d.begin(), d.end());
	return 0;
}