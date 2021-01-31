//TP 2018/2019: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <map>
#include <set>

std::map<std::string, std::set<int>> KreirajIndeksPojmova (std::string string)
{
    std::string s = string;
    std::map<std::string, std::set<int>> mapa;
    for(int i = 0; i < s.length(); i++) s.at(i) = tolower(s.at(i));
    for(int i = 0; i < s.length(); i++) {
        if((s.at(i) >= 'a' && s.at(i) <= 'z') || (s.at(i) >= '0' && s.at(i) <= '9')) {
            int broj_indeksa = i;
            int j = i;
            while(j < s.length() && ((s.at(j) >= 'a' && s.at(j) <= 'z') || (s.at(j) >= '0' && s.at(j) <= '9'))) j++;
            std::string rijec;
            while(i != j) {
                rijec.push_back(s.at(i));
                i++;
            }
            mapa[rijec].insert(broj_indeksa);
        }
    }
    return mapa;
}

std::set<int> PretraziIndeksPojmova (std::string pojam, std::map<std::string, std::set<int>> mapa)
{
    auto it = mapa.find(pojam);
    if(it == mapa.end()) throw std::logic_error("Unesena rijec nije nadjena!");
    return mapa[pojam];
}


void IspisiIndeksPojmova (std::map<std::string, std::set<int>> mapa)
{
    for(auto it = mapa.begin(); it != mapa.end(); it++) {
        std::cout << it->first << ": ";
        for(auto it2 = (it->second).begin(); it2 != (it->second).end(); it2++) {
            if(it2 != --(it->second).end())
                std::cout << *it2 << ",";
            else std::cout << *it2 <<std::endl;
        }
    }
}

int main ()
{
    std::string tekst;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, tekst);
    auto indeks_pojmova = KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(indeks_pojmova);

    std::string rijec;
    do {
        rijec = "";
        std::cout << "Unesite rijec: ";
        std::getline(std::cin, rijec);
        if(rijec != ".")
            try {
                auto skup = PretraziIndeksPojmova(rijec, indeks_pojmova);
                for(int x : skup) std::cout << x << " ";
                std::cout << std::endl;
            } catch(std::logic_error e) {
                std::cout << e.what() << std::endl;
            }
    } while(rijec != ".");


    return 0;
}
