/*
    TP 16/17 (Tutorijal 10, Zadatak 1)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>

class StedniRacun
{
	double stanje_racuna;
public:
	StedniRacun(double x = 0)
	{
		if(x < 0) throw std::logic_error("Nedozvoljeno pocetno stanje");
		stanje_racuna = x;
	};
	void Ulozi (double x)
	{
		if(x + stanje_racuna < 0) throw std::logic_error("Transakcija odbijena");
		stanje_racuna += x;
	}
	void Podigni (double x)
	{
		if(x > stanje_racuna) throw std::logic_error("Transakcija odbijena");
		stanje_racuna -= x;
	}
	double DajStanje() const{
		return stanje_racuna;
	}
	void ObracunajKamatu (double kamatna_stopa) {
		if(kamatna_stopa <= 0) throw std::logic_error("Nedozvoljena kamatna stopa");
		stanje_racuna += kamatna_stopa*stanje_racuna/100;
	}
};

int main ()
{
	return 0;
}
