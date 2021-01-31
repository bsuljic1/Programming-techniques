/*
    TP 16/17 (Tutorijal 13, Zadatak 1)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#define pi 4*atan(1)

class Lik
{
public:
	virtual~Lik() {};
	virtual void IspisiSpecificnosti() const = 0;
	virtual double DajPovrsinu() const = 0;
	virtual double DajObim() const = 0;
	void Ispisi() const
	{
		IspisiSpecificnosti();
		std::cout << "Obim: " << DajObim() << " Povrsina: " << DajPovrsinu() << std::endl;
	}
};

class Krug : public Lik
{
	double poluprecnik;
public:
	Krug(double r)
	{
		if(r <= 0) throw std::domain_error("Neispravni parametri");
		poluprecnik = r;
	}
	void IspisiSpecificnosti() const
	{
		std::cout << "Krug poluprecnika " << poluprecnik << std::endl;
	}
	double DajPovrsinu() const
	{
		return poluprecnik*poluprecnik*pi;
	}
	double DajObim() const
	{
		return 2*poluprecnik*pi;
	}
};

class Pravougaonik : public Lik
{
	double a,b;
public:
	Pravougaonik(double x, double y)
	{
		if(x <= 0 || y <= 0) throw std::domain_error("Neispravni parametri");
		a = x;
		b = y;
	}
	void IspisiSpecificnosti() const
	{
		std::cout << "Pravougaonik sa stranicama duzine " << a << " i " << b << std::endl;
	}
	double DajPovrsinu() const
	{
		return a*b;
	}
	double DajObim() const
	{
		return 2*(a+b);
	}
};

class Trougao : public Lik
{
	double a, b, c;
public:
	Trougao(double x, double y, double z)
	{
		if(x <= 0 || y <= 0 || z <= 0 || x + y <= z || x + z <= y || y + z <= x) throw std::domain_error("Neispravni parametri");
		a = x;
		b = y;
		c = z;
	}
	void IspisiSpecificnosti() const
	{
		std::cout << "Trougao sa stranicama duzine " << a << ", " << b << " i " << c << std::endl;
	}
	double DajPovrsinu() const
	{
		double s = DajObim()/2;
		return sqrt(s*(s-a)*(s-b)*(s-c));
	}
	double DajObim() const
	{
		return a + b + c;
	}
};

int main ()
{
	std::cout << "Koliko zelite likova: ";
	int n;
	std::cin >> n;
	std::cin.ignore(10000,'\n');
	std::cin.clear();
	std::vector<std::shared_ptr<Lik>> v(n);
	for(int i = 0; i < n; i++) {
		std::cout << "Lik " << i+1 << ": ";
		char unos = std::cin.get();
		if(unos == 'K') {
			double poluprecnik;
			std::cin >> poluprecnik;
			if(std::cin.peek() != '\n') {
				std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
				std::cin.ignore(10000, '\n');
				std::cin.clear();
				i--;
			} else {
				try {
					v.at(i) = std::make_shared<Krug>(poluprecnik);
					std::cin.ignore(10000,'\n');
					std::cin.clear();
				} catch(std::domain_error) {
					std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
					std::cin.ignore(10000, '\n');
					std::cin.clear();
					i--;
				}
			}
		} else if(unos == 'P') {
			double a, b;
			char zarez;
			std::cin >> a >> zarez >> b;
			if(std::cin.peek() != '\n' || zarez != ',') {
				std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
				std::cin.ignore(10000, '\n');
				std::cin.clear();
				i--;
			} else {
				try {
					v.at(i) = std::make_shared<Pravougaonik>(a, b);
					std::cin.ignore(10000,'\n');
					std::cin.clear();
				} catch(std::domain_error) {
					std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
					std::cin.ignore(10000, '\n');
					std::cin.clear();
					i--;
				}
			}
		} else if(unos == 'T') {
			double a, b, c;
			char prvizarez, drugizarez;
			std::cin >> a >> prvizarez >> b >> drugizarez >> c;
			if(std::cin.peek() != '\n' || prvizarez != ',' || drugizarez != ',') {
				std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
				std::cin.ignore(10000, '\n');
				std::cin.clear();
				i--;

			} else {
				try {
					v.at(i) = std::make_shared<Trougao>(a, b, c);
					std::cin.ignore(10000,'\n');
					std::cin.clear();
				} catch(std::domain_error) {
					std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
					std::cin.ignore(10000, '\n');
					std::cin.clear();
					i--;
				}
			}
		} else {
			std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
			std::cin.ignore(10000, '\n');
			std::cin.clear();
			i--;
		}
	}
	
	std::cout << std::endl;
	for(auto x : v)	x->Ispisi();

	return 0;
}
