//TP 2018/2019: Tutorijal 8, Zadatak 6
#include <iostream>

template<typename TipElemenata>
struct Cvor {
    TipElemenata element;
    Cvor* struktura;
};

template<typename TipElemenata>
Cvor<TipElemenata> *KreirajPovezanuListu(TipElemenata zavrsni)
{
    Cvor<TipElemenata> *pocetak = nullptr, *prethodni;
    for(;;) {
        TipElemenata broj;
        std::cin >> broj;
        if(broj == zavrsni) break;
        Cvor<TipElemenata> *novi = new Cvor<TipElemenata>{broj, nullptr};
        if(!pocetak) pocetak = novi;
        else prethodni->struktura = novi;
        prethodni = novi;
    }
    return pocetak;
}

template<typename TipElemenata>
int BrojElemenata(Cvor<TipElemenata> *pocetak)
{
    if(pocetak == nullptr) return 0;
    int broj_elemenata = 0;
    while(!!pocetak) {
        broj_elemenata++;;
        pocetak = pocetak->struktura;
    }
    return broj_elemenata;
}

template<typename TipElemenata>
TipElemenata SumaElemenata(Cvor<TipElemenata> *pocetak)
{
    TipElemenata suma{};
    while(!!pocetak) {
        suma += pocetak->element;
        pocetak = pocetak->struktura;
    }
    return suma;
}

template<typename TipElemenata>
int BrojVecihOd(Cvor<TipElemenata> *pocetak, TipElemenata prag)
{
    if(!pocetak) return 0;
    int broj_vecih = 0;
    while(!!pocetak) {
        if(pocetak->element > prag) broj_vecih++;
        pocetak = pocetak->struktura;
    }
    return broj_vecih;
}

template<typename TipElemenata>
void UnistiListu(Cvor<TipElemenata> *pocetak)
{
    while(pocetak) {
        auto next = pocetak->struktura;
        delete pocetak;
        pocetak = next;
    }
}

int main ()
{
    std::cout << "Unesite slijed brojeva (0 za kraj): ";
    auto pocetak = KreirajPovezanuListu<double>(0);
    std::cout <<"U slijedu ima " << BrojVecihOd(pocetak, SumaElemenata(pocetak)/BrojElemenata(pocetak)) <<" brojeva vecih od njihove aritmeticke sredine";
    UnistiListu(pocetak);
    return 0;
}
