/* TP, 2018/2019, Zadaća 1, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.
*/
#include <iostream>
#include <vector>
#include <complex>

typedef std::vector<std::vector<int>> Matrica;

bool IspravnaForma (Matrica a)
{
	if(a.size() == 0 || a.at(0).size() == 0) return false;
	for(int i = 0; i < a.size(); i++)
		if(a.at(i).size() != a.at(0).size()) return false;
	return true;
}

std::complex<double> VrhMatrice (Matrica a, int p, int q)
{
	if(IspravnaForma(a) == false) throw std::domain_error("Nekorektna matrica");
	if(p > a.size() - 1 || q > a.at(0).size() - 1) throw std::range_error("Nekorektna pocetna pozicija");

	std::complex<double> vrh(p, q);
	int i = p, j = q;

	if(a.size() == 1) {
		if(a.at(0).size() == 1) {
			vrh.real(p);
			vrh.imag(q);
			return vrh;
		}

		if(q == 0) {
			if(a.at(i).at(j+1) > a.at(p).at(q)) {
				q = j + 1;
				return VrhMatrice(a, p, q);
			} else {
				vrh.real(p);
				vrh.imag(q);
				return vrh;
			}
		}

		else if(q != 0 && q != a.at(0).size() - 1) {
			if(a.at(i).at(j+1) > a.at(p).at(q)) {
				if(a.at(i).at(j+1) >= a.at(i).at(j-1)) {
					q = j + 1;
					return VrhMatrice(a, p, q);
				}
			}
			if(a.at(i).at(j-1) > a.at(p).at(q)) {
				q = j - 1;
				return VrhMatrice(a, p, q);
			} else {
				vrh.real(p);
				vrh.imag(q);
				return vrh;
			}
		}

		else {
			if(a.at(i).at(j-1) > a.at(p).at(q)) {
				q = j - 1;
				return VrhMatrice(a, p, q);
			} else {
				vrh.real(p);
				vrh.imag(q);
				return vrh;
			}
		}
	}

	else if(a.at(0).size() == 1) {
		if(p == 0) {
			if(a.at(i+1).at(j) > a.at(p).at(q)) {
				p = i + 1;
				return VrhMatrice(a, p, q);
			} else {
				vrh.real(p);
				vrh.imag(q);
				return vrh;
			}
		}

		else if(p != 0 && p != a.size() - 1) {
			if(a.at(i-1).at(j) > a.at(p).at(q)) {
				p = i - 1;
				return VrhMatrice(a, p, q);
			}
			if(a.at(i+1).at(j) > a.at(p).at(q)) {
				p = i + 1;
				return VrhMatrice(a, p, q);
			} else {
				vrh.real(p);
				vrh.imag(q);
				return vrh;
			}
		}

		else {
			if(a.at(i-1).at(j) > a.at(p).at(q)) {
				p = i - 1;
				return VrhMatrice(a, p, q);
			} else {
				vrh.real(p);
				vrh.imag(q);
				return vrh;
			}
		}
	}

	else if(p == 0 && q == 0) {
		if(a.at(i).at(j+1) > a.at(p).at(q)) {
			if(a.at(i).at(j+1) >= a.at(i+1).at(j+1) && a.at(i).at(j+1) >= a.at(i+1).at(j)) {
				q = j + 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i+1).at(j+1)  > a.at(p).at(q)) {
			if(a.at(i+1).at(j+1) >= a.at(i+1).at(j)) {
				p = i + 1;
				q = j + 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i+1).at(j) > a.at(p).at(q)) {
			p = i + 1;
			return VrhMatrice(a, p, q);
		} else {
			vrh.real(p);
			vrh.imag(q);
			return vrh;
		}
	}

	else if(p == 0 && q != 0 && q != a.at(0).size() - 1) {
		if(a.at(i).at(j+1) > a.at(p).at(q)) {
			if(a.at(i).at(j+1) >= a.at(i+1).at(j+1) && a.at(i).at(j+1) >= a.at(i+1).at(j) && a.at(i).at(j+1) >= a.at(i+1).at(j-1) && a.at(i).at(j+1) >= a.at(i).at(j-1)) {
				q = j + 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i+1).at(j+1)  > a.at(p).at(q)) {
			if(a.at(i+1).at(j+1) >= a.at(i+1).at(j) && a.at(i+1).at(j+1) >= a.at(i+1).at(j-1) && a.at(i+1).at(j+1) >= a.at(i).at(j-1)) {
				p = i + 1;
				q = j + 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i+1).at(j) > a.at(p).at(q)) {
			if(a.at(i+1).at(j) >= a.at(i+1).at(j-1) && a.at(i+1).at(j) >= a.at(i).at(j-1)) {
				p = i + 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i+1).at(j-1) > a.at(p).at(q)) {
			if(a.at(i+1).at(j-1) >= a.at(i).at(j-1)) {
				p = i + 1;
				q = j - 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i).at(j-1) > a.at(p).at(q)) {
			q = j - 1;
			return VrhMatrice(a, p, q);
		} else {
			vrh.real(p);
			vrh.imag(q);
			return vrh;
		}
	}

	else if(p == 0 && q == a.at(0).size() - 1) {

		if(a.at(i+1).at(j) > a.at(p).at(q)) {
			if(a.at(i+1).at(j) >= a.at(i+1).at(j-1) && a.at(i+1).at(j) >= a.at(i).at(j-1)) {
				p = i + 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i+1).at(j-1) > a.at(p).at(q)) {
			if(a.at(i+1).at(j-1) >= a.at(i).at(j-1)) {
				p = i + 1;
				q = j - 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i).at(j-1) > a.at(p).at(q)) {
			q = j - 1;
			return VrhMatrice(a, p, q);
		} else {
			vrh.real(p);
			vrh.imag(q);
			return vrh;
		}
	}

	else if(q == 0 && p != 0 && p != a.size() - 1) {
		if(a.at(i-1).at(j) > a.at(p).at(q)) {
			if(a.at(i-1).at(j) >= a.at(i-1).at(j+1) && a.at(i-1).at(j) >= a.at(i).at(j+1) && a.at(i-1).at(j) >= a.at(i+1).at(j+1) && a.at(i-1).at(j) >= a.at(i+1).at(j)) {
				p = i - 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i-1).at(j+1) > a.at(p).at(q)) {
			if(a.at(i-1).at(j+1) >= a.at(i).at(j+1) && a.at(i-1).at(j+1) >= a.at(i+1).at(j+1) && a.at(i-1).at(j+1) >= a.at(i+1).at(j)) {
				p = i - 1;
				q = j + 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i).at(j+1) > a.at(p).at(q)) {
			if(a.at(i).at(j+1) >= a.at(i+1).at(j+1) && a.at(i).at(j+1) >= a.at(i+1).at(j)) {
				q = j + 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i+1).at(j+1)  > a.at(p).at(q)) {
			if(a.at(i+1).at(j+1) >= a.at(i+1).at(j)) {
				p = i + 1;
				q = j + 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i+1).at(j) > a.at(p).at(q)) {
			p = i + 1;
			return VrhMatrice(a, p, q);
		} else {
			vrh.real(p);
			vrh.imag(q);
			return vrh;
		}
	}

	else if(q == 0 && p == a.size() - 1) {
		if(a.at(i-1).at(j) > a.at(p).at(q)) {
			if(a.at(i-1).at(j) >= a.at(i-1).at(j+1) && a.at(i-1).at(j) >= a.at(i).at(j+1)) {
				p = i - 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i-1).at(j+1) > a.at(p).at(q)) {
			if(a.at(i-1).at(j+1) >= a.at(i).at(j+1)) {
				p = i - 1;
				q = j + 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i).at(j+1) > a.at(p).at(q)) {
			q = j + 1;
			return VrhMatrice(a, p, q);
		} else {
			vrh.real(p);
			vrh.imag(q);
			return vrh;
		}
	}

	else if(p == a.size() -1 && q != a.at(0).size() - 1 && q != 0) {
		if(a.at(i-1).at(j-1) > a.at(p).at(q)) {
			if(a.at(i-1).at(j-1) >= a.at(i-1).at(j+1) && a.at(i-1).at(j-1) >= a.at(i).at(j+1) && a.at(i-1).at(j-1) >= a.at(i).at(j-1) && a.at(i-1).at(j-1) >= a.at(i-1).at(j)) {
				p = i - 1;
				q = j - 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i-1).at(j) > a.at(p).at(q)) {
			if(a.at(i-1).at(j) >= a.at(i-1).at(j+1) && a.at(i-1).at(j) >= a.at(i).at(j+1) && a.at(i-1).at(j) >= a.at(i).at(j-1) && a.at(i-1).at(j) >= a.at(i-1).at(j-1)) {
				p = i - 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i-1).at(j+1) > a.at(p).at(q)) {
			if(a.at(i-1).at(j+1) >= a.at(i).at(j+1) && a.at(i-1).at(j+1) >= a.at(i).at(j-1) && a.at(i-1).at(j+1) >= a.at(i-1).at(j-1)) {
				p = i - 1;
				q = j + 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i).at(j+1) > a.at(p).at(q)) {
			if(a.at(i).at(j+1) >= a.at(i).at(j-1) && a.at(i).at(j+1) >= a.at(i-1).at(j-1)) {
				q = j + 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i).at(j-1) > a.at(p).at(q)) {
			if(a.at(i).at(j-1) >= a.at(i-1).at(j-1)) {
				q = j - 1;
				return VrhMatrice(a, p, q);
			}
		} else {
			vrh.real(p);
			vrh.imag(q);
			return vrh;
		}
	}

	else if(p == a.size() - 1 && q == a.at(0).size() - 1) {
		if(a.at(i-1).at(j) > a.at(p).at(q)) {
			if(a.at(i-1).at(j) >= a.at(i).at(j-1) && a.at(i-1).at(j) >= a.at(i-1).at(j-1)) {
				p = i - 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i).at(j-1) > a.at(p).at(q)) {
			if(a.at(i).at(j-1) >= a.at(i-1).at(j-1)) {
				q = j - 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i-1).at(j-1) > a.at(p).at(q)) {
			p = i - 1;
			q = j - 1;
			return VrhMatrice(a, p, q);
		} else {
			vrh.real(p);
			vrh.imag(q);
			return vrh;
		}
	}


	else if(p != a.size() - 1 && q == a.at(0).size() - 1) {
		if(a.at(i-1).at(j) > a.at(p).at(q)) {
			if(a.at(i-1).at(j) >= a.at(i+1).at(j) && a.at(i-1).at(j) >= a.at(i+1).at(j-1) && a.at(i-1).at(j) >= a.at(i).at(j-1) && a.at(i-1).at(j) >= a.at(i-1).at(j-1)) {
				p = i - 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i+1).at(j) > a.at(p).at(q)) {
			if(a.at(i+1).at(j) >= a.at(i+1).at(j-1) && a.at(i+1).at(j) >= a.at(i).at(j-1) && a.at(i+1).at(j) >= a.at(i-1).at(j-1)) {
				p = i + 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i+1).at(j-1) > a.at(p).at(q)) {
			if(a.at(i+1).at(j-1) >= a.at(i).at(j-1) && a.at(i+1).at(j-1) >= a.at(i-1).at(j-1)) {
				p = i + 1;
				q = j - 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i).at(j-1) > a.at(p).at(q)) {
			if(a.at(i).at(j-1) >= a.at(i-1).at(j-1)) {
				q = j - 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i-1).at(j-1) > a.at(p).at(q)) {
			p = i - 1;
			q = j - 1;
			return VrhMatrice(a, p, q);
		} else {
			vrh.real(p);
			vrh.imag(q);
			return vrh;
		}
	}

	else {
		if(a.at(i-1).at(j-1) > a.at(p).at(q)) {
			if(a.at(i-1).at(j-1) >= a.at(i-1).at(j+1) && a.at(i-1).at(j-1) >= a.at(i).at(j+1) && a.at(i-1).at(j-1) >= a.at(i+1).at(j+1) && a.at(i-1).at(j-1) >= a.at(i+1).at(j) && a.at(i-1).at(j-1) >= a.at(i+1).at(j-1) && a.at(i-1).at(j-1) >= a.at(i).at(j-1) && a.at(i-1).at(j-1) >= a.at(i-1).at(j)) {
				p = i - 1;
				q = j - 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i-1).at(j) > a.at(p).at(q)) {
			if(a.at(i-1).at(j) >= a.at(i-1).at(j+1) && a.at(i-1).at(j) >= a.at(i).at(j+1) && a.at(i-1).at(j) >= a.at(i+1).at(j+1) && a.at(i-1).at(j) >= a.at(i+1).at(j) && a.at(i-1).at(j) >= a.at(i+1).at(j-1) && a.at(i-1).at(j) >= a.at(i).at(j-1) && a.at(i-1).at(j) >= a.at(i-1).at(j-1)) {
				p = i - 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i-1).at(j+1) > a.at(p).at(q)) {
			if( a.at(i-1).at(j+1) >= a.at(i).at(j+1) && a.at(i-1).at(j+1) >= a.at(i+1).at(j+1) && a.at(i-1).at(j+1) >= a.at(i+1).at(j) && a.at(i-1).at(j+1) >= a.at(i+1).at(j-1) && a.at(i-1).at(j+1) >= a.at(i).at(j-1) && a.at(i-1).at(j+1) >= a.at(i-1).at(j-1)) {
				p = i - 1;
				q = j + 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i).at(j+1) > a.at(p).at(q)) {
			if(a.at(i).at(j+1) >= a.at(i+1).at(j+1) && a.at(i).at(j+1) >= a.at(i+1).at(j) && a.at(i).at(j+1) >= a.at(i+1).at(j-1) && a.at(i).at(j+1) >= a.at(i).at(j-1) && a.at(i).at(j+1) >= a.at(i-1).at(j-1)) {
				q = j + 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i+1).at(j+1)  > a.at(p).at(q)) {
			if(a.at(i+1).at(j+1) >= a.at(i+1).at(j) && a.at(i+1).at(j+1) >= a.at(i+1).at(j-1) && a.at(i+1).at(j+1) >= a.at(i).at(j-1) && a.at(i+1).at(j+1) >= a.at(i-1).at(j-1)) {
				p = i + 1;
				q = j + 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i+1).at(j) > a.at(p).at(q)) {
			if(a.at(i+1).at(j) >= a.at(i+1).at(j-1) && a.at(i+1).at(j) >= a.at(i).at(j-1) && a.at(i+1).at(j) >= a.at(i-1).at(j-1)) {
				p = i + 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i+1).at(j-1) > a.at(p).at(q)) {
			if(a.at(i+1).at(j-1) >= a.at(i).at(j-1) && a.at(i+1).at(j-1) >= a.at(i-1).at(j-1)) {
				p = i + 1;
				q = j - 1;
				return VrhMatrice(a, p, q);
			}
		}
		if(a.at(i).at(j-1) > a.at(p).at(q)) {
			if(a.at(i).at(j-1) >= a.at(i-1).at(j-1)) {
				q = j - 1;
				return VrhMatrice(a, p, q);
			}
		} else {
			vrh.real(p);
			vrh.imag(q);
			return vrh;
		}
	}
	return vrh;
}

int main ()
{
	int m, n;
	std::cout << "Unesite broj redova i kolona matrice:" << std::endl;
	std::cin >> m >> n;

	std::cout << "Unesite elemente matrice:" << std::endl;
	Matrica mat(m, std::vector<int>(n));
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			std::cin >> mat.at(i).at(j);

	std::cout << "Unesite poziciju odakle zapocinje pretraga:" << std::endl;
	int p, q;
	std::cin >> p >> q;

	try {
		std::complex<double> vrh = VrhMatrice(mat, p, q);
		std::cout << "Nadjen je vrh matrice na poziciji " << real(vrh) << " " << imag(vrh) << std::endl;
		std::cout << "Njegova vrijednost je " << mat.at(real(vrh)).at(imag(vrh));
	} catch(std::domain_error greska) {
		std::cout << "Greska: " << greska.what() << std::endl;
	} catch(std::range_error greska) {
		std::cout << "Greska: " << greska.what() << std::endl;
	}

	return 0;
}
