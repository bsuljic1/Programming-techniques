/* 
    TP 16/17 (Tutorijal 7, Zadatak 10)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <functional>

std::function<int(int)> IteriranaFunkcija (int f(int), int n){
	return [f, n](int x){
	for(int i = n; i > 0; i--){
		x = f(x);
	}
	return x;
	};
}

int main ()
{
	return 0;
}