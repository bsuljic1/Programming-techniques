/* 
    TP 16/17 (Tutorijal 7, Zadatak 8)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

std::string IzvrniBezRazmaka (std::string s){
	std::string izvrnut;
	std::remove_copy(s.rbegin(), s.rend(), std::inserter(izvrnut, izvrnut.begin()), ' ');
	return izvrnut;
}


int main ()
{
	return 0;
}