//TP 2018/2019: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <cmath>

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double,double>> v, int d)
{
    if(d < 0 || d >= v.size()) throw std::domain_error("Nedozvoljen red");
    for(int m = 0; m < v.size(); m++)
        for(int n = m+1; n < v.size(); n++)
            if(v.at(m).first == v.at(n).first) throw std::domain_error("Neispravni cvorovi");
    std::vector<double> tezinski_koeficijenti (v.size(), 0);
    for(int i = 1; i <= v.size(); i++) {
        double max = 1;
        if((i-d) > 1) max = i-d;
        double k = max;
        double min = i;
        if((v.size()-d) < i) min = v.size()-d;
        for(int j = k; j <= min; j++) {  //racunanje tezinskog_koeficijenta
            double proizvod = 1;
            for(int l = j; l <= j+d; l++) {
                if(l == i) continue;
                proizvod *= 1/(v.at(i-1).first - v.at(l-1).first);
            }
            tezinski_koeficijenti[i-1] += pow((-1), j-1) * proizvod;
        }
    }
    
    return [=](double x) {
        for(int i = 0; i < v.size(); i++)
            if(v.at(i).first == x) return v.at(i).second;

        double suma1 = 0;
        double suma2 = 0;
        for(int i = 1; i <= v.size(); i++) {
            suma1 += tezinski_koeficijenti[i-1]/(x - v.at(i-1).first) * v.at(i-1).second;   //racunanje sume iz brojnika
            suma2 += tezinski_koeficijenti[i-1]/(x - v.at(i-1).first);  //racunanje sume iz nazivnika
        }
        return suma1 / suma2;
    };
}

double f (double x)
{
    return x*x + sin(x);
}

std::function<double(double)> BaricentricnaInterpolacija (double f(double), double min, double max, double korak, int d)
{
    if(min > max || korak <= 0) throw std::domain_error("Nekorektni parametri");

    std::vector<std::pair<double,double>> v;
    for(double i = min; i <= max; i+=korak)
        v.push_back({i, f(i)});

    return BaricentricnaInterpolacija(v, d);
}

int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin >> opcija;
    if(opcija == 1) {
        std::cout << "Unesite broj cvorova: ";
        int broj_cvorova;
        std::cin >> broj_cvorova;
        std::vector<std::pair<double,double>> v(broj_cvorova);
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i = 0; i < v.size(); i++) {
            std::cin >> v.at(i).first;
            std::cin >> v.at(i).second;
        }
        std::cout << "Unesite red interpolacije: ";
        int red;
        std::cin >> red;
        try {
            auto f1 = BaricentricnaInterpolacija(v, red);
            do {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                std::cin >> argument;
                if(std::cin)
                    std::cout << "f(" << argument << ") = " << f1(argument) << std::endl;
            } while(std::cin);
        } catch(std::domain_error e) {
            std::cout << e.what();
        }
    } else {
        std::cout << "Unesite krajeve intervala i korak: ";
        double min, max, korak;
        std::cin >> min >> max >> korak;
        std::cout << "Unesite red interpolacije: ";
        int red;
        std::cin >> red;
        try {
            auto fapprox = BaricentricnaInterpolacija(f, min, max, korak, red);
            do {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                std::cin >> argument;
                if(std::cin)
                    std::cout << "f(" << argument << ") = " << f(argument) << " fapprox(" << argument << ") = " << fapprox(argument) << std::endl;
            } while(std::cin);
        } catch(std::domain_error e) {
            std::cout << e.what();
        }
    }
    return 0;
}
