/*
    TP 2018/2019: Tutorijal 6, Zadatak 1

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <cmath>
#include <limits>

template <typename NekiTip>
NekiTip *GenerirajStepeneDvojke (int n) 
{
	try{
		NekiTip *pok{};
		if(n <= 0) throw std::domain_error("Broj elemenata mora biti pozitivan");
		pok = new NekiTip[n];
		for(int i = 0; i < n; i++) {
			if(powl(2, i) > (std::numeric_limits<NekiTip>::max())){
				delete[] pok;
				throw std::overflow_error("Prekoracen dozvoljeni opseg");
			}
			pok[i] = powl(2, i);
			
		
		}
		return pok;
	}
	catch(std::bad_alloc){
		std::runtime_error("Alokacija nije uspjela");
	}
	catch(std::domain_error){
		throw;
	}
	catch(std::overflow_error){
		throw;
	}
}

int main ()
{
	int n;
	std::cout << "Koliko zelite elemenata: ";
	std::cin >> n;

	try {
		auto niz = GenerirajStepeneDvojke<unsigned long int>(n);
		for(int i = 0; i < n; i++) std::cout << niz[i] << " ";
		delete[] niz;
	} catch(std::domain_error greska) {
		std::cout << "Izuzetak: " << greska.what() << std::endl;
	} catch(std::overflow_error greska) {
		std::cout << "Izuzetak: " << greska.what() << std::endl;
	} catch(std::runtime_error greska) {
		std::cout <<"Izuzetak: " << greska.what() << std::endl;
	}
	
	return 0;
}
