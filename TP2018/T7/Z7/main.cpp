/* 
    TP 16/17 (Tutorijal 7, Zadatak 7)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <set>

template <typename NekiTip>
std::set<NekiTip> Unija (std::set<NekiTip> s1, std::set<NekiTip> s2){
	std::set<NekiTip> unija;
	for(NekiTip x : s1) unija.insert(x);
	
	bool nadjen = false;
	for(NekiTip y : s2){
		for(NekiTip z : s1){
			if(y == z) nadjen = true;
		}
		if(!nadjen) unija.insert(y);
		nadjen = false;
	}
	return unija;
}

template <typename NekiTip>
std::set<NekiTip> Presjek (std::set<NekiTip> s1, std::set<NekiTip> s2){
	std::set<NekiTip> presjek;
	bool isti = false;
	for(NekiTip x : s1){
		for(NekiTip y : s2){
			if(x == y) isti = true;
		}
		if(isti) presjek.insert(x);
		isti = false;
	}
	return presjek;
}

int main ()
{
	return 0;
}