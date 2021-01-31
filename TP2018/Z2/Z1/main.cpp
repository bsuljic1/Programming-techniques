/* TP, 2018/2019
*/
#include <iostream>

bool aktiviran = true;
enum class Smjer {Nalijevo, Nadesno};
enum class Pravci {Sjever, Istok, Jug, Zapad};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {Aktiviraj, Deaktiviraj, Nalijevo, Nadesno, Idi, Kraj};


void AktivirajRobota()
{
    aktiviran = true;
}

void DeaktivirajRobota()
{
    aktiviran = false;
}

void Rotiraj(Pravci &orijentacija, Smjer na_koju_stranu)
{
    if(na_koju_stranu == Smjer::Nalijevo) {
        if(orijentacija == Pravci::Sjever) orijentacija = Pravci::Zapad;
        else if(orijentacija == Pravci::Istok) orijentacija = Pravci::Sjever;
        else if(orijentacija == Pravci::Jug) orijentacija = Pravci::Istok;
        else orijentacija = Pravci::Jug;
    } else {
        if(orijentacija == Pravci::Sjever) orijentacija = Pravci::Istok;
        else if(orijentacija == Pravci::Istok) orijentacija = Pravci::Jug;
        else if(orijentacija == Pravci::Jug) orijentacija = Pravci::Zapad;
        else orijentacija = Pravci::Sjever;
    }
}

void Idi(int &x, int &y, Pravci orijentacija, int korak)
{
    if(orijentacija == Pravci::Sjever) y += korak;
    else if(orijentacija == Pravci::Istok) x += korak;
    else if(orijentacija == Pravci::Jug) y -= korak;
    else x -= korak;
}

void IspisiPoziciju(int x, int y, Pravci orijentacija)
{
    std::cout << "Robot je trenutno ";
    if(aktiviran) std::cout << "aktivan";
    else std::cout << "neaktivan";
    std::cout << ", nalazi se na poziciji (" << x << "," << y <<") i gleda na ";
    if(orijentacija == Pravci::Sjever) std::cout << "sjever.";
    else if(orijentacija == Pravci::Istok) std::cout << "istok.";
    else if(orijentacija == Pravci::Jug) std::cout << "jug.";
    else std::cout << "zapad.";
}

void PrijaviGresku(KodoviGresaka kod_greske)
{
    if(kod_greske == KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl;
    else if(kod_greske == KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
    else if(kod_greske == KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!" << std::endl;
    else std::cout << "Zadan je suvisan parametar nakon komande!"<< std::endl;
}

void IzvrsiKomandu(Komande komanda, int parametar, int &x, int &y, Pravci &orijentacija)
{
    if(komanda == Komande::Aktiviraj) AktivirajRobota();
    else if(!aktiviran) return;
    else if(komanda == Komande::Deaktiviraj) DeaktivirajRobota();
    else if(komanda == Komande::Nalijevo) Rotiraj(orijentacija, Smjer::Nalijevo);
    else if(komanda == Komande::Nadesno) Rotiraj(orijentacija, Smjer::Nadesno);
    else if(komanda == Komande::Idi) Idi(x, y, orijentacija, parametar);
}

bool UnosKomande(Komande &komanda, int &parametar, KodoviGresaka &kod_greske)
{
    while(std::cin.peek() == ' ') {
        std::cin.get();
    }
    switch(std::cin.get()) {
    case 'A':
        switch(std::cin.get()) {
        case '+':
            while(std::cin.peek() == ' ') {
                std::cin.get();
            }
            if(std::cin.peek() == '\n') {
                komanda = Komande::Aktiviraj;
                return true;
            } else {
                kod_greske = KodoviGresaka::SuvisanParametar;
                return false;
            }
        case '-':
            while(std::cin.peek() == ' ') {
                std::cin.get();
            }
            if(std::cin.peek() == '\n') {
                komanda = Komande::Deaktiviraj;
                return true;
            } else {
                kod_greske = KodoviGresaka::SuvisanParametar;
                return false;
            }
        default:
            kod_greske = KodoviGresaka::PogresnaKomanda;
            return false;
        }
    case 'L':
        while(std::cin.peek() == ' ') {
            std::cin.get();
        }
        if(std::cin.peek() == '\n') {
            komanda = Komande::Nalijevo;
            return true;
        } else {
            kod_greske = KodoviGresaka::SuvisanParametar;
            return false;
        }
    case 'D':
        while(std::cin.peek() == ' ') {
            std::cin.get();
        }
        if(std::cin.peek() == '\n') {
            komanda = Komande::Nadesno;
            return true;
        } else {
            kod_greske = KodoviGresaka::SuvisanParametar;
            return false;
        }
    case 'I':
        while(std::cin.peek() == ' ') {
            std::cin.get();
        }
        if(std::cin.peek() == '\n') {
            kod_greske = KodoviGresaka::NedostajeParametar;
            return false;
        } else {
            std::cin >> parametar;
            if(std::cin) {
                while(std::cin.peek() == ' ') {
                    std::cin.get();
                }
                if(std::cin.peek() == '\n') {
                    komanda = Komande::Idi;
                    return true;
                } else {
                    kod_greske = KodoviGresaka::SuvisanParametar;
                    return false;
                }

            } else {
                kod_greske = KodoviGresaka::NeispravanParametar;
                std::cin.clear();
                return false;
            }
        }
    case 'K':
        while(std::cin.peek() == ' ') {
            std::cin.get();
        }
        if(std::cin.peek() == '\n') {
            komanda = Komande::Kraj;
            return true;
        } else {
            kod_greske = KodoviGresaka::SuvisanParametar;
            return false;
        }
    default:
        kod_greske = KodoviGresaka::PogresnaKomanda;
        return false;
    }
}

int main ()
{
    int x = 0, y = 0, parametar = 0;
    Pravci orijentacija = Pravci::Sjever;
    Komande komanda = Komande::Idi;
    KodoviGresaka kod_greske;
    bool uspjesnaKomanda = true;
    do {
        if(uspjesnaKomanda) {
            IspisiPoziciju(x, y, orijentacija);
            std::cout << std::endl;
        }
        std::cout << "Unesi komandu: ";
        uspjesnaKomanda = UnosKomande(komanda, parametar, kod_greske);
        if(uspjesnaKomanda)
            IzvrsiKomandu(komanda, parametar, x, y, orijentacija);
        else
            PrijaviGresku(kod_greske);
        std::cin.ignore(10000, '\n');
        std::cin.clear();
    } while(komanda != Komande::Kraj);

    std::cout << "Dovidjenja!";

    return 0;
}
