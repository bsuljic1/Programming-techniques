//TP 2018/2019: Tutorijal 4, Zadatak 2
#include <iostream>
#include <string>

void IzvrniString (std::string &s){
    char temp;
    for(int i = 0; i < s.length()/2; i++){
        temp = s.at(i);
        s.at(i) = s.at(s.length() - i - 1);
        s.at(s.length() - i - 1) = temp;
    }
}

int main ()
{
    std::string recenica;
    std::cout << "Unesi string: ";
    std::getline(std::cin, recenica);
    IzvrniString(recenica);
    std::cout << "Izvrnuti string je: " << recenica;
	return 0;
}