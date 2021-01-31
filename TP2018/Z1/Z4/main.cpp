/* TP, 2018/2019, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.
*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

std::string ObrniRijec (std::string rijec)
{
	std::string obrnuta_rijec;
	for(int i = rijec.length()-1; i >= 0; i--)
		obrnuta_rijec.push_back(rijec.at(i));
	return obrnuta_rijec;
}

bool simetricna (std::string rijec)
{
	std::string obrnuta = ObrniRijec(rijec);
	for(int i = 0; i < rijec.length(); i++)
		if(char(std::toupper(rijec.at(i))) != char(std::toupper(obrnuta.at(i)))) return false;
	return true;;
}

std::vector<std::string> NadjiSimetricneRijeci (std::string s)
{
	std::vector<std::string> simetricne;
	std::string rijec;
	for(int i = 0; i < s.length(); i++) {
		while(i < s.length() && !((s.at(i) >= 'A' && s.at(i) <= 'z') || (s.at(i) >= '0' && s.at(i) <= '9'))) i++;
		if(i == s.length()) break;
		if(i < s.length() && ((s.at(i) >= 'A' && s.at(i) <= 'z') || (s.at(i) >= '0' && s.at(i) <= '9'))) {
			while(i < s.length() && ((s.at(i) >= 'A' && s.at(i) <= 'z') || (s.at(i) >= '0' && s.at(i) <= '9'))) {
				rijec.push_back(s.at(i));
				i++;
			}
			if(rijec.size() >= 2)
				if(simetricna(rijec) == true) simetricne.push_back(rijec);
			rijec = "";
		}
	}
	return simetricne;
}

int main ()
{
	std::string recenica;
	std::cout << "Unesite recenicu: " << std::endl;
	std::getline(std::cin, recenica);

	std::vector<std::string> rijeci = NadjiSimetricneRijeci(recenica);

	if(rijeci.size() == 0) std::cout << "Recenica ne sadrzi simetricne rijeci!" << std::endl;
	else {
		std::cout << "Simetricne rijeci unutar recenice su: " << std::endl;
		for(std::string x : rijeci) std::cout << x << std::endl;
	}

	return 0;
}
