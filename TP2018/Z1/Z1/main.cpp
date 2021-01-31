/* TP, 2018/2019, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.
*/
#include <iostream>
#include <vector>

int ObrniRedoslijed (int x)
{
	int novi_broj = 0;
	while(x != 0) {
		novi_broj *= 10;
		novi_broj += x % 10;
		x /= 10;
	}
	return novi_broj;
}

std::vector<int> PalindromskaOtpornost (std::vector<int> v)
{
	std::vector <int> palindromske_otpornosti;
	for(int x : v) {
		int palindromska = 0;
		while (x != ObrniRedoslijed(x)) {
			x += ObrniRedoslijed(x);
			palindromska++;
		}
		palindromske_otpornosti.push_back(palindromska);
	}
	return palindromske_otpornosti;

}


int main ()
{
	int n;
	std::vector<int> v;
	std::vector<int> palindromske;

	std::cout << "Koliko zelite unijeti elemenata: ";
	std::cin >> n;

	std::cout << "Unesite elemente: ";
	for(int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		v.push_back(a);
	}

	palindromske = PalindromskaOtpornost(v);

	for(int i = 0; i < n; i++) {
		std::cout << "Palindromska otpornost broja " << v.at(i) << " iznosi " <<  palindromske.at(i) << std::endl;
	}

	return 0;
}
