//TP 2016/2017: Tutorijal 1, Zadatak 2
#include <iostream>
#include <cmath>

int main ()
{
    double a, b, c;
    std::cout<< "Unesite tri broja: ";
    std::cin>> a >> b >> c;
    
    if(a>0 && b>0 && c>0 && (a+b)>c && (a+c)>b && (b+c)>a){
        double obim = a + b + c;
        double s = obim/2;
        double povrsina =  sqrt(s*(s-a)*(s-b)*(s-c));
        double ua = (b*b + c*c - a*a)/(2*b*c);
        double ub = (a*a + c*c - b*b)/(2*a*c);
        double uc = (a*a + b*b -c*c)/(2*a*b);
        double ugao_a = acos(ua);
        double ugao_b = acos(ub);
        double ugao_c = acos(uc);
        double najmanji_ugao;
        
        if(ugao_a <= ugao_b && ugao_a <= ugao_c) najmanji_ugao = ugao_a;
        else if(ugao_b <= ugao_a && ugao_b <= ugao_c) najmanji_ugao = ugao_b;
        else najmanji_ugao = ugao_c;
        
        double pi = 4 * atan(1);
        double najmanji = (180/pi) * najmanji_ugao;
        
        int stepeni = int(najmanji);
        double min = najmanji - stepeni;
        int minute = int(min*60);
        int sekunde = int(((najmanji-stepeni)*60-minute)*60);
        if(stepeni==najmanji){
            minute = 0;
            sekunde = 0;
        }
        
        std::cout<< "Obim trougla sa duzinama stranica " << a << ", " << b << " i " << c << " iznosi " << obim << ".";
        std::cout<< "\nNjegova povrsina iznosi " << povrsina << ".";
        std::cout<< "\nNjegov najmanji ugao ima "<< stepeni << " stepeni, " << minute << " minuta i " << sekunde << " sekundi.";
    }
    else{
        std::cout<< "Ne postoji trougao cije su duzine stranica "<< a << ", " << b << " i " << c << "!";
    }
	return 0;
}