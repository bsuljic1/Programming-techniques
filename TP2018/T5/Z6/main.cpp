/*
    TP 2018/2019: Tutorijal 5, Zadatak 6

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
#include <vector>

int SumaCifara (int a)
{
	if(a == 0) return 0;
	return abs(a) % 10 + SumaCifara(abs(a)/10);
}

bool VeciPoSumi (int a, int b){
	if(SumaCifara(a) < SumaCifara(b)) return true;
	if(SumaCifara(b) < SumaCifara(a)) return false;
	return a < b;
}


int main ()
{
	int n;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	std::cout << "Unesite elemente: ";
	std::vector<int> v(n);
	std::for_each(v.begin(), v.end(), [](int &a) {
		std::cin >> a;
	});

	std::vector<int> sortiran(n);
	std::partial_sort_copy (v.begin(), v.end(), sortiran.begin(), sortiran.end(), VeciPoSumi);

	std::cout << "Niz sortiran po sumi cifara glasi:";
	std::for_each(sortiran.begin(), sortiran.end(), [](int a) {
		std::cout << " " << a;
	});


	std::cout << std::endl << "Unesite broj koji trazite: ";
	int x;
	std::cin >> x;
	
	bool nalazi = std::binary_search(sortiran.begin(), sortiran.end(), x, VeciPoSumi);
	if(nalazi)
		std::cout << "Trazeni broj nalazi se na poziciji " << std::find(sortiran.begin(), sortiran.end(), x) - sortiran.begin() << std::endl;
	else
		std::cout << "Trazeni broj ne nalazi se u nizu!" << std::endl;
	return 0;
}
