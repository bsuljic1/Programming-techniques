//TP 2018/2019: Tutorijal 14, Zadatak 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Temperatura{
    int dan, mjesec, godina;
    std::string ime;
    std::vector<int> brojevi;
    double prosjecna;
};

int main ()
{
    std::vector<Temperatura> t;
    std::ifstream ulazni("TEMPERATURE.TXT");
    if(!ulazni) std::cout << "Otvaranje datoteke nije uspjelo!";
    while(!ulazni.eof()){
        Temperatura temp;
        char neki;
        ulazni >> temp.dan >> neki >> temp.mjesec >> neki >> temp.godina >> std::ws;
        std::getline(ulazni, temp.ime, '\n');
        int suma = 0;
        do{
            int number;
            ulazni >> number;
            temp.brojevi.push_back(number);
            suma += number;
        }while(!(ulazni.eof()) && ulazni.get() == ',');
        double prosjek = double(suma) / temp.brojevi.size();
        temp.prosjecna = prosjek;
        t.push_back(temp);
    }
    
    std::sort(t.begin(), t.end(), [](Temperatura t1, Temperatura t2){
        if(t1.godina < t2.godina) return true;
        else if(t1.godina > t2.godina) return false;
        else{
            if(t1.mjesec > t2.mjesec) return false;
            else if(t1.mjesec < t2.mjesec) return true;
            else{
                if(t1.dan > t2.dan) return false;
                else if(t1.dan < t2.dan) return true;
                else{
                    if(t1.prosjecna > t2.prosjecna) return false;
                    else return true;
                }
            }
        }
    });
    
    std::ofstream izlazni("IZVJESTAJ.TXT");
    if(!izlazni) std::cout << "Kreiranje datoteke nije uspjelo!";
    for(auto x : t){
        izlazni << x.ime << std::endl;
        for(int i = 0; i < x.ime.length(); i++) izlazni << "-";
        izlazni << std::endl << "Datum mjerenja: " << x.dan << "/" << x.mjesec << "/" << x.godina;
        izlazni << std::endl << "Minimalna temperatura: " << *std::min_element(x.brojevi.begin(), x.brojevi.end());
        izlazni << std::endl << "Maksimalna temperatura: " << *std::max_element(x.brojevi.begin(), x.brojevi.end());
        izlazni << std::endl << "Prosjecna temperatura: " << std::fixed << std::setprecision(2) << x.prosjecna << std::endl << std::endl;
    }
	return 0;
}