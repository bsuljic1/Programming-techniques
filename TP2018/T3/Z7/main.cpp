//TP 2017/2018: Tutorijal 3, Zadatak 7
#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<int>> Matrica;


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



Matrica PascalovTrougao (int n){
    if(n<0) throw std::domain_error("Broj redova ne smije biti negativan");
    
    Matrica m(n, std::vector<int>(n, 0));
    for(int i = 0; i < m.size(); i++){
        m.at(i).resize(i+1);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || i == j) m.at(i).at(j) = 1;
            else m.at(i).at(j) = m.at(i-1).at(j) + m.at(i-1).at(j-1);
        }
    }
    return m;
}

int main ()
{
    int n;
    std::cout << "Unesite broj redova: ";
    std::cin >> n;
    Matrica paskalov(PascalovTrougao(n));
    std::cout << std::endl;
    int najveca = NajvecaSirina(paskalov) + 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            std::cout << std::right << std::setw(najveca)<< paskalov.at(i).at(j);
        }
        std::cout << std::endl;
    }
    
    
    
    
	return 0;
}
