/*
    TP 16/17 (Tutorijal 12, Zadatak 2)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <set>

template <typename TipEl>
std::set<TipEl> operator +(const std::set<TipEl> &s1, const std::set<TipEl> &s2)
{
	std::set<TipEl> unija;
	for(auto x : s1) unija.insert(x);

	bool nadjen = false;
	for(auto y : s2) {
		for(auto z : s1) {
			if(y == z) nadjen = true;
		}
		if(!nadjen) unija.insert(y);
		nadjen = false;
	}
	return unija;
}

template <typename TipEl>
std::set<TipEl> operator *(const std::set<TipEl> &s1, const std::set<TipEl> &s2)
{
	std::set<TipEl> presjek;
	bool isti = false;
	for(auto x : s1) {
		for(auto y : s2) {
			if(x == y) isti = true;
		}
		if(isti) presjek.insert(x);
		isti = false;
	}
	return presjek;
}

template <typename TipEl>
std::set<TipEl> &operator +=(std::set<TipEl> &s1, const std::set<TipEl> &s2)
{
	bool nadjen = false;
	for(auto y : s2) {
		for(auto z : s1) {
			if(y == z) nadjen = true;
		}
		if(!nadjen) s1.insert(y);
		nadjen = false;
	}
	return s1;
}

template <typename TipEl>
std::set<TipEl> &operator *=(std::set<TipEl> &s1, const std::set<TipEl> &s2)
{
	std::set<TipEl> presjek;
	bool isti = false;
	for(auto x : s1) {
		for(auto y : s2) {
			if(x == y) isti = true;
		}
		if(isti) presjek.insert(x);
		isti = false;
	}
	s1 = presjek;
	return s1;
}

template <typename TipEl>
std::ostream &operator <<(std::ostream &tok, const std::set<TipEl> s)
{
	tok << "{";
	for(auto it = s.begin(); it != s.end(); it++) {
		if(it != --(s.end())) tok << *it << ",";
		else tok << *it;
	}
	tok << "}";
	return tok;
}

template <typename Tip1, typename Tip2>
std::set<std::pair<Tip1, Tip2>> operator %(const std::set<Tip1> &s1, const std::set<Tip2> &s2)
{
	std::set<std::pair<Tip1, Tip2>> dekart;
	for(auto x : s1) {
		for(auto y : s2) {
			dekart.insert(std::make_pair(x,y));
		}
	}
	return dekart;
}

template <typename Tip1, typename Tip2>
std::ostream &operator <<(std::ostream &tok, std::set<std::pair<Tip1, Tip2>> dekart)
{
	tok << "{";
	for(auto it = dekart.begin(); it != dekart.end(); it++) {
		if(it != --(dekart.end())) tok << "(" << it->first << "," << it->second << "),";
		else tok << "(" << it->first << "," << it->second << ")";
	}
	tok << "}";
	return tok;
}
int main ()
{
	std::set<double> s1{3.6, 5.1, 1, 2, 8};
	s1 *= std::set<double> {3.6,10,3, 2., 9};
	std::cout << s1 << std::endl;
	s1 += std::set<double> {3.6,10,3, 2., 9};
	std::cout << s1 << std::endl;
	std::set<std::string> s3{"dajte", "mi", "presjek", "molim", "vas"};
	s3 *= std::set<std::string> {"izvolite", "vaš", "presjek"};
	std::cout << s3 << std::endl;

	return 0;
}
