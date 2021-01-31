/*
    TP 16/17 (Tutorijal 7, Zadatak 6)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <list>
#include <iterator>

template <typename NekiTip>
auto SortirajListu (std::list<NekiTip> &lista) -> std::list<NekiTip>
{
	std::list<NekiTip> nova_lista;
	while(!lista.empty()){
		auto min = lista.begin();
		for(auto i = lista.begin(); i != lista.end(); i++) {
			if(*i < *min) min = i;
		}
		nova_lista.push_back(*min);
		lista.erase(min);
	}
	lista = nova_lista;
	return nova_lista;
}

int main ()
{
	std::cout << "Koliko ima elemenata: ";
	int n; 
	std::cin >> n;
	std::cout << "Unesite elemente: ";
	std::list<int> lista(n);
	for(int &x : lista) std::cin >> x;
	std::list<int> sortirana_lista = SortirajListu(lista);
	std::cout << "Sortirana lista: ";
	for(int &x : sortirana_lista) std::cout << x << " ";
	return 0;
}
