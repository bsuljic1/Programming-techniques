/*
    TP 16/17 (Tutorijal 12, Zadatak 3)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>

enum Dani {Ponedjeljak, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};

Dani &operator ++(Dani &d)
{
	return d = Dani((int(d) + 1) % 7);
}

Dani operator ++(Dani &d, int)
{
	Dani pomocni = d;
	++d;
	return pomocni;
}

std::ostream &operator <<(std::ostream &tok, const Dani &d)
{
	switch(d) {
	case 0:
		return tok << "Ponedjeljak";
	case 1:
		return tok << "Utorak";
	case 2:
		return tok << "Srijeda";
	case 3:
		return tok << "Cetvrtak";
	case 4:
		return tok << "Petak";
	case 5:
		return tok << "Subota";
	case 6:
		return tok << "Nedjelja";
	}
}

int main ()
{
	for(Dani d = Ponedjeljak; d <= Petak; d++) std::cout << d << std::endl;
	return 0;
}
