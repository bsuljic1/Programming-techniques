/* TP, 2018/2019
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

template <typename NekiTip>
bool ZaSve (NekiTip p1, NekiTip p2, bool f(typename std::remove_reference<decltype(*p1)>::type))
{
    while(p1 != p2) {
        if(f(*p1) == false) return false;
        p1++;
    }
    return true;
}

template <typename NekiTip>
bool MakarJedan (NekiTip p1, NekiTip p2, bool f(typename std::remove_reference<decltype(*p1)>::type))
{
    while(p1 != p2) {
        if(f(*p1) == true) return true;
        p1++;
    }
    return false;
}

template <typename NekiTip>
auto Akumuliraj (NekiTip p1, NekiTip p2, typename std::remove_reference<decltype(*p1)>::type f(typename std::remove_reference<decltype(*p1)>::type, typename std::remove_reference<decltype(*p1)>::type), int a0 = 0) -> typename std::remove_reference<decltype(*p1)>::type
{
    if(p1 == p2) return a0;
    int rezultat = f(a0, *p1);
    p1++;
    while(p1 != p2) {
        rezultat = f(rezultat, *p1);
        p1++;
    }
    return rezultat;
}

int main ()
{
    std::string s;
    std::cout << "Unesite string: ";
    std::getline(std::cin, s);
    bool sve = ZaSve(s.begin(), s.end(), [](char a) {
        if((a >= 'A' && a <= 'z') || (a >= '0' && a <= '9')) return true;
        return false;
    });
    if(sve) std::cout << "Uneseni string sadrzi samo slova i cifre" << std::endl;
    else std::cout << "Uneseni string sadrzi i druge znakove osim slova i cifara" << std::endl;

    int niz[10];
    std::cout << "Unesite niz od 10 brojeva: ";
    std::for_each(niz, niz + 10, [](int &a) {
        std::cin >> a;
    });
    bool makar_jedan = MakarJedan(niz, niz + 10, [](int a) -> bool {
        int suma = 0;
        int a_novo = abs(a);
        while(a_novo != 0)
        {
            suma += a_novo %10;
            a_novo /= 10;
        }
        if(a % suma == 0) return true;
        return false;
    });
    if(makar_jedan) std::cout << "U nizu ima brojeva djeljivih sa sumom svojih cifara" << std::endl;
    else std::cout << "U nizu nema brojeva djeljivih sa sumom svojih cifara" << std::endl;

    std::deque<double> dek(10);
    std::cout << "Unesite dek od 10 elemenata: ";
    std::for_each(dek.begin(), dek.end(), [](double &a) {
        std::cin >> a;
    });

    std::cout << std::endl << "Suma deka: " << Akumuliraj(dek.begin(), dek.end(), [](double a, double b) {
        return a + b;
    }) << std::endl;
    std::cout << "Produkt deka: " << Akumuliraj(dek.begin(), dek.end(), [](double a, double b) {
        return a * b;
    }, 1) << std::endl;
    std::cout << "Najveci elemenat deka: " << Akumuliraj(dek.begin(), dek.end(), [](double a, double b) {
        if(a > b) return a;
        return b;
    }) << std::endl;
    std::cout << "Najmanji elemenat deka: " << Akumuliraj(dek.begin(), dek.end(), [](double a, double b){
        if(a < b) return a;
        return b;
    }) << std::endl;

    return 0;
}
