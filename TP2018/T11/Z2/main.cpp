/*
    TP 16/17 (Tutorijal 11, Zadatak 2)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>

class StedniRacun
{
	double stanje_racuna;
	static int kreirani;
	static int aktivni;
public:
	StedniRacun(double x = 0)
	{
		if(x < 0) throw std::logic_error("Nedozvoljeno pocetno stanje");
		stanje_racuna = x;
		kreirani++;
		aktivni++;
	};
	StedniRacun(const StedniRacun &x){
		stanje_racuna = x.stanje_racuna;
		kreirani++;
		aktivni++;
	}
	~StedniRacun()
	{
		aktivni--;
	}
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
	double DajStanje() const
	{
		return stanje_racuna;
	}
	void ObracunajKamatu (double kamatna_stopa)
	{
		if(kamatna_stopa <= 0) throw std::logic_error("Nedozvoljena kamatna stopa");
		stanje_racuna += kamatna_stopa*(stanje_racuna)/100;
	}
	static int DajBrojKreiranih()
	{
		return kreirani;
	}
	static int DajBrojAktivnih()
	{
		return aktivni;
	}
};
int StedniRacun::aktivni = 0;
int StedniRacun::kreirani = 0;

int main ()
{
	return 0;
}
