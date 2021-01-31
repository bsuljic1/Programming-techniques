/*
    TP 16/17 (Tutorijal 9, Zadatak 1)

	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cmath>


class Vektor3d
{
	double x, y, z;
public:
	void Postavi(double x, double y, double z)
	{
		Vektor3d::x = x;
		Vektor3d::y = y;
		Vektor3d::z = z;
	}
	void Ocitaj(double &x, double &y, double &z) const
	{
		x = Vektor3d::x;
		y = Vektor3d::y;
		z = Vektor3d::z;
	}
	void Ispisi() const
	{
		std::cout << "{" << x << "," << y << "," << z << "}";
	}
	double DajX() const
	{
		return x;
	}
	double DajY() const
	{
		return y;
	}
	double DajZ() const
	{
		return z;
	}
	double DajDuzinu() const
	{
		return sqrt(x * x + y * y + z * z);
	}
	Vektor3d &PomnoziSaSkalarom(double s)
	{
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}
	Vektor3d &SaberiSa(const Vektor3d &v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);
	void PostaviX(double x)
	{
		Vektor3d::x = x;
	}
	void PostaviY(double y)
	{
		Vektor3d::y = y;
	}
	void PostaviZ(double z)
	{
		Vektor3d::z = z;
	}
};

Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2)
{
	Vektor3d v3;
	v3.Postavi(v1.DajX() + v2.DajX(), v1.DajY() + v2.DajY(),
	           v1.DajZ() + v2.DajZ());
	return v3;
}


int main ()
{
	Vektor3d v1;
	v1.Postavi(1, 2, 3);
	double x, y, z;
	v1.Ocitaj(x, y, z);
	std::cout << "Ocitaj...x:" << x << " y:" << y << " z:" << z << std::endl;
	v1.Ispisi();
	std::cout << std::endl;
	double xx = v1.DajX();
	double yy = v1.DajY();
	double zz = v1.DajZ();
	std::cout << "Daj...x:" << xx << " y:" << yy << " z:" <<zz << std::endl;
	double duzina = v1.DajDuzinu();
	std::cout << "Duzina vektora: " << duzina << std::endl;
	v1.PomnoziSaSkalarom(2);
	std::cout << "Pomnozen sa 2: ";
	v1.Ispisi();
	std::cout << std::endl;
	Vektor3d v2;
	v2.Postavi(1, 2, 3);
	v1.SaberiSa(v2);
	std::cout << "Vektor sabran sa vektorom {1,2,3}: ";
	v1.Ispisi();
	std::cout << std::endl;
	Vektor3d v3;
	v3.Postavi(7,8,9);
	std::cout << "Vektor sabran sa vektorom {7,8,9}: ";
	ZbirVektora(v1, v3).Ispisi();
	std::cout << std::endl;
	v1.PostaviX(12);
	v1.PostaviY(10);
	v1.PostaviZ(2018);
	std::cout << "Funkcija postavixyz...";
	v1.Ispisi();
	return 0;
}
