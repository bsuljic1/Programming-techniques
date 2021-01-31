/*
    TP 16/17 (Tutorijal 11, Zadatak 3)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cstring>
#include <iomanip>

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


int main ()
{
	return 0;
}
