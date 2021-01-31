/*
    TP 16/17 (Tutorijal 11, Zadatak 5)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <memory>
#include <vector>

class Tim
{
	char ime_tima[20];
	int broj_odigranih;
	int broj_pobjeda;
	int broj_nerijesenih;
	int broj_poraza;
	int broj_datih;
	int broj_primljenih;
	int broj_poena;
public:
	Tim(const char ime[]);
	void ObradiUtakmicu(int dati, int primljeni);
	const char *DajImeTima() const
	{
		return ime_tima;
	}
	int DajBrojPoena() const
	{
		return broj_poena;
	}
	int DajGolRazliku() const
	{
		return broj_datih - broj_primljenih;
	}
	void IspisiPodatke() const;
};

Tim::Tim(const char ime[]) : broj_odigranih(0),
	broj_pobjeda(0),
	broj_nerijesenih(0),
	broj_poraza(0),
	broj_datih(0),
	broj_primljenih(0),
	broj_poena(0)
{
	if(std::strlen(ime) > 19) throw std::range_error("Predugacko ime tima");
	std::strcpy(ime_tima, ime);
}

void Tim::ObradiUtakmicu(int dati, int primljeni)
{
	if(dati < 0 || primljeni < 0) throw std::range_error("Neispravan broj golova");
	broj_datih += dati;
	broj_primljenih += primljeni;
	broj_odigranih++;
	if(dati > primljeni) {
		broj_pobjeda++;
		broj_poena += 3;
	}
	if(dati < primljeni) broj_poraza++;
	if(dati == primljeni) {
		broj_nerijesenih++;
		broj_poena++;
	}

}

void Tim::IspisiPodatke() const
{
	std::cout <<  std::setw(20) << std::left << ime_tima << std::right <<  std::setw(4) << broj_odigranih << std::setw(4) << broj_pobjeda << std::setw(4) << broj_nerijesenih <<
	          std::setw(4) << broj_poraza << std::setw(4) << broj_datih << std::setw(4) << broj_primljenih << std::setw(4) << broj_poena << std::endl;
}

class Liga
{
	std::vector<std::shared_ptr<Tim>> timovi;
public:
	explicit Liga()
	{}
	explicit Liga(std::initializer_list<Tim> lista_timova)
	{
		for(Tim x : lista_timova) timovi.push_back(std::make_shared<Tim>(x.DajImeTima()));
	}
	Liga(const Liga &l)
	{
		for(int i = 0; i < l.timovi.size(); i++)
			timovi.push_back(std::make_shared<Tim>(*(l.timovi[i])));
	}
	Liga(Liga &&l)
	{
		timovi = l.timovi;
		l.timovi.clear();
	}
	Liga &operator =(const Liga &l)
	{
		timovi.clear();
		for(int i = 0; i < l.timovi.size(); i++)
			timovi.push_back(std::make_shared<Tim>(*(l.timovi[i])));
		return *this;
	}
	Liga &operator =(Liga &&l)
	{
		timovi = l.timovi;
		l.timovi.clear();
		return *this;
	}
	void DodajNoviTim(const char ime_tima[])
	{
		if(std::strlen(ime_tima) > 19) throw std::range_error("Predugacko ime tima");
		for(int i = 0; i < timovi.size(); i++)
			if(std::strcmp(timovi[i]->DajImeTima(), ime_tima) == 0) throw std::logic_error("Tim vec postoji");
		timovi.push_back(std::make_shared<Tim>(ime_tima));
	}
	void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2)
	{
		if(rezultat_1 < 0 || rezultat_2 < 0) throw std::range_error("Neispravan broj golova");
		bool postoji1 = false, postoji2 = false;
		std::shared_ptr<Tim> t1 = nullptr, t2 = nullptr;
		for(int i = 0; i < timovi.size(); i++) {
			if(std::strcmp(timovi[i]->DajImeTima(), tim1) == 0) {
				postoji1 = true;
				t1 = (timovi[i]);
			}
			if(std::strcmp(timovi[i]->DajImeTima(), tim2) == 0) {
				postoji2 = true;
				t2 = (timovi[i]);
			}
		}
		if(!postoji1 || !postoji2) throw std::logic_error("Tim nije nadjen");
		t1->ObradiUtakmicu(rezultat_1, rezultat_2);
		t2->ObradiUtakmicu(rezultat_2, rezultat_1);
	}
	static bool Kriterij(std::shared_ptr<Tim> a, std::shared_ptr<Tim> b)
	{
		if(a->DajBrojPoena() == b->DajBrojPoena()) {
			if(a->DajGolRazliku() > b->DajGolRazliku()) return true;
			else if(a->DajGolRazliku() < b->DajGolRazliku()) return false;
			if(std::strcmp(a->DajImeTima(), b->DajImeTima()) > 0) return false;
			return true;
		} else if(a->DajBrojPoena() > b->DajBrojPoena()) return true;
		else return false;
	}
	void IspisiTabelu()
	{
		std::sort(timovi.begin(), timovi.end(), Kriterij);
		for(int i = 0; i < timovi.size(); i++) (*timovi[i]).IspisiPodatke();
	}
};

int main ()
{
	return 0;
}
