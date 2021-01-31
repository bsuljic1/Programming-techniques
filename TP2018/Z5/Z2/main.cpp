//TP 2018/2019: Zadaća 5, Zadatak 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <iterator>

class Berza
{
    int minimalna, maksimalna;
    std::vector<int> v;
public:
    Berza(int min, int max);
    explicit Berza(int max);
    void RegistrirajCijenu(int cijena);
    int DajBrojRegistriranihCijena() const
    {
        return v.size();
    }
    void BrisiSve()
    {
        v.clear();
    }
    int DajMinimalnuCijenu() const;
    int DajMaksimalnuCijenu() const;
    int DajBrojVecihOd(int vrijednost) const;
    void Ispisi() const;
    bool operator !() const
    {
        if(v.size() == 0) return false;
        else return true;
    }
    int operator [](int indeks) const;
    Berza &operator ++();
    Berza &operator ++(int);
    Berza &operator --();
    Berza &operator --(int);
    Berza operator -() const;
    Berza operator +(int broj) const;
    Berza operator -(int broj) const;
    Berza operator -(const Berza &b) const;
    Berza &operator +=(int broj);
    Berza &operator -=(int broj);
    Berza &operator -=(const Berza &b);
    bool operator ==(const Berza &b) const;
    bool operator !=(const Berza &b) const;
    friend Berza operator+(int broj, Berza b);
    friend Berza operator-(int broj, Berza &b);
};

Berza::Berza(int min, int max)
{
    if(min < 0 || max < 0) throw std::range_error("Ilegalne granicne cijene");
    minimalna = min;
    maksimalna = max;
}
Berza::Berza(int max)
{
    if(max < 0) throw std::range_error("Ilegalne granicne cijene");
    minimalna = 0;
    maksimalna = max;
}
int Berza::DajMinimalnuCijenu() const
{
    if(v.size() == 0) throw std::range_error("Nema registriranih cijena");
    return *std::min_element(v.begin(), v.end());
}
int Berza::DajMaksimalnuCijenu() const
{
    if(v.size() == 0) throw std::range_error("Nema registriranih cijena");
    return *std::max_element(v.begin(), v.end());
}
void Berza::RegistrirajCijenu(int cijena)
{
    if(cijena < minimalna || cijena > maksimalna) throw std::domain_error("Ilegalna cijena");
    v.push_back(cijena);
}
int Berza::DajBrojVecihOd(int vrijednost) const
{
    if(v.size() == 0) throw std::range_error("Nema registriranih cijena");
    return std::count_if(v.begin(), v.end(), std::bind(std::less<int>(), vrijednost, std::placeholders::_1));
}
void Berza::Ispisi() const
{
    std::vector<double> pom(v.size());
    std::transform(v.begin(), v.end(), pom.begin(), std::bind(std::divides<double>(), std::placeholders::_1, 100));
    std::sort(pom.begin(), pom.end(), std::greater<double>());
    std::cout << std::fixed << std::setprecision(2);
    std::copy(pom.begin(), pom.end(), std::ostream_iterator<double>(std::cout, "\n"));
}
int Berza::operator [](int indeks) const
{
    if(indeks < 0 || indeks > v.size()) throw std::range_error("Neispravan indeks");
    return v.at(indeks-1);
}
Berza &Berza::operator ++()
{
    if(DajMaksimalnuCijenu() + 100 > maksimalna) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(v.begin(), v.end(), v.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
    return *this;
}
Berza &Berza::operator ++(int)
{
    if(DajMaksimalnuCijenu() + 100 > maksimalna) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(v.begin(), v.end(), v.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
    return *this;
}
Berza &Berza::operator --()
{
    if(DajMinimalnuCijenu()-100 < minimalna) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(v.begin(), v.end(), v.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 100));
    return *this;
}
Berza &Berza::operator --(int)
{
    if(DajMinimalnuCijenu()-100 < minimalna) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(v.begin(), v.end(), v.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 100));
    return *this;
}
Berza Berza::operator -() const
{
    Berza b = *this;
    int zbir = maksimalna + minimalna;
    std::transform(b.v.begin(), b.v.end(), b.v.begin(), std::bind(std::minus<int>(), std::placeholders::_1, zbir));
    return b;
}
Berza Berza::operator +(int broj) const
{
    if(DajMaksimalnuCijenu()+broj > maksimalna) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    auto x = *this;
    std::transform(x.v.begin(), x.v.end(), x.v.begin(), std::bind(std::plus<int>(), std::placeholders::_1, broj));
    return *this;
}
Berza operator+(int broj, Berza b)
{
    
    if(b.DajMaksimalnuCijenu()+broj > b.maksimalna) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(b.v.begin(), b.v.end(), b.v.begin(), std::bind(std::plus<int>(), std::placeholders::_1, broj));
    return b;
}
Berza Berza::operator -(int broj) const
{
    auto nova = *this;
    if(DajMinimalnuCijenu() - broj < minimalna) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(nova.v.begin(), nova.v.end(), nova.v.begin(), std::bind(std::minus<int>(), std::placeholders::_1, broj));
    return nova;
}
Berza operator -(int broj, Berza &b)
{
    if(b.DajMinimalnuCijenu() - broj < b.minimalna) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(b.v.begin(), b.v.end(), b.v.begin(), std::bind(std::minus<int>(), broj, std::placeholders::_1));
    return b;
}
Berza Berza::operator -(const Berza &b) const
{
    Berza razlika = *this;
    if(maksimalna != b.maksimalna || minimalna != b.minimalna || v.size() != b.v.size()) throw std::domain_error("Nesaglasni parametri");
    std::transform(razlika.v.begin(), razlika.v.end(), b.v.begin(),  razlika.v.begin(), std::minus<int>());
    if(razlika.DajMinimalnuCijenu() < minimalna) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return razlika;
}
Berza &Berza::operator +=(int broj)
{
    return *this = *this + broj;
}
Berza &Berza::operator -=(int broj)
{
    return *this = *this - broj;
}
Berza &Berza::operator -=(const Berza &b)
{
    return *this = *this - b;
}
bool Berza::operator ==(const Berza &b) const
{
    if(v.size() != b.v.size()) return false;
    return std::equal(v.begin(), v.end(), b.v.begin());
}
bool Berza::operator !=(const Berza &b) const
{
    if(v.size() != b.v.size()) return true;
    return !std::equal(v.begin(), v.end(), b.v.begin());
}
int main ()
{
    return 0;
}
