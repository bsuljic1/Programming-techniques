//TP 2018/2019: Tutorijal 14, Zadatak 2
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

class Spremnik
{
protected:
    double tezina;
    std::string ime;
public:
    Spremnik(double tezina, const char ime[]) : tezina(tezina), ime(ime) {}
    virtual ~Spremnik() {}
    double DajTezinu() const
    {
        return tezina;
    }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual Spremnik *DajKopiju() const = 0;
};

class Sanduk : public Spremnik
{
    int broj_predmeta;
    double tezina_predmeta;
public:
    Sanduk(double tezina, const char ime[], int brojpredmeta, double tezinapredmeta) : Spremnik(tezina, ime), broj_predmeta(brojpredmeta), tezina_predmeta(tezinapredmeta) {}
    double DajUkupnuTezinu() const override
    {
        return DajTezinu() + tezina_predmeta*broj_predmeta;
    }
    void Ispisi() const override
    {
        std::cout << "Vrsta spremnika: Sanduk" << std::endl
                  << "Sadrzaj: " << ime << std::endl
                  << "Vlastita tezina: " << DajTezinu() << " kg" << std::endl
                  << "Ukupna tezina: " << DajUkupnuTezinu() << " kg"<< std::endl;
    }
    Spremnik *DajKopiju() const override
    {
        return new Sanduk(*this);
    }
};

class Bure : public Spremnik
{
    double tezina_tecnosti;
public:
    Bure(double tezina, const char ime[], double tezinatecnosti) : Spremnik(tezina, ime), tezina_tecnosti(tezinatecnosti) {}
    double DajUkupnuTezinu() const override
    {
        return DajTezinu() + tezina_tecnosti;
    }
    void Ispisi() const override
    {
        std::cout << "Vrsta spremnika: Bure" << std::endl
                  << "Sadrzaj: " << ime << std::endl
                  << "Vlastita tezina: " << DajTezinu() << " kg" << std::endl
                  << "Ukupna tezina: " << DajUkupnuTezinu() << " kg" << std::endl;
    }
    Spremnik *DajKopiju() const override
    {
        return new Bure(*this);
    }
};

class Skladiste
{
    Spremnik **pok;
    int br_el;
    int max_br_el;
public:
    explicit Skladiste(int max) : max_br_el(max), br_el(0)
    {
        pok = new Spremnik*[max];
    }
    ~Skladiste()
    {
        if(pok != nullptr)
            for(int i = 0; i < br_el; i++) delete pok[i];
        delete[] pok;
    }
    Skladiste(const Skladiste &s) : max_br_el(s.max_br_el), br_el(s.br_el)
    {
        pok = new Spremnik*[max_br_el];
        for(int i = 0; i < s.br_el; i++)
            pok[i] = s.pok[i]->DajKopiju();
    }
    Skladiste &operator=(const Skladiste &s)
    {
        max_br_el = s.max_br_el;
        br_el = s.br_el;
        pok = new Spremnik*[max_br_el];
        for(int i = 0; i < s.br_el; i++)
            pok[i] = s.pok[i]->DajKopiju();
        return *this;
    }
    void DodajSanduk(double tezina, const char ime[], int brojpredmeta, double tezinapredmeta)
    {
        if(br_el == max_br_el) throw std::domain_error("Popunjeno skladiste");
        pok[br_el] = new Sanduk(tezina, ime, brojpredmeta, tezinapredmeta);
        br_el++;
    }
    void DodajBure(double tezina, const char ime[], double tezinatecnosti)
    {
        if(br_el == max_br_el) throw std::domain_error("Popunjeno skladiste");
        pok[br_el] = new Bure(tezina, ime, tezinatecnosti);
        br_el++;
    }
    Spremnik &DajNajlaksi()
    {
        if(br_el == 0) throw std::range_error("Skladiste je prazno");
        int najlaksi = 0;
        for(int i = 1; i < br_el; i++)
            if(pok[i]->DajTezinu() < pok[najlaksi]->DajTezinu()) najlaksi = i;
        return *pok[najlaksi];

    }
    Spremnik &DajNajtezi()
    {
        if(br_el == 0) throw std::range_error("Skladiste je prazno");
        int najtezi = 0;
        for(int i = 1; i < br_el; i++)
            if(pok[i]->DajTezinu() > pok[najtezi]->DajTezinu()) najtezi = i;
        return *pok[najtezi];
    }
    int BrojPreteskih(int x) const
    {
        if(br_el == 0) throw std::range_error("Skladiste je prazno");
        int broj = 0;
        for(int i = 0; i < br_el; i++)
            if(pok[i]->DajUkupnuTezinu() > x) broj++;
        return broj;
    }
    void IzlistajSkladiste() const
    {
        if(br_el == 0) throw std::range_error("Skladiste je prazno");
        auto temp = new Spremnik*[br_el];
        std::copy(pok, pok + br_el, temp);
        std::sort(temp, temp + br_el,[](Spremnik *s1, Spremnik *s2) {
            return s1->DajUkupnuTezinu() > s2->DajUkupnuTezinu();
        });
        for(int i = 0; i < br_el; i++) temp[i]->Ispisi();
        delete[] temp;
    }
    void UcitajIzDatoteke(std::string ime)
    {
        if(br_el != 0)
            for(int i = 0; i < br_el; i++) delete pok[i];
        std::ifstream ulazni(ime);
        if(!ulazni) throw std::logic_error("Trazena datoteka ne postoji");
        while(!(ulazni >> std::ws).eof()) {
            char slovo;
            ulazni >> slovo >> std::ws;
            if(slovo == 'S') {
                std::string naziv;
                std::getline(ulazni, naziv);
                double tezina_sanduka, tezinapr;
                int broj;
                ulazni >> tezina_sanduka >> std::ws >> broj >> std::ws >> tezinapr;
                try {
                    DodajSanduk(tezina_sanduka, naziv.c_str(), broj, tezinapr);
                } catch(...) {
                    throw std::logic_error("Problemi pri citanju datoteke");
                }
            } else if(slovo == 'B') {
                std::string naziv;
                std::getline(ulazni, naziv);
                double tezina_bureta, tezinatec;
                ulazni >> tezina_bureta >> std::ws >> tezinatec;
                try {
                    DodajBure(tezina_bureta, naziv.c_str(), tezinatec);
                } catch(...) {
                    throw std::logic_error("Problemi pri citanju datoteke");
                }
            } else {
                throw std::logic_error("Datoteka sadrzi besmislene podatke");
            }
        }
    }
};

int main ()
{
    Skladiste s(12);
    s.UcitajIzDatoteke("ROBA.TXT");
    s.IzlistajSkladiste();
    return 0;
}
