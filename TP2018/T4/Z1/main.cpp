//TP 2018/2019: Tutorijal 4, Zadatak 1
#include <iostream>
#include <limits>

int NajvecaCifra (long long int n){
    int max = n % 10;
    while(n != 0){
        int cifra = n % 10;
        if(cifra > max) max = cifra;
        n /= 10;
    }
    return max;
}

int NajmanjaCifra (long long int n){
    int min = n % 10;
    while(n != 0){
        int cifra = n % 10;
        if (cifra < min) min = cifra;
        n /= 10;
    }
    return min;
}

int BrojCifara (long long int n){
    if(n == 0) return 1;
    int broj_cifara = 0;
    while( n!= 0){
        broj_cifara++;
        n /= 10;
    }
    return broj_cifara;
}

int Cifre (long long int n, int &c_min, int &c_max){
    if(n == std::numeric_limits<long long int>::min()) {
        c_min = 0;
        c_max = 9;
        return 19;
    }
    if(n < 0) n *= (-1);
    c_min = NajmanjaCifra(n);
    c_max = NajvecaCifra(n);
    return BrojCifara(n);
    
}


int main ()
{
    long long int n;
    int cmin, cmax;
    std::cout << "Unesite broj: ";
    std::cin >> n;
    int brojcif = Cifre(n, cmin, cmax);
    std::cout << "Broj " << n << " ima " << brojcif << " cifara, najveca je " << cmax << " a najmanja " << cmin << ".";
	return 0;
}