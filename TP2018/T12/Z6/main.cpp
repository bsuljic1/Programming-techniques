/*
    TP 16/17 (Tutorijal 12, Zadatak 6)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
template <typename TipEl>
class Matrica
{
	int br_redova, br_kolona;
	TipEl **elementi;
	char ime_matrice;
	static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
	static void DealocirajMemoriju(TipEl **elementi, int br_redova);
	void KopirajElemente(TipEl **elementi);
public:
	Matrica(int br_redova, int br_kolona, char ime = 0);
	Matrica(const Matrica &m);
	Matrica(Matrica &&m);
	~Matrica()
	{
		DealocirajMemoriju(elementi, br_redova);
	}
	Matrica &operator =(const Matrica &m);
	Matrica &operator =(Matrica &&m);
	Matrica operator *(const Matrica &m2);
	Matrica operator *(int broj);
	Matrica operator - (const Matrica &m2);
	Matrica operator + (const Matrica &m2);
	Matrica &operator +=(const Matrica &m2);
	Matrica &operator -=(const Matrica &m2);
	Matrica &operator *=(const Matrica &m2);
	template <typename Tip1>
	friend std::ostream &operator << (std::ostream &tok, const Matrica<Tip1> &m);
	template <typename Tip1>
	friend std::istream &operator >> (std::istream &tok, Matrica<Tip1> &m);
	Matrica &operator *=(int broj);
	template <typename Tip1>
	friend Matrica<Tip1> &operator *=(Matrica<Tip1> &m, int broj);
	template <typename Tip1>
	friend Matrica<Tip1> operator *(int broj, Matrica<Tip1> &m);
	TipEl *&operator [](int i)
	{
		return elementi[i];
	}
	TipEl *operator [](int i) const
	{
		return elementi[i];
	}
	TipEl &operator ()(int i, int j)
	{
		if(i < 1 || i > br_redova || j < 1  || j > br_kolona) throw std::range_error("Neispravan indeks");
		return elementi[i-1][j-1];
	}
	TipEl operator ()(int i, int j) const
	{
		if(i < 1 || i > br_redova || j < 1  || j > br_kolona) throw std::range_error("Neispravan indeks");
		return elementi[i-1][j-1];
	}

};
template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
	TipEl **elementi = new TipEl*[br_redova] {};
	try {
		for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
	} catch(...) {
		DealocirajMemoriju(elementi, br_redova);
		throw;
	}
	return elementi;
}
template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova)
{
	for(int i = 0; i < br_redova; i++) delete[] elementi[i];
	delete[] elementi;
}
template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :
	br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
	elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			Matrica::elementi[i][j] = elementi[i][j];
}
template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
	elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
	KopirajElemente(m.elementi);
}
template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice)
{
	m.br_redova = 0;
	m.elementi = nullptr;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m)
{
	if(br_redova < m.br_redova || br_kolona < m.br_kolona) {
		TipEl **novi_prostor = AlocirajMemoriju(m.br_redova, m.br_kolona);
		DealocirajMemoriju(elementi, br_redova);
		elementi = novi_prostor;
	} else if(br_redova > m.br_redova)
		for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
	br_redova = m.br_redova;
	br_kolona = m.br_kolona;
	ime_matrice = m.ime_matrice;
	KopirajElemente(m.elementi);
	return *this;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m)
{
	std::swap(br_redova, m.br_redova);
	std::swap(br_kolona, m.br_kolona);
	std::swap(ime_matrice, m.ime_matrice);
	std::swap(elementi, m.elementi);
	return *this;
}

template <typename TipEl>
Matrica<TipEl> Matrica<TipEl>::operator + (const Matrica<TipEl> &m2)
{
	if(br_redova != m2.br_redova || br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(br_redova, br_kolona);
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			m3.elementi[i][j] = elementi[i][j] + m2.elementi[i][j];
	return m3;
}
template <typename TipEl>
std::ostream &operator << (std::ostream &tok, const Matrica<TipEl> &m)
{
	int duzina = tok.width();
	for(int i = 0; i < m.br_redova; i++) {
		for(int j = 0; j < m.br_kolona; j++)
			tok << std::setw(duzina) << m.elementi[i][j];

		tok << std::endl;
	}
	return tok;
}
template <typename TipEl>
std::istream &operator >> (std::istream &tok, Matrica<TipEl> &m)
{
	for(int i = 0; i < m.br_redova; i++)
		for(int j = 0; j < m.br_kolona; j++) {
			std::cout << m.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
			tok >> m.elementi[i][j];
		}
	return tok;
}
template <typename TipEl>
Matrica<TipEl> Matrica<TipEl>::operator *(int broj)
{
	auto m3 = *this;
	for(int i = 0; i < br_redova; i++) {
		for(int j = 0; j < br_kolona; j++) {
			m3.elementi[i][j]*=broj;
		}
	}
	return m3;
}
template <typename TipEl>
Matrica<TipEl> Matrica<TipEl>::operator *(const Matrica<TipEl> &m2)
{
	if(br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
	Matrica<TipEl> nova(br_redova, m2.br_kolona);
	for(int i = 0; i < br_redova; i++) {
		for(int j = 0; j < m2.br_kolona; j++) {
			for(int k = 0; k < br_kolona; k++) {
				nova.elementi[i][j] += elementi[i][k]*m2.elementi[k][j];
			}
		}
	}
	return nova;
}
template <typename TipEl>
Matrica<TipEl> Matrica<TipEl>::operator - (const Matrica<TipEl> &m2)
{
	if(br_redova != m2.br_redova || br_kolona != m2.br_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(br_redova, br_kolona);
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			m3.elementi[i][j] = elementi[i][j] - m2.elementi[i][j];
	return m3;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator +=(const Matrica<TipEl> &m2)
{
	if(br_redova != m2.br_redova || br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			elementi[i][j] = elementi[i][j] + m2.elementi[i][j];
	return *this;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator -=(const Matrica<TipEl> &m2)
{
	if(br_redova != m2.br_redova || br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			elementi[i][j] = elementi[i][j] - m2.elementi[i][j];
	return *this;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator *=(const Matrica<TipEl> &m2)
{
	if(br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
	*this = *this * m2;
	return *this;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator *=(int broj)
{
	*this = *this * broj;
	return *this;
}
template <typename Tip1>
Matrica<Tip1> operator *(int broj, Matrica<Tip1> &m){
	auto m3 = m;
	for(int i = 0; i < m.br_redova; i++) {
		for(int j = 0; j < m.br_kolona; j++) {
			m3.elementi[i][j]*=broj;
		}
	}
	return m3;
}

int main()
{
	int m, n;
	std::cout << "Unesi broj redova i kolona za matrice:\n";
	std::cin >> m >> n;
	try {
		Matrica<double> a(m, n, 'A'), b(m, n, 'B');
		std::cout << "Unesi matricu A: \n";
		std::cin >> a;
		std::cout << "Unesi matricu B: \n";
		std::cin >> b;
		std::cout << "Zbir ove dvije matrice je: \n";
		std::cout << std::setw(7) << a + b;
	} catch(std::bad_alloc) {
		std::cout << "Nema dovoljno memorije! \n";
	}
	return 0;
}
