//TP 2017/2018: Tutorijal 3, Zadatak 8
#include <iostream>
#include <string>

std::string IzdvojiRijec (std::string s, int n){
    int broj_rijeci = 0;
    std::string rijec;
    for(int i = 0; i < s.length(); i++){
        while(i < s.length() && s[i] == ' ') i++;
        if(i == s.length()) break;
        broj_rijeci++;
        if(broj_rijeci == n){ 
            while(s[i] != ' ' && i != s.length()){
                rijec.push_back(s[i]);
                i++;
            }
            return rijec;
        }
        while(i < s.length() && s[i] != ' ') i++;
    }
    throw std::range_error("Pogresan redni broj rijeci!");
}

int main ()
{ 
    int redni;
    std::string recenica;
    std::cout << "Unesite redni broj rijeci: ";
    std::cin >> redni;
    std::cout << "Unesite recenicu: ";
    std::cin.ignore(100, '\n');
    std::getline(std::cin, recenica);
    
    try{
        std::string rijec(IzdvojiRijec(recenica, redni));
        std::cout << "Rijec na poziciji " << redni << " je " << rijec << std::endl;
    }
    catch(std::range_error greska){
        std::cout << "IZUZETAK: " << greska.what() << std::endl;
    }

    
	return 0;
}
