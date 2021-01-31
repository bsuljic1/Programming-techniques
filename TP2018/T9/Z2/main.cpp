/* 
    TP 16/17 (Tutorijal 9, Zadatak 2)
	
	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cmath>


class Vektor3d
{
	double koordinate[3];
public:
	void Postavi(double x, double y, double z)
	{
		koordinate[0] = x;
		koordinate[1] = y;
		koordinate[2] = z;
	}
	void Ocitaj(double &x, double &y, double &z) const
	{
		x = koordinate[0];
		y = koordinate[1];
		z = koordinate[2];
	}
	void Ispisi() const
	{
		std::cout << "{" << koordinate[0] << "," << koordinate[1] << "," << koordinate[2] << "}";
	}
	double DajX() const
	{
		return koordinate[0];
	}
	double DajY() const
	{
		return koordinate[1];
	}
	double DajZ() const
	{
		return koordinate[2];
	}
	double DajDuzinu() const
	{
		double x = koordinate[0];
		double y = koordinate[1];
		double z = koordinate[2];
		return sqrt(x * x + y * y + z * z);
	}
	Vektor3d &PomnoziSaSkalarom(double s)
	{
		koordinate[0] *= s;
		koordinate[1] *= s;
		koordinate[2] *= s;
		return *this;
	}
	Vektor3d &SaberiSa(const Vektor3d &v)
	{
		koordinate[0] += v.koordinate[0];
		koordinate[1] += v.koordinate[1];
		koordinate[2] += v.koordinate[2];
		return *this;
	}
	friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);
	void PostaviX(double x)
	{
		koordinate[0] = x;
	}
	void PostaviY(double y)
	{
		koordinate[1] = y;
	}
	void PostaviZ(double z)
	{
		koordinate[2] = z;
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
