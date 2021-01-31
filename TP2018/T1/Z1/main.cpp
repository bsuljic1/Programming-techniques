//TP 2016/2017: Tutorijal 1, Zadatak 1
#include <iostream>
#include <cmath>
int main ()
{
    int a, b, c, d;
    int omjer_a, omjer_b, omjer_c;
    double d_u_metrima;
    int plocice;
    
    std::cout<< "Unesite duzinu, sirinu i dubinu bazena u metrima: ";
    std::cin>> a >> b >> c;
    std::cout<< "Unesite sirinu plocice u centimetrima: ";
    std::cin>> d;
    
    d_u_metrima = d * 0.01;
    
    omjer_a = a/d_u_metrima;
    omjer_b = b/d_u_metrima;
    omjer_c = c/d_u_metrima;
    
    plocice = omjer_a*omjer_b + 2*omjer_a*omjer_c + 2*omjer_b*omjer_c;
    
    if( (a==omjer_a*d_u_metrima) && (b==omjer_b*d_u_metrima) && (c==omjer_c*d_u_metrima) ){
        std::cout<< "\nZa poplocavanje bazena dimenzija " << a << "x" << b << "x" << c << "m sa plocicama dimenzija " << d << "x" 
        << d << "cm" << "\npotrebno je " << plocice << " plocica.";
    }
    else{
        std::cout<< "\nPoplocavanje bazena dimenzija " << a << "x" << b << "x" << c << "m sa plocicama dimenzija " << d << "x" << d 
        << "cm" << "\nnije izvodljivo bez lomljenja plocica!";
    }
    
	return 0;
}