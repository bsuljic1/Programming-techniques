//TP 2018/2019: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>

template <typename TipElemenata>
struct Matrica {
    int br_redova, br_kolona;
    TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> &mat)
{
    if(!mat.elementi) return;
    for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona)
{
    Matrica<TipElemenata> mat;
    mat.br_redova = br_redova;
    mat.br_kolona = br_kolona;
    mat.elementi = new TipElemenata*[br_redova] {};
    try {
        for(int i = 0; i < br_redova; i++)
            mat.elementi[i] = new TipElemenata[br_kolona] {};
    } catch(...) {
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i = 0; i < mat.br_redova; i++)
        for(int j = 0; j < mat.br_kolona; j++) {
            std::cout << ime_matrice
                      << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
        }
}

template <typename TipElemenata>
void IspisiMatricu(Matrica<TipElemenata> &mat,
                   int sirina_ispisa, int preciznost = 6, bool treba_brisati = false)
{
    std::cout.precision(preciznost);
    for(int i = 0; i < mat.br_redova; i++) {
        for(int j = 0; j < mat.br_kolona; j++)
            std::cout << std::setw(sirina_ispisa) << mat.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
                                  const Matrica<TipElemenata> &m2)
{
    if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
        for(int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    auto produkt = StvoriMatricu<TipElemenata>(m1.br_redova, m2.br_kolona);

    for(int i = 0; i < m1.br_redova; i++) {
        for(int j = 0; j < m2.br_kolona; j++) {
            TipElemenata suma = 0;
            for(int k = 0; k < m2.br_redova; k++) suma += m1.elementi[i][k] * m2.elementi[k][j];
            produkt.elementi[i][j] = suma;
        }
    }
    return produkt;
}

template <typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom (Matrica<TipElemenata> a, std::vector<double> v)
{
    if(a.br_redova != a.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
    auto polinom = StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona);

    for(int i = 0; i < v.size(); i++) {
        auto matrica = StvoriMatricu<TipElemenata>(a.br_redova, a.br_kolona);
        for(int j = 0; j < polinom.br_redova; j++)
            matrica.elementi[j][j] = v.at(i);
        for(int j = 0; j < i; j++) {
            auto matrica2 = ProduktMatrica(matrica, a);
            for(int k = 0; k < matrica.br_redova; k++)
                for(int l = 0; l < matrica.br_kolona; l++)
                    matrica.elementi[k][l] = matrica2.elementi[k][l];
            UnistiMatricu(matrica2);
        }
        auto matrica3 = ZbirMatrica(polinom, matrica);
        for(int k = 0; k < matrica.br_redova ; k++)
            for(int l = 0; l < matrica.br_kolona; l++)
                polinom.elementi[k][l] = matrica3.elementi[k][l];
        UnistiMatricu(matrica);
        UnistiMatricu(matrica3);
    }
    return polinom;
}




int main()
{
    Matrica<double> a;
    int m;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> m;
    try {
        a = StvoriMatricu<double>(m, m);
        std::cout << "Unesite elemente matrice A: \n";
        UnesiMatricu('A', a);
        std::cout << "Unesite red polinoma: ";
        int red;
        std::cin >> red;
        std::cout << "Unesite koeficijente polinoma: ";
        std::vector<double> v(red+1);
        for(int i = 0; i < v.size(); i++)
            std::cin >> v.at(i);
        auto polinom = MatricniPolinom(a, v);
        IspisiMatricu(polinom, 10, 6, true);
    } catch(std::bad_alloc) {
        std::cout << "Nema dovoljno memorije!\n";
    }
    UnistiMatricu(a);
    return 0;
}
