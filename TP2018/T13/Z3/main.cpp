/*
    TP 16/17 (Tutorijal 13, Zadatak 3)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

class Fakultet
{
	std::vector<ApstraktniStudent*> v;
public:
	~Fakultet()
	{
		for(int i = 0; i < v.size(); i++) delete v.at(i);
	}
	Fakultet() {}
	Fakultet(const Fakultet &f)
	{
		for(int i = 0; i < f.v.size(); i++) {
			v.push_back(f.v.at(i)->DajKopiju());
		}
	}
	Fakultet(Fakultet &&f)
	{
		v = f.v;
		f.v.clear();
	}
	Fakultet &operator=(const Fakultet &f)
	{
		for(int i = 0; i < v.size(); i++) delete v.at(i);
		v.clear();
		for(int i = 0; i < f.v.size(); i++) {
			v.push_back(f.v.at(i)->DajKopiju());
		}
		return *this;
	}
	Fakultet &operator=(Fakultet &&f)
	{
		for(auto x : v) delete x;
		v.clear();
		std::swap(v,f.v);
		return *this;
	}
	void UpisiStudenta(std::string ime, std::string prezime, int indeks)
	{
		for(auto x : v)
			if(x->DajBrojIndeksa() == indeks) throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
		v.push_back(new StudentBachelor(ime, prezime, indeks));
	}
	void UpisiStudenta(std::string ime, std::string prezime, int indeks, int godina)
	{
		for(auto x : v)
			if(x->DajBrojIndeksa() == indeks) throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
		v.push_back(new StudentMaster(ime, prezime, indeks, godina));
	}
	void ObrisiStudenta(int indeks)
	{
		for(auto x : v)
			if(x->DajBrojIndeksa() == indeks) {
				delete x;
				v.erase(std::find(v.begin(), v.end(), x));
				return;
			}
		throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	}
	ApstraktniStudent &operator [] (int indeks)
	{
		for(auto x : v)
			if(x->DajBrojIndeksa() == indeks)
				return *x;
		throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	}
	const ApstraktniStudent &operator [] (int indeks) const
	{
		for(auto x : v)
			if(x->DajBrojIndeksa() == indeks)
				return *x;
		throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
	}
	void IspisiSveStudente() const
	{
		auto novi = v;
		std::sort(novi.begin(), novi.end(), [](const ApstraktniStudent *a, const ApstraktniStudent *b) {
			if(a->DajProsjek() == b->DajProsjek())
				return a->DajBrojIndeksa() < b->DajBrojIndeksa();
			else return a->DajProsjek() > b->DajProsjek();

		});
		for(auto x : novi)
			x->IspisiPodatke();
	}
};

int main ()
{
	return 0;
}
