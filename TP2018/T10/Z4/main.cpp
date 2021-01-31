/*
    TP 16/17 (Tutorijal 10, Zadatak 4)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#define pi (4*atan(1))

class Ugao
{
	double rad;
public:
	Ugao(double radijani = 0)
	{
		Postavi(radijani);
	}
	Ugao(int stepeni, int minute, int sekunde)
	{
		Postavi(stepeni,minute,sekunde);
	}
	void Postavi(double radijani)
	{
		while(radijani >= 2*pi) radijani -= 2*pi;
		while(radijani < 0) radijani += 2*pi;
		rad = radijani;
	}
	void Postavi(int stepeni, int minute, int sekunde)
	{
		rad = pi*(stepeni + double(minute)/60 + double(sekunde)/3600)/180;
		while(rad >= 2*pi) rad -= 2*pi;
		while(rad < 0) rad += 2*pi;
	}
	double DajRadijane() const
	{
		return rad;
	}
	void OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde)
	{
		stepeni = rad*180/pi + 0.000001;
		minute = (rad*180/pi-stepeni)*60 + 0.000001;
		sekunde = ((rad*180/pi-stepeni)*60 - minute)*60 + 0.000001;
	}
	int DajStepene() const
	{
		return rad*180/pi + 0.000001;
	}
	int DajMinute() const
	{
		int stepeni = rad*180/pi + 0.000001;
		return (rad*180/pi-stepeni)*60 + 0.000001;
	}
	int DajSekunde() const
	{
		int stepeni = rad*180/pi + 0.000001;
		int minute = (rad*180/pi-stepeni)*60 + 0.000001;
		return ((rad*180/pi-stepeni)*60 - minute)*60 + 0.000001;
	}
	void Ispisi() const
	{
		std::cout << std::fixed << std::setprecision(5) << rad;
	}
	void IspisiKlasicno() const
	{
		std::cout << std::fixed << std::setprecision(5) << DajStepene() << "deg " << DajMinute() << "min " << DajSekunde() << "sec";
	}
	Ugao &SaberiSa(const Ugao &u)
	{
		rad += u.DajRadijane();
		while(rad >= 2*pi) rad -= 2*pi;
		while(rad < 0) rad += 2*pi;
		return *this;
	}
	Ugao &PomnoziSa(double x)
	{
		rad *= x;
		while(rad >= 2*pi) rad -= 2*pi;
		while(rad < 0) rad += 2*pi;
		return *this;
	}
	friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2);
	friend Ugao ProduktUglaSaBrojem(const Ugao &u, double x);
};

Ugao ZbirUglova(const Ugao &u1, const Ugao &u2)
{
	Ugao u3(u1.DajRadijane() + u2.DajRadijane());
	return u3;
}

Ugao ProduktUglaSaBrojem(const Ugao &u, double x)
{
	Ugao u2(u.DajRadijane()*x);
	return u2;
}


int main ()
{
	return 0;
}
