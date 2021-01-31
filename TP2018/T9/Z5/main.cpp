/*
    TP 16/17 (Tutorijal 9, Zadatak 5)

	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <iomanip>

class Sat
{
	int sek;
public:
	static bool DaLiJeIspravno(int h, int m, int s)
	{
		if(h > 23 || h < 0 || m > 59 || m < 0 || s > 59 || s < 0) return false;
		return true;
	}
	static int Razmak(const Sat &vrijeme1, const Sat &vrijeme2)
	{
		int sek1 = vrijeme1.sek;
		int sek2 = vrijeme2.sek;
		return sek1 - sek2;
	}
	void Postavi(int h, int m, int s)
	{
		bool ispravno = DaLiJeIspravno(h, m, s);
		if(!ispravno) throw std::domain_error("Neispravno vrijeme");
		Sat::sek = s + m*60 + h*3600;
	}
	void PostaviNormalizirano(int h, int m, int s);
	Sat Sljedeci()
	{
		sek++;
		sek = (sek % 86400 + 86400) % 86400;
		return *this;
	}
	Sat Prethodni()
	{
		sek--;
		sek = (sek % 86400 + 86400) % 86400;
		return *this;
	}
	Sat PomjeriZa(int za)
	{
		sek += za;
		sek = (sek % 86400 + 86400) % 86400;
		return *this;
	}
	void Ispisi() const
	{
		std::cout << std::setw(2) << std::setfill('0') << DajSate() << ":" << std::setw(2) << std::setfill('0') << DajMinute() << ":" <<  std::setw(2) << std::setfill('0') << DajSekunde();
	}
	int DajSate() const
	{
		return sek/3600;
	}
	int DajMinute() const
	{
		return (sek%3600) / 60;
	}
	int DajSekunde() const
	{
		return sek%60;
	}
	friend int BrojSekundiIzmedju(const Sat vrijeme1, const Sat vrijeme2);
};

void Sat::PostaviNormalizirano(int h, int m, int s)
{
	Sat::sek = ((s + m*60 + h*3600) % 86400 + 86400) % 86400;
}

int BrojSekundiIzmedju(const Sat vrijeme1, const Sat vrijeme2)
{
	int sek1 = vrijeme1.sek;
	int sek2 = vrijeme2.sek;
	return sek1 - sek2;
}
int main ()
{
	if(Sat::DaLiJeIspravno(2, 45, 50)) std::cout << "02:45:50 je ispravno vrijeme!" << std::endl;
	else std::cout << "02:45:50 nije ispravno vrijeme!" << std::endl;
	if(Sat::DaLiJeIspravno(456, 123, 432)) std::cout << "456:123:432 je ispravno vrijeme!" << std::endl;
	else std::cout << "456:123:432 nije ispravno vrijeme!" << std::endl;
	Sat v1, v2;
	v1.Postavi(1,20,15);
	std::cout << "Vrijeme 1: ";
	v1.Ispisi();
	std::cout << std::endl;
	v2.PostaviNormalizirano(2, 56, 40);
	std::cout <<"Vrijeme 2: ";
	v2.Ispisi();
	std::cout << std::endl;
	std::cout << "Razmak izmedju v1 i v2 je: " << Sat::Razmak(v1, v2) << std::endl;
	v1.Sljedeci();
	std::cout << "Poslije v1: ";
	v1.Ispisi();
	std::cout << std::endl;
	v2.Prethodni();
	std::cout << "Prije v2: ";
	v2.Ispisi();
	std::cout << std::endl;
	v1.PomjeriZa(-1);
	v2.PomjeriZa(1);
	std::cout << "v1 i v2 poslije pomjeranja: ";
	v1.Ispisi();
	std::cout << " ";
	v2.Ispisi();
	std::cout << std::endl;
	std::cout << "Vrijeme 1: Sati: " << v1.DajSate() << " Minute: " << v1.DajMinute() << " Sekunde: " << v1.DajSekunde() << std::endl;
	std::cout << "Broj sekundi izmedju v1 i v2: " << BrojSekundiIzmedju(v1, v2) << std::endl;

	return 0;
}
