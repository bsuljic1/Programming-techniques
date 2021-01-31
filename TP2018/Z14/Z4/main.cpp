//TP 2018/2019: Tutorijal 14, Zadatak 4
#include <iostream>
#include <fstream>
#include <string>

void IzvrniDatoteku(std::string ime_dat){
    std::fstream ulazni(ime_dat, std::ios::binary | std::ios::in | std::ios::out);
    if(!ulazni) throw std::logic_error("Datotetka ne postoji");
    ulazni.seekg(0, std::ios::end);
    long int duzina = ulazni.tellg() / sizeof(double);
    for(int i = 0; i < duzina/2; i++){
        double x, y;
        ulazni.seekg(i*sizeof(double), std::ios::beg);
        ulazni.read(reinterpret_cast<char*>(&x), sizeof x);
        ulazni.seekg((duzina-i-1)*sizeof(double), std::ios::beg);
        ulazni.read(reinterpret_cast<char*>(&y), sizeof y);
        ulazni.seekg(i*sizeof(double), std::ios::beg);
        ulazni.write(reinterpret_cast<char*>(&y), sizeof y);
        ulazni.seekg((duzina-i-1)*sizeof(double), std::ios::beg);
        ulazni.write(reinterpret_cast<char*>(&x), sizeof x);
    }
    
}

int main ()
{
    double niz[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::ofstream izlazni("BIN.DAT", std::ios::binary);
    izlazni.write(reinterpret_cast<char*>(niz), sizeof niz);
    izlazni.close();
    IzvrniDatoteku("BIN.DAT");
	return 0;
}