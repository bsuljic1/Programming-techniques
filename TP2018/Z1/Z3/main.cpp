/* TP, 2018/2019, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.
*/
#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<int>> Matrica;

bool IspravnaForma (Matrica x)
{
	int vel = x.at(0).size();
	for(int i = 0; i < x.size(); i++)
		if(x.at(i).size() != vel) return false;
	return true;
}

Matrica KroneckerovProizvod (Matrica a, Matrica b)
{
	if(a.size() == 0 || b.size() == 0) return Matrica();

	if(IspravnaForma(a) == false && IspravnaForma(b) == true) throw std::domain_error("Prvi parametar nema formu matrice");
	else if(IspravnaForma(a) == true && IspravnaForma(b) == false) throw std::domain_error("Drugi parametar nema formu matrice");
	else if(IspravnaForma(a) == false && IspravnaForma(b) == false) throw std::domain_error("Parametri nemaju formu matrice");

	int m1 = a.size();          // broj redova matrice a
	int n1 = a.at(0).size();	// broj redova matrice b
	int m2 = b.size();			// broj elemenata u redovima matrice a
	int n2 = b.at(0).size();	// broj elemenata u redovima matrice b

	Matrica kroneckerov_proizvod(m1*m2, std::vector<int>(n1*n2, 0));

	for(int i = 0; i < m1; i++)
		for(int j = 0; j < m2; j++)
			for(int k = 0; k < n1; k++)
				for(int l = 0; l < n2; l++)
					kroneckerov_proizvod.at(i*m2 + j).at(k*n2 + l) = a.at(i).at(k) * b.at(j).at(l);

	return kroneckerov_proizvod;


}

int BrojCifara (int x)
{
	int brojcifara = 0;
	if(x < 0) brojcifara++;
	while(x != 0) {
		brojcifara++;
		x /= 10;
	}
	return brojcifara;
}

int NajvecaSirina (Matrica x)
{
	int max = 0;
	for(int i = 0; i < x.size(); i++)
		for(int j = 0; j < x.at(i).size(); j++)
			if(BrojCifara(x.at(i).at(j)) > max) max = BrojCifara(x.at(i).at(j));
	return max;
}


int main ()
{
	int m1, n1, m2, n2;

	std::cout << "Unesite dimenzije prve matrice: ";
	std::cin >> m1 >> n1;
	Matrica matrica_1(m1, std::vector<int> (n1, 0));
	std::cout << std::endl << "Unesite elemente prve matrice: ";
	for(int i = 0; i < m1; i++)
		for(int j = 0; j < n1; j++)
			std::cin >> matrica_1.at(i).at(j);

	std::cout << std::endl << "Unesite dimenzije druge matrice: ";
	std::cin >> m2 >> n2;
	Matrica matrica_2(m2, std::vector<int> (n2, 0));
	std::cout << std::endl << "Unesite elemente druge matrice: ";
	for(int i = 0; i < m2; i++)
		for(int j = 0; j < n2; j++)
			std::cin >> matrica_2.at(i).at(j);


	std::cout << std::endl << "Njihov Kroneckerov proizvod glasi: " << std::endl;

	Matrica kroneckerov_proizvod = KroneckerovProizvod(matrica_1, matrica_2);
	int najveca_sirina = NajvecaSirina(kroneckerov_proizvod);

	for(int i = 0; i < kroneckerov_proizvod.size(); i++) {
		for(int j = 0; j < kroneckerov_proizvod.at(0).size(); j++)
			std::cout << std::right << std::setw(najveca_sirina + 1) << kroneckerov_proizvod.at(i).at(j);
		std::cout << std::endl;
	}

	return 0;
}
