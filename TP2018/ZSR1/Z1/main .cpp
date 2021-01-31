/*  *** Zadaci za samostalan rad (ZSR 1, Zadatak 1) *** */
#include <iostream>

int main ()
{
    int sati1, minute1, sekunde1, sati2, minute2, sekunde2;
    std::cout << "Unesi prvo vrijeme (h min s): ";
    std::cin >> sati1 >> minute1 >> sekunde1;
    std::cout << "Unesi drugo vrijeme (h min s): ";
    std::cin >> sati2 >> minute2 >> sekunde2;
    int ukupno1 = sati1 * 60 * 60 + minute1 * 60 + sekunde1; 
    int ukupno2 = sati2 * 60 * 60 + minute2 * 60 + sekunde2;
    double razlika = ukupno2 - ukupno1;
    razlika /= double(3600);
    int sati = int(razlika);
    razlika -= sati;
    int minute = razlika * 60;
    razlika *= 60;
    razlika -= minute;
    int sekunde = razlika * 60;
    
    std::cout << "Između ova dva trenutka proteklo je " << sati << "h " << minute << "min " << sekunde << "s.";
    
	return 0;
}