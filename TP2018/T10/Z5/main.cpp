/*
    TP 16/17 (Tutorijal 10, Zadatak 5)
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
	int step, min, sec;
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
		step = radijani*180/pi + 0.000001;
		min= (radijani*180/pi-step)*60 + 0.000001;
		sec = ((radijani*180/pi-step)*60 - min)*60 + 0.000001;
	}
	void Postavi(int stepeni, int minute, int sekunde)
	{
		int sek1 = ((sekunde + minute*60 + stepeni*3600) % 1296000 + 1296000)%1296000;
		step = sek1/3600;
		min = (sek1%3600) / 60;
		sec = sek1 % 60;
	}
	double DajRadijane() const
	{
		return pi*(step + double(min)/60 + double(sec)/3600)/180;
	}
	void OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde)
	{
		stepeni = step;
		minute = min;
		sekunde = sec;
	}
	int DajStepene() const
	{
		return step;
	}
	int DajMinute() const
	{
		return min;
	}
	int DajSekunde() const
	{
		return sec;
	}
	void Ispisi() const
	{
		std::cout << std::fixed << std::setprecision(5) << DajRadijane();
	}
	void IspisiKlasicno() const
	{
		std::cout << std::fixed << std::setprecision(5) << step << "deg " << min << "min " << sec << "sec";
	}
	Ugao &SaberiSa(const Ugao &u)
	{
		step += u.DajStepene();
		min += u.DajMinute();
		sec += u.DajSekunde();
		int sek1 = ((sec + min*60 + step*3600) % 1296000 + 1296000)%1296000;
		step = sek1/3600;
		min = (sek1%3600) / 60;
		sec = sek1 % 60;
		return *this;
	}
	Ugao &PomnoziSa(double x)
	{
		step *= x;
		min *= x;
		sec *= x;
		int sek1 = ((sec + min*60 + step*3600) % 1296000 + 1296000)%1296000;
		step = sek1/3600;
		min = (sek1%3600) / 60;
		sec = sek1 % 60;
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
