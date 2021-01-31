//TP 2016/2017: Tutorijal 1, Zadatak 3
#include <iostream>
#include <cmath>
#include <iomanip>

int main ()
{
    int a, b;
    std::cout << "Unesite pocetnu i krajnju vrijednost: ";
    std::cin >> a >> b;
    
    if(a > 9999 || b > 9999 || a > b) return 0;
    
    std::cout << "\n";
    
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 45; j++){
            if((i == 0 ||  i== 2) && (j==0 || j==10 || j==20+1 || j==30+2 || j==44))
                std::cout << "+";
            else if((i == 0 ||  i== 2) && !(j==0 || j==10 || j==20+1 || j==30+2 || j==44))
                std::cout<< "-";
            else  if(i == 1){
                if(j==0 || j==10 || j==20+1 || j==30+2 || j==44)
                    std::cout << "|";
                else if (j == 3)
                    std::cout << " Brojevi ";
                else if(j == 12)
                    std::cout << " Kvadrati ";
                else if(j == 22)
                    std::cout << " Korijeni ";
                else if(j == 33)
                    std::cout << " Logaritmi ";
            }
        }
        std::cout << "\n";
    }
    
    for (int i = a; i <= b; i++){
        for (int j = 0; j < 45; j++){
            if(j==0 || j==10 || j==20+1 || j==30+2 || j==44)
                std::cout << "|";
            else if (j == 1 || j == 11 || j == 22 || j == 33 || j == 20 || j == 31 || j == 43)
                std::cout << " ";
            else if (j == 2)
                std::cout << std::left << std::setw(8) << i;
            else if (j == 12)
                std::cout << std::right << std::setw(8) << i*i;
            else if (j == 24)
                std::cout << std::setw(8) << std::fixed << std::setprecision(3) << sqrt(i);
            else if (j == 35)
                std::cout << std::setw(9) << std::fixed << std::setprecision(5) << log(i);
        }
        std::cout << "\n";
    }
    
    for(int j = 0; j < 45; j++){
        if (j==0 || j==10 || j==20+1 || j==30+2 || j==44)
            std::cout << "+";
        else std::cout<< "-";
    }

    return 0;
}