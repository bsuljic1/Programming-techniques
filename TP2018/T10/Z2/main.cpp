/*
    TP 16/17 (Tutorijal 10, Zadatak 2)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#define  pi 4*atan(1)

class Krug
{
	double poluprecnik;
public:
	explicit Krug(double x)
	{
		Postavi(x);
	}
	void Postavi (double x)
	{
		if(x <= 0) throw std::domain_error("Neispravan poluprecnik");
		poluprecnik = x;
	}
	double DajPoluprecnik() const
	{
		return poluprecnik;
	}
	double DajObim() const
	{
		return 2*poluprecnik*pi;
	}
	double DajPovrsinu() const
	{
		return poluprecnik*poluprecnik*pi;
	}
	void Skaliraj (double faktor_skaliranja)
	{
		if(faktor_skaliranja <= 0) throw std::domain_error("Neispravan faktor skaliranja");
		poluprecnik *= faktor_skaliranja;
	}
	void Ispisi() const
	{
		std::cout << std::fixed << std::setprecision(5) << "R=" << poluprecnik << " O=" << DajObim() << " P=" << DajPovrsinu();
	}
};

class Valjak
{
	Krug baza;
	double visina;
public:
	Valjak(double x, double y)
		:baza(x), visina(y)
	{
		if(x < 0) throw std::domain_error("Neispravan poluprecnik");
		if(y < 0) throw std::domain_error("Neispravna visina");
	}
	void Postavi(double x, double y)
	{
		if(x < 0) throw std::domain_error("Neispravan poluprecnik");
		if(y < 0) throw std::domain_error("Neispravna visina");
		baza.Krug::Postavi(x);
		visina = y;
	}
	Krug DajBazu() const
	{
		return baza;
	}
	double DajPoluprecnikBaze() const
	{
		return baza.DajPoluprecnik();
	}
	double DajVisinu() const
	{
		return visina;
	}
	double DajPovrsinu() const
	{
		return 2*baza.DajPoluprecnik()*baza.DajPoluprecnik()*pi + 2*baza.DajPoluprecnik()*visina*pi;
	}
	double DajZapreminu() const
	{
		return pi*baza.DajPoluprecnik()*baza.DajPoluprecnik()*visina;
	}
	void Skaliraj(double faktor_skaliranja)
	{
		if(faktor_skaliranja <= 0) throw std::domain_error("Neispravan faktor skaliranja");
		baza.Postavi(baza.DajPoluprecnik()*faktor_skaliranja);
		visina *= faktor_skaliranja;
	}
	void Ispisi() const
	{
		std::cout << std::fixed << std::setprecision(5) << "R=" << baza.DajPoluprecnik() << " H=" << visina << " P=" << DajPovrsinu() << " V=" << DajZapreminu();
	}

};

int main ()
{
	return 0;
}
