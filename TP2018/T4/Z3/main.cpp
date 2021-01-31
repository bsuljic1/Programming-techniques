//TP 2018/2019: Tutorijal 4, Zadatak 3
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

void IzdvojiKrajnjeRijeci (std::vector<std::string> v, std::string &first, std::string &last){
    if(v.size() == 0)
        return;
    
    first = v.at(0);
    last = v.at(0);
    for(std::string x : v){
        bool nadjena = false;
        for(int i = 0; i < x.length() && i < first.length(); i++){
            if(tolower(x[i]) < tolower(first[i])){
                first = x;
                nadjena = true;
                break;
            }
            else if(tolower(x[i]) > tolower(first[i])){
                nadjena = true;
                break;
            }
        }
        if(nadjena == false && x.length() < first.length()) first = x;
        
        nadjena = false;
        for(int i = 0; i < x.length() && i < last.length(); i++){
            if(tolower(x[i]) > tolower(last[i])){
                last = x;
                nadjena = true;
                break;
            }
            else if(tolower(x[i]) < tolower(last[i])){
                nadjena = true;
                break;
            }
        }
        if(nadjena == false && x.length() > last.length()) last = x;
    }
}

void ZadrziDuplikate (std::vector<std::string> &v){
    std::vector<std::string> dupli;
    std::vector<int> br(v.size(), 0);
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v.size(); j++){
            if(v.at(i) == v.at(j)) br.at(j)++;
        }
    }
    for(int i = 0; i < br.size(); i++){
        if(br.at(i) >= 2){
            bool nadjena = false;
            for(std::string x : dupli)
                if(x == v.at(i)) nadjena = true;
            if(nadjena == false) 
                dupli.push_back(v.at(i));
        }
    }
    v = dupli;
}


int main ()
{
    int broj_rijeci;
    std::cout << "Koliko zelite unijeti rijeci: ";
    std::cin >> broj_rijeci;
    std::cin.ignore(1000, '\n');
    std::cout << "Unesite rijeci: ";
    std::vector<std::string> spisak_rijeci(broj_rijeci, "");
    for(int i = 0; i < spisak_rijeci.size(); i++){
        std::getline(std::cin, spisak_rijeci.at(i), ' ');
    }
    
    std::string prva;
    std::string posljednja;
    IzdvojiKrajnjeRijeci(spisak_rijeci, prva, posljednja);
    std::cout << std::endl << "Prva rijec po abecednom poretku je: " << prva << std::endl;
    std::cout << "Posljednja rijec po abecednom poretku je: " << posljednja << std::endl;
    ZadrziDuplikate(spisak_rijeci);
    std::cout << "Rijeci koje se ponavljaju su: ";
    for(std::string x : spisak_rijeci) std::cout << x << " ";
    
	return 0;
}