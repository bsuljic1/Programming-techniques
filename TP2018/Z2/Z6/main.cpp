#include <iostream>
#include <string>
#include <algorithm>

std::string StaviNaMala (std::string s)
{
    for(int i = 0; i < s.size(); i++) {
        s.at(i) = std::tolower(s.at(i));
    }
    return s;
}

bool KriterijSortiranja (std::string s1, std::string s2)
{
    if(s1.size() < s2.size()) return true;
    else if(s1.size() > s2.size()) return false;
    return (StaviNaMala(s1) < StaviNaMala(s2));
}

void SortirajPoDuzini (std::string *p1, int broj_elemenata)
{
    std::sort(p1, p1 + broj_elemenata, KriterijSortiranja);

}

bool PretraziBinarno (std::string *p1, int broj_elemenata, std::string rijec)
{
    return std::binary_search(p1, p1 + broj_elemenata, rijec, KriterijSortiranja);
}

int main()
{
    int n;
    std::cout << "Unesite broj rijeci: ";
    std::cin >> n;
    std::cin.ignore(10000, ' ');
    std::string *niz = new std::string[n];
    std::cout << "Unesite rijeci: ";
    for(int i = 0; i < n; i++) {
        std::getline(std::cin, *niz, ' ');
        niz++;
    }
    niz -= n;

    SortirajPoDuzini(niz, n);
    std::cout << "Sortirane rijeci:";
    for(int i = 0; i < n; i++){
        std::cout << " " << *niz;
        niz++;
    }
    niz -= n;

    std::cout << std::endl << "Unesite rijec za pretragu: ";
    std::string rijec;
    std::getline(std::cin, rijec, '\n');

    bool binarno = PretraziBinarno(niz, n, rijec);
    if(binarno) std::cout << "Rijec '" << rijec << "' se nalazi u nizu.";
    else std::cout << "Rijec '" << rijec << "' se ne nalazi u nizu.";

    delete[] niz;
    return 0;
}
