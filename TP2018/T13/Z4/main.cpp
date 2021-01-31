/*
    TP 16/17 (Tutorijal 13, Zadatak 4)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <string>

class ApstraktniStudent
{
protected:
	std::string ime, prezime;
	int broj_indeksa;
	int broj_polozenih;
	double prosjek;
public:
	virtual ~ApstraktniStudent() {}
	ApstraktniStudent(std::string name, std::string lastname, int number) :	ime(name), prezime(lastname), broj_indeksa(number), broj_polozenih(0), prosjek(5) {}
	std::string DajIme() const
	{
		return ime;
	}
	std::string DajPrezime() const
	{
		return prezime;
	}
	int DajBrojIndeksa() const
	{
		return broj_indeksa;
	}
	int DajBrojPolozenih() const
	{
		return broj_polozenih;
	}
	double DajProsjek() const
	{
		return prosjek;
	};
	void RegistrirajIspit(int ocjena)
	{
		if(ocjena < 5 || ocjena > 10) throw std::domain_error("Neispravna ocjena");
		if(ocjena != 5) {
			prosjek = (prosjek*broj_polozenih + ocjena)/(broj_polozenih+1);
			broj_polozenih++;
		}
	}
	void PonistiOcjene()
	{
		broj_polozenih = 0;
		prosjek = 5;
	}
	virtual void IspisiPodatke()const = 0;
	virtual ApstraktniStudent *DajKopiju() const = 0;
};

class StudentBachelor : public ApstraktniStudent
{
public:
	StudentBachelor(std::string name, std::string lastname, int number) : ApstraktniStudent(name, lastname, number) {}
	void IspisiPodatke()const override
	{
		std::cout << "Student bachelor studija " << ime << " " << prezime << ", sa brojem indeksa "
		          << broj_indeksa << "," << std::endl << "ima prosjek " << prosjek << "." << std::endl;
	}
	ApstraktniStudent *DajKopiju() const override
	{
		return new StudentBachelor(*this);
	}

};

class StudentMaster : public ApstraktniStudent
{
	int godina;
public:
	StudentMaster(std::string name, std::string lastname, int number, int god) : godina(god), ApstraktniStudent(name, lastname, number) {}
	void IspisiPodatke()const override
	{
		std::cout << "Student master studija " << ime << " " << prezime << ", sa brojem indeksa "
		          << broj_indeksa << "," << std::endl << "zavrsio bachelor studij godine " << godina << ",ima prosjek " << prosjek << "." << std::endl;
	}
	ApstraktniStudent *DajKopiju() const override
	{
		return new StudentMaster(*this);
	}


};
class Student
{
	ApstraktniStudent *s;
	void Test() const
	{
		if(!s)throw std::logic_error("Nespecificiran lik!");
	}
public:
	Student() : s(nullptr) {}
	~Student()
	{
		delete s;
	}
	Student(const ApstraktniStudent &s2) : s(s2.DajKopiju()) {}
	Student(const Student &s2)
	{
		if(!s2.s) s= nullptr;
		else s = s2.s->DajKopiju();
	}
	Student(Student &&s2)
	{
		s = s2.s;
		s2.s = nullptr;
	}
	Student &operator =(const Student &s2)
	{
		ApstraktniStudent *n = nullptr;
		if(s2.s != nullptr) n = s2.s->DajKopiju();
		delete s;
		s = n;
		return *this;
	}
	Student &operator = (Student &&s2)
	{
		std::swap(s, s2.s);
		return *this;
	}
	std::string DajIme() const
	{
		Test();
		return s->DajIme();
	}
	std::string DajPrezime() const
	{
		Test();
		return s->DajPrezime();
	}
	int DajBrojIndeksa() const
	{
		Test();
		return s->DajBrojIndeksa();
	}
	int DajBrojPolozenih() const
	{
		Test();
		return s->DajBrojPolozenih();
	}
	double DajProsjek() const
	{
		Test();
		return s->DajProsjek();
	}
	void RegistrirajIspit(int ocjena)
	{
		Test();
		s->RegistrirajIspit(ocjena);
	}
	void PonistiOcjene()
	{
		Test();
		s->PonistiOcjene();
	}
	void IspisiPodatke()const
	{
		Test();
		s->IspisiPodatke();
	}

};

int main ()
{
	return 0;
}
