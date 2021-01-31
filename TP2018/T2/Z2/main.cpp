//TP 2017/2018: Tutorijal 2, Zadatak 2
#include <iostream>
#include <vector>

bool TestPerioda (std::vector<double> v, int p){
    if (p >= 1 && p < v.size()){
        for (int i = 0; i < v.size() - p; i++){
            if (v.at(i) != v.at(i + p)) return false;
    }
    }
    else return false;
    
   return true;
        
}


int OdrediOsnovniPeriod (std::vector<double> x){
    for(int i = 0; i < x.size(); i++){
        if(TestPerioda(x, i)) return i;
    }
    return 0;
}



int main ()
{
    double n;
    std::vector<double> v;
    std::cout << "Unesite slijed brojeva (0 za kraj): ";
    for(;;){
        std::cin >> n;
        if (n == 0.f) break;
        v.push_back(n);
    }
    int period = OdrediOsnovniPeriod(v);
    if(period == 0) std::cout << "Slijed nije periodican!";
    else std::cout << "Slijed je periodican sa osnovnim periodom " <<  period << ".";
    
	return 0;
}
