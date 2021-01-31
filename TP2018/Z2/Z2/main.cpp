/* TP, 2018/2019
*/
#include <iostream>
#include <vector>

void RastavaBroja (int n, int &p, int &q)
{
    if(n <= 0) throw std::domain_error("Broj koji se rastavlja mora biti prirodan");
    std::vector<int> temp;
    int tem = 2;
    while(n > 1) {
        if(n % tem == 0) {
            temp.push_back(tem);
            n /= tem;
        } else tem++;
    }

    std::vector<int> slobodni_od_kvadrata;
    std::vector<int> kvadrat;

    for(int i = 0; i < temp.size(); i++) {
        bool postoji = false;
        for(int m = 0; m < slobodni_od_kvadrata.size(); m++)     //provjera da li taj broj vec u vektoru slobodnih kvadrata
            if(temp.at(i) == slobodni_od_kvadrata.at(m)) postoji = true;

        for(int l = 0; l < kvadrat.size(); l++)     //provjera da li je taj broj vec u vektoru kvadrata
            if(temp.at(i) == kvadrat.at(l)) postoji = true;

        if(postoji) continue;

        int broj_ponavljanja = 1;
        for(int j = i + 1; j < temp.size(); j++) {
            if(temp.at(j) == temp.at(i)) broj_ponavljanja++;
        }

        if(broj_ponavljanja % 2 == 0) {
            while(broj_ponavljanja != 0) {
                kvadrat.push_back(temp.at(i));
                broj_ponavljanja -= 2;
            }
        } else {
            while(broj_ponavljanja != 1) {
                kvadrat.push_back(temp.at(i));
                broj_ponavljanja -= 2;
            }
            if(broj_ponavljanja == 1) slobodni_od_kvadrata.push_back(temp.at(i));
        }
    }

    p = 1;

    for(int i = 0; i < slobodni_od_kvadrata.size(); i++)
        p *= slobodni_od_kvadrata.at(i);

    q = 1;
    for(int i = 0; i < kvadrat.size(); i++)
        q *= kvadrat.at(i);

}

int main ()
{
    std::cout << "Unesite prirodan broj";
    int n;
    std::cin >> n;

    int p, q;

    try {
        RastavaBroja(n, p, q);
        std::cout << std::endl << p << " " << q << std::endl;
    } catch(std::domain_error e) {
        std::cout << std::endl << "Izuzetak: " << e.what() << "!" << std::endl;
    }

    return 0;
}
