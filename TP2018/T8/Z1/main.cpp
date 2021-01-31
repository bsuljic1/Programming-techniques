//TP 2018/2019: Tutorijal 8, Zadatak 1
#include <iostream>
#include <iomanip>


struct Vrijeme {
    int sati, minute, sekunde;
};

void TestirajVrijeme (Vrijeme vrijeme)
{
    if(vrijeme.sati < 0 || vrijeme.sati > 23 || vrijeme.minute < 0 || vrijeme.minute > 59 || vrijeme.sekunde < 0 || vrijeme.sekunde > 59)
        throw std::domain_error("Neispravno vrijeme");
}

void IspisiVrijeme (Vrijeme vrijeme)
{
    TestirajVrijeme(vrijeme);
    std::cout << std::setw(2) << std::setfill('0') << vrijeme.sati << ":" << std::setw(2) << std::setfill('0') << vrijeme.minute << ":" << std::setw(2) << std::setfill('0') << vrijeme.sekunde;
}

Vrijeme SaberiVrijeme (Vrijeme v1, Vrijeme v2)
{
    TestirajVrijeme(v1);
    TestirajVrijeme(v2);
    int s = v1.sekunde + v2.sekunde;
    int m = v1.minute + v2.minute;
    int h = v1.sati + v2.sati;

    while(s >= 60) {
        m += 1;
        s -= 60;
    }

    while(m >= 60) {
        h += 1;
        m -= 60;
    }

    if(h >= 24) h -= 24;
    if(m >= 60) m -= 60;
    if(s >= 60) s -= 60;

    Vrijeme novo{h, m, s};
    return novo;
}


int main ()
{
    std::cout << "Unesite prvo vrijeme (h m s): ";
    Vrijeme prvo;
    std::cin >> prvo.sati >> prvo.minute >> prvo.sekunde;
    if(prvo.sati < 0 || prvo.sati > 23 || prvo.minute < 0 || prvo.minute > 59 || prvo.sekunde < 0 || prvo.sekunde > 59) {
        std::cout << "Neispravno vrijeme";
        return 0;
    }

    std::cout << "Unesite drugo vrijeme (h m s): ";
    Vrijeme drugo;
    std::cin >> drugo.sati >> drugo.minute >> drugo.sekunde;
    if(drugo.sati < 0 || drugo.sati > 23 || drugo.minute < 0 || drugo.minute > 59 || drugo.sekunde < 0 || drugo.sekunde > 59) {
        std::cout << "Neispravno vrijeme";
        return 0;
    }

    std::cout << "Prvo vrijeme: " << std::setw(2) << std::setfill('0') << prvo.sati << ":" << std::setw(2) << std::setfill('0') << prvo.minute << ":" << std::setw(2) << std::setfill('0') << prvo.sekunde << std::endl;
    std::cout << "Drugo vrijeme: " << std::setw(2) << std::setfill('0') << drugo.sati << ":" << std::setw(2) << std::setfill('0') << drugo.minute << ":" << std::setw(2) << std::setfill('0') << drugo.sekunde << std::endl;
    Vrijeme zbir = SaberiVrijeme(prvo, drugo);
    std::cout << "Zbir vremena: " << std::setw(2) << std::setfill('0') << zbir.sati << ":" << std::setw(2) << std::setfill('0') << zbir.minute << ":" << std::setw(2) << std::setfill('0') << zbir.sekunde << std::endl;

    return 0;
}
