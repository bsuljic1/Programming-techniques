//TP 2018/2019: Zadaća 3, Zadatak 6
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <memory>

struct Dijete {
    std::string ime;
    std::shared_ptr<Dijete> sljedeci;
};

int BrojSlovaUImenu (std::string s)
{
    int broj_slova = 0;
    for(int i = 0; i < s.length(); i++)
        if((s.at(i) >= 'A' && s.at(i) <= 'z') || (s.at(i) >= '0' && s.at(i) <= '9')) broj_slova++;
    return broj_slova;
}

std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> imena, int broj_timova)
{
    if(broj_timova < 1 || broj_timova > imena.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::vector<std::set<std::string>> timovi(broj_timova);

    int veci = imena.size() % broj_timova;
    //int manji = broj_timova - veci;
    int broj_clanova_1 = imena.size() / broj_timova + 1;
    int broj_clanova_2 = imena.size() / broj_timova;
    int broj_u_timu = 0;
    int index_tima = 0;

    std::shared_ptr<Dijete> pocetak = nullptr, prethodni;

    for(int i = 0; i < imena.size(); i++) {
        auto novi = std::make_shared<Dijete>();
        novi->ime = imena.at(i);
        novi->sljedeci = nullptr;
        if(!pocetak) pocetak = novi;
        else prethodni->sljedeci = novi;
        prethodni = novi;
    }
    prethodni->sljedeci = pocetak;
    auto p = pocetak;
    while(p != p->sljedeci) {
        int broj_slova = BrojSlovaUImenu(p->ime);
        timovi.at(index_tima).insert(p->ime);
        auto previous = p;
        while(previous->sljedeci != p) {
            previous = previous->sljedeci;
        }
        previous->sljedeci = p->sljedeci;
        p = previous->sljedeci;
        broj_u_timu++;
        if((broj_u_timu == broj_clanova_1 ) || (broj_u_timu == broj_clanova_2 && index_tima >= veci)) {
            broj_u_timu = 0;
            index_tima++;
        }
        for(int i = 1; i < broj_slova; i++) p = p->sljedeci;
    }
    timovi.at(index_tima).insert(p->ime);
    p->sljedeci = NULL;
    return timovi;
}

int main ()
{
    std::cout << "Unesite broj djece: ";
    int broj_djece;
    std::cin >> broj_djece;
    std::cout << "Unesite imena djece: ";
    std::vector<std::string> imena(broj_djece);
    std::cin.ignore(10000, '\n');
    for(int i = 0; i < broj_djece; i++)
        std::getline(std::cin, imena.at(i));
    std::cout << "\nUnesite broj timova: ";
    int broj_timova;
    std::cin >> broj_timova;
    try {
        auto timovi = Razvrstavanje(imena, broj_timova);
        for(int i = 0; i < timovi.size(); i++) {
            std::cout << "Tim " << i + 1 << ": ";
            for(auto it = timovi.at(i).begin(); it != timovi.at(i).end(); it++) {
                if(it !=  --(timovi.at(i).end())) std::cout << *it << ", ";
                else std::cout << *it;
            }
            std::cout << std::endl;
        }
    } catch(std::logic_error e) {
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
    return 0;
}
