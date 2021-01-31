//TP 2017/2018: Tutorijal 3, Zadatak 2
#include <iostream>
#include <vector>

int SumaCifara (int x)
{
    int suma = 0;
    while(x != 0) {
        suma += (x % 10);
        x /= 10;
    }
    return suma;
}

std::vector<int> IzdvojiElemente(std::vector<int> s, bool a)
{
    std::vector<int> v;
    if(a == true) {
        for(int x : s)
            if((SumaCifara(x)) % 2 == 0) v.push_back(x);
    } else {
        for(int x : s)
            if((SumaCifara(x)) % 2 != 0) v.push_back(x);
    }
    return v;
}

int main ()
{
    int n;
    std::cout << "Koliko zelite unijeti elemenata: ";
    std::cin >> n;
    if(n <= 0) {
        std::cout << "Broj elemenata mora biti veci od 0!";
        return 0;
    }

    std::cout << "Unesite elemente: ";
    std::vector<int> a;
    for(int i = 0; i < n; i++) {
        int y;
        std::cin >> y;
        a.push_back(y);
    }

    std::vector<int> b(IzdvojiElemente(a, true));
    std::vector<int> c(IzdvojiElemente(a, false));


    for(int i = 0; i < b.size(); i++){
        if(i == b.size()-1) std::cout << b.at(i);
        else std::cout << b.at(i) << ",";
    }
    std::cout << std::endl;
    for(int i = 0; i < c.size(); i++){
        if(i == c.size()-1) std::cout << c.at(i);
        else std::cout << c.at(i) << ",";
    }
    std::cout << std::endl;

    return 0;
}

