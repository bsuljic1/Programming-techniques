//TP 2018/2019: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <iomanip>
#include <algorithm>

class Datum
{
    int d, m, g;
public:
    Datum(int dan, int mjesec, int godina)
    {
        Postavi(dan, mjesec, godina);
    }
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const
    {
        return std::make_tuple(d, m, g);
    }
    void Ispisi() const
    {
        std::cout << d << "/" << m << "/" << g;
    }
};

class Vrijeme
{
    int sat, min;
public:
    Vrijeme(int sati, int minute)
    {
        Postavi(sati, minute);
    }
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj () const
    {
        return std::make_pair(sat, min);
    }
    void Ispisi() const
    {
        std::cout << std::setfill('0') << std::setw(2) << std::right << sat << ":" << std::setw(2) << min << std::setfill(' ');
    }
};

class Pregled
{
    std::string ime;
    Datum datum_pregl;
    Vrijeme vrijeme_pregl;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : datum_pregl(datum_pregleda), vrijeme_pregl(vrijeme_pregleda)
    {
        ime = ime_pacijenta;
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void PromijeniPacijenta(const std::string &ime_pacijenta)
    {
        ime = ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum)
    {
        datum_pregl = novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme)
    {
        vrijeme_pregl = novo_vrijeme;
    }
    void PomjeriDanUnaprijed()
    {
        PromijeniDatum(Datum(std::get<0>(datum_pregl.Ocitaj())+1, std::get<1>(datum_pregl.Ocitaj()), std::get<2>(datum_pregl.Ocitaj())));
    }
    void PomjeriDanUnazad()
    {
        PromijeniDatum(Datum(std::get<0>(datum_pregl.Ocitaj())-1, std::get<1>(datum_pregl.Ocitaj()), std::get<2>(datum_pregl.Ocitaj())));
    }
    std::string DajImePacijenta() const
    {
        return ime;
    }
    Datum DajDatumPregleda() const
    {
        return datum_pregl;
    }
    Vrijeme DajVrijemePregleda() const
    {
        return vrijeme_pregl;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const
    {
        std::cout << std::left << std::setw(30) << ime;
        datum_pregl.Ispisi();
        std::cout << " ";
        vrijeme_pregl.Ispisi();
        std::cout << std::endl;
    }
};

class Pregledi
{
    int br_pregl;
    const int max_br_pregl;
    Pregled **pregl;
public:
    explicit Pregledi(int max_broj_pregleda);
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi()
    {
        if(pregl != nullptr) for(int i = 0; i < br_pregl; i++) delete pregl[i];
        delete[] pregl;
    }
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi)
    {
        if(max_br_pregl != pregledi.max_br_pregl) throw std::range_error("Nisu isti maksimalni brojevi pregleda");
        for(int i = 0; i < br_pregl; i++) delete pregledi.pregl[i];
        for(int i = 0; i < pregledi.DajBrojPregleda(); i++)
            pregl[i] = new Pregled(pregledi.pregl[i]->DajImePacijenta(), pregledi.pregl[i]->DajDatumPregleda(), pregledi.pregl[i]->DajVrijemePregleda());
        br_pregl = pregledi.br_pregl;
        return *this;
    }
    Pregledi &operator =(Pregledi &&pregledi)
    {
        if(max_br_pregl != pregledi.max_br_pregl) throw std::range_error("Nisu isti maksimalni brojevi pregleda");
        std::swap(br_pregl, pregledi.br_pregl);
        std::swap(pregl, pregledi.pregl);
        return *this;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
    {
        if(br_pregl == max_br_pregl) throw std::range_error("Dostignut maksimalni broj pregleda");
        pregl[br_pregl] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
        br_pregl++;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
    {
        if(br_pregl == max_br_pregl) throw std::range_error("Dostignut maksimalni broj pregleda");
        pregl[br_pregl] = new Pregled(ime_pacijenta, dan_pregleda,mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
        br_pregl++;
    }
    void RegistrirajPregled(Pregled *pregled)
    {
        if(br_pregl == max_br_pregl) throw std::range_error("Dostignut maksimalni broj pregleda");
        pregl[br_pregl] = pregled;
        br_pregl++;
    }
    int DajBrojPregleda() const
    {
        return br_pregl;
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const
    {
        return std::count_if(pregl, pregl+br_pregl, [datum](Pregled *p) {
            return p->DajDatumPregleda().Ocitaj() == datum.Ocitaj();
        });
    }
    Pregled &DajNajranijiPregled()
    {
        if(br_pregl == 0) throw std::domain_error("Nema registriranih pregleda");
        return **std::min_element(pregl, pregl+br_pregl, [](Pregled* p1, Pregled* p2) {
            return !Pregled::DolaziPrije(*p2, *p1);
        });
    }
    Pregled DajNajranijiPregled() const
    {
        if(br_pregl == 0) throw std::domain_error("Nema registriranih pregleda");
        return **std::min_element(pregl, pregl+br_pregl, [](Pregled* p1, Pregled* p2) {
            return !Pregled::DolaziPrije(*p2, *p1);
        });
    }
    void IsprazniKolekciju()
    {
        for(int i = 0; i < br_pregl; i++) delete pregl[i];
        br_pregl = 0;
    }
    void ObrisiNajranijiPregled()
    {
        if(br_pregl == 0) throw std::range_error("Prazna kolekcija");
        auto pregled = DajNajranijiPregled();
        int i;
        for(i = 0; i < br_pregl; i++) {
            if(pregl[i]->DajDatumPregleda().Ocitaj() == pregled.DajDatumPregleda().Ocitaj() && pregl[i]->DajVrijemePregleda().Ocitaj() == pregled.DajVrijemePregleda().Ocitaj()) {
                delete pregl[i];
                break;
            }
        }
        for(i++; i < br_pregl; i++) pregl[i-1] = pregl[i];
        br_pregl--;
    }
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta)
    {
        for(int i = 0; i < br_pregl; i++) {
            if(pregl[i]->DajImePacijenta() == ime_pacijenta) {
                delete pregl[i];
                for(int j = i+1; j < br_pregl; j++) pregl[j-1] = pregl[j];
                br_pregl--;
                i--;
            }
        }
    }
    void IspisiPregledeNaDatum(const Datum &datum) const
    {
        Pregled **pregl_copy = new Pregled*[br_pregl];
        auto pok = std::copy_if(pregl, pregl+br_pregl, pregl_copy, [datum](Pregled *p) {
            return p->DajDatumPregleda().Ocitaj() == datum.Ocitaj();
        });
        std::sort(pregl_copy, pok, [datum](Pregled *p1, Pregled *p2) {
            return !Pregled::DolaziPrije(*p2, *p1);
        });
        std::for_each(pregl_copy, pok, [](Pregled *p) {
            p->Ispisi();
        });
        delete[] pregl_copy;
    }
    void IspisiSvePreglede() const
    {
        Pregled **pregl_copy = new Pregled*[br_pregl];
        auto pok = std::copy(pregl, pregl+br_pregl, pregl_copy);
        std::sort(pregl_copy, pok, [](Pregled *p1, Pregled *p2) {
            return !Pregled::DolaziPrije(*p2, *p1);
        });
        std::for_each(pregl_copy, pok, [](Pregled *p) {
            p->Ispisi();
        });
        delete[] pregl_copy;
    }
};

void Datum::Postavi(int dan, int mjesec, int godina)
{

    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
        broj_dana[1]++;
    if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1
            || dan > broj_dana[mjesec - 1])
        throw std::domain_error("Neispravan datum!");
    d = dan;
    m = mjesec;
    g = godina;
}
void Vrijeme::Postavi(int sati, int minute)
{
    if(sati < 0 || sati > 23 || minute < 0 || minute > 59) throw std::domain_error("Neispravno vrijeme");
    sat = sati;
    min = minute;
}
Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : datum_pregl(Datum(dan_pregleda, mjesec_pregleda, godina_pregleda)),
    vrijeme_pregl(Vrijeme(sati_pregleda, minute_pregleda))
{
    ime = ime_pacijenta;
}

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2)
{
    if(std::get<2>(p1.datum_pregl.Ocitaj()) < std::get<2>(p2.datum_pregl.Ocitaj())) return true;
    else if(std::get<2>(p1.datum_pregl.Ocitaj()) > std::get<2>(p2.datum_pregl.Ocitaj())) return false;
    else {
        if(std::get<1>(p1.datum_pregl.Ocitaj()) < std::get<1>(p2.datum_pregl.Ocitaj())) return true;
        else if((std::get<1>(p1.datum_pregl.Ocitaj()) > std::get<1>(p2.datum_pregl.Ocitaj()))) return false;
        else {
            if(std::get<0>(p1.datum_pregl.Ocitaj()) < std::get<0>(p2.datum_pregl.Ocitaj()))return true;
            else if(std::get<0>(p1.datum_pregl.Ocitaj()) > std::get<0>(p2.datum_pregl.Ocitaj())) return false;
        }
    }
    return false;
}

Pregledi::Pregledi(int max_broj_pregleda) : br_pregl(0), max_br_pregl(max_broj_pregleda)
{
    pregl = new Pregled*[max_br_pregl];
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) : br_pregl(spisak_pregleda.size()), max_br_pregl(spisak_pregleda.size()), pregl(new Pregled*[max_br_pregl])
{
    int i = 0;
    for(Pregled x : spisak_pregleda) pregl[i++] = new Pregled(x);
}

Pregledi::Pregledi(const Pregledi &pregledi) : br_pregl(pregledi.DajBrojPregleda()), max_br_pregl(pregledi.max_br_pregl)
{
    pregl = new Pregled*[max_br_pregl];
    for(int i = 0; i < br_pregl; i++)
        pregl[i] = new Pregled(pregledi.pregl[i]->DajImePacijenta(), pregledi.pregl[i]->DajDatumPregleda(), pregledi.pregl[i]->DajVrijemePregleda());
}

Pregledi::Pregledi(Pregledi &&pregledi) : br_pregl(pregledi.br_pregl), max_br_pregl(pregledi.max_br_pregl)
{
    pregl = pregledi.pregl;
    pregledi.pregl = nullptr;
    pregledi.br_pregl = 0;
}


int main ()
{
    std::cout <<"Unesite maksimalan broj pregleda: ";
    int max;
    int broj_pregleda = 0;
    std::cin >> max;
    Pregledi pregledi(max);
    for(int i = 0; i < max; i++) {
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string ime;
        std::cin.ignore(10000, '\n');
        std::cin.clear();
        std::getline(std::cin, ime);
        if(ime == "kraj") break;
        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        int dan, mjesec, godina;
        std::cin >> dan >> mjesec >> godina;
        std::cout << "Unesite sate i minute pregleda: ";
        int sati, minute;
        std::cin >> sati >> minute;
        try {
            pregledi.RegistrirajPregled(ime, dan, mjesec, godina, sati, minute);
            broj_pregleda++;
        } catch(std::domain_error e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
    pregledi.IspisiSvePreglede();
    int opcija = 1;
    while(opcija != 7) {
        std::cout << "Odaberite jednu od sljedecih opcija" << std::endl
                  << "1 - Broj pregleda na datum" << std::endl
                  << "2 - Najraniji pregled" << std::endl
                  << "3 - Obrisi pregled pacijenta" << std::endl
                  << "4 - Obrisi najraniji pregled" << std::endl
                  << "5 - Ispisi sve pregleda na datum" << std::endl
                  << "6 - Ispisi sve preglede" << std::endl
                  << "7 - Kraj programa" << std::endl;
        std::cin >> opcija;
        if(opcija == 1) {
            std::cout << "Unesite dan mjesec i godinu : ";
            int d, m, g;
            std::cin >> d >> m >> g;
            std::cout << "Broj pregleda na datum " << d << " " << m << " " << g << " je: " << pregledi.DajBrojPregledaNaDatum(Datum(d, m, g)) << std::endl;
        } else if(opcija == 2) {
            std::cout << "Najraniji pregled je:" << std::endl;
            pregledi.DajNajranijiPregled().Ispisi();
        } else if(opcija == 3) {
            std::cout << "Unesite ime pacijenta: ";
            std::string pacijent;
            std::cin.ignore(10000, '\n');
            std::cin.clear();
            std::getline(std::cin, pacijent);
            pregledi.ObrisiPregledePacijenta(pacijent);
            std::cout << "Uspjesno obrisano " <<  broj_pregleda - pregledi.DajBrojPregleda() << " pregleda" << std::endl;
        } else if(opcija == 4) {
            pregledi.ObrisiNajranijiPregled();
            std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
        } else if(opcija == 5) {
            std::cout << "Unesite dan mjesec i godinu : ";
            int d, m, g;
            std::cin >> d >> m >> g;
            std::cout <<"Pregledi na datum " << d << " " << m << " " << g << " su:" << std::endl;
            pregledi.IspisiPregledeNaDatum(Datum(d,m,g));
        } else if(opcija == 6)
            pregledi.IspisiSvePreglede();
    }
    return 0;
}
