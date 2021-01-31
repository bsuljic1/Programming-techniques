/*
    TP 16/17 (Tutorijal 12, Zadatak 1)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>

class Sat
{
	int sat, min, sek;
public:
	Sat(): sat(0), min(0), sek(0) {};
	Sat(int h, int m, int s)
	{
		PostaviNormalizirano(h, m, s);
	}
	static bool DaLiJeIspravno(int h, int m, int s)
	{
		if(h > 23 || h < 0 || m > 59 || m < 0 || s > 59 || s < 0) return false;
		return true;
	}
	static int Razmak(const Sat vrijeme1, const Sat vrijeme2)
	{
		int sek1 = vrijeme1.sek + vrijeme1.min*60 + vrijeme1.sat*3600;
		int sek2 = vrijeme2.sek + vrijeme2.min*60 + vrijeme2.sat*3600;
		return sek1 - sek2;
	}
	void Postavi(int h, int m, int s)
	{
		bool ispravno = DaLiJeIspravno(h, m, s);
		if(!ispravno) throw std::domain_error("Neispravno vrijeme");
		Sat::sat = h;
		Sat::min = m;
		Sat::sek = s;
	}
	void PostaviNormalizirano(int h, int m, int s);
	Sat &operator ++() //prefiksni ++
	{
		sek++;
		PostaviNormalizirano(sat, min, sek);
		return *this;
	}
	Sat operator ++(int) //postfiksni ++
	{
		Sat pomocni(sat, min, sek);
		sek++;
		PostaviNormalizirano(sat, min, sek);
		return pomocni;
	}
	Sat &operator --() //prefiksni --
	{
		sek--;
		PostaviNormalizirano(sat, min, sek);
		return *this;
	}
	Sat operator --(int) //postfiksni --
	{
		Sat pomocni(sat, min, sek);
		sek--;
		PostaviNormalizirano(sat, min, sek);
		return pomocni;
	}
	Sat operator +=(int za){
		sek += za;
		PostaviNormalizirano(sat, min, sek);
		return *this;
	}
	Sat operator -=(int za){
		sek -= za;
		PostaviNormalizirano(sat, min, sek);
		return *this;
	}
	Sat operator +(int n){
		Sat novi(sat, min,sek);
		novi += n;
		return novi;
	}
	Sat operator -(int n){
		Sat novi(sat, min,sek);
		novi-= n;
		return novi;
	}
	int DajSate() const
	{
		return sat;
	}
	int DajMinute() const
	{
		return min;
	}
	int DajSekunde() const
	{
		return sek;
	}
	friend std::ostream &operator <<(std::ostream &tok, const Sat &s);
	friend int operator -(const Sat vrijeme1, const Sat vrijeme2);
};
std::ostream &operator <<(std::ostream &tok, const Sat &s) {
	tok << std::setw(2) << std::setfill('0') << s.sat << ":" << std::setw(2) << std::setfill('0') << s.min << ":" <<  std::setw(2) << std::setfill('0') << s.sek;
}
void Sat::PostaviNormalizirano(int h, int m, int s)
{
	int sek = ((s + m*60 + h*3600) % 86400 + 86400) % 86400;
	Sat::sat = sek/3600;
	Sat::min = (sek%3600) / 60;
	Sat::sek = sek % 60;
}

int operator -(const Sat vrijeme1, const Sat vrijeme2)
{
	int sek1 = vrijeme1.sek + vrijeme1.min*60 + vrijeme1.sat*3600;
	int sek2 = vrijeme2.sek + vrijeme2.min*60 + vrijeme2.sat*3600;
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
	std::cout << "Vrijeme 1: " << v1 << std::endl;
	v2.PostaviNormalizirano(2, 56, 40);
	std::cout <<"Vrijeme 2: " << v2 << std::endl;
	std::cout << "Razmak izmedju v1 i v2 je: " << Sat::Razmak(v1, v2) << std::endl;
	++v1;
	std::cout << "Poslije v1: " << v1 << std::endl;
	--v2;
	std::cout << "Prije v2: " << v2 << std::endl;
	v1 -= 1;
	v2 += 1;
	std::cout << "v1 i v2 poslije pomjeranja: " << v1 << " " << v2 << std::endl;
	std::cout << "Vrijeme 1: Sati: " << v1.DajSate() << " Minute: " << v1.DajMinute() << " Sekunde: " << v1.DajSekunde() << std::endl;
	std::cout << "Broj sekundi izmedju v1 i v2: " << v1-v2 << std::endl;
	return 0;
}
