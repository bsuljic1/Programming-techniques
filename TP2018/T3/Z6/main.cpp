//TP 2017/2018: Tutorijal 3, Zadatak 6
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

typedef std::vector<std::vector<int>> Matrica;

Matrica KroneckerovProizvod (std::vector<int> a, std::vector<int> b){
    Matrica c(a.size(), std::vector<int>(b.size()));
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            c[i][j] = a[i] * b[j];
        }
    }
    return c;
}

int BrojCifara (int x){
    int brojcifara = 0;
    if(x < 0) brojcifara++;
    while(x != 0){
        brojcifara++;
        x /= 10;
    }
    return brojcifara;
}

int NajvecaSirina (Matrica v){
    int max = 0;
  
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(BrojCifara(v.at(i).at(j)) > max) max = BrojCifara(v.at(i).at(j));
        }
        
    }
    return max;
}

int main ()
{
    int n1, n2;
    std::cout << "Unesite broj elemenata prvog vektora: ";
    std::cin >> n1;
    std::vector<int> v1;
    std::cout << "Unesite elemente prvog vektora: ";
    for(int i = 0; i < n1; i++){
        int y;
        std::cin >> y;
        v1.push_back(y);
    }
    std::cout << "Unesite broj elemenata drugog vektora: ";
    std::cin >> n2;
    std::vector<int> v2;
    std::cout << "Unesite elemente drugog vektora: ";
    for(int i = 0; i < n2; i++){
        int y;
        std::cin >> y;
        v2.push_back(y);
    }
    
    Matrica m(KroneckerovProizvod(v1,v2));
    
    std::cout << std::endl;
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            std::cout << std::right << std::setw(NajvecaSirina(m)+1) << m[i][j];
        }
        std::cout << std::endl;
    }
    
	return 0;
}
