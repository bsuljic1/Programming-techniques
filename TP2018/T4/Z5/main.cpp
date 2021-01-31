//TP 2018/2019: Tutorijal 4, Zadatak 5
#include <iostream>
#include <vector>
#include <string>

template <typename NekiTip>
    std::vector<NekiTip> Presjek (std::vector<NekiTip> v1, std::vector<NekiTip> v2){
        std::vector<NekiTip> novi;
        for(int i = 0; i < v1.size(); i++){
            bool duplikat = false;
            for(int j = 0; j < v2.size(); j++){
                if(v1.at(i) == v2.at(j)){
                     duplikat = true;
                     break;
                }
            }
            if(duplikat){
                bool postoji = false;
                for(int k = 0; k < novi.size(); k++){
                    if(v1.at(i) == novi.at(k)){
                        postoji = true;
                        break;
                    }
                }
                if(!postoji) novi.push_back(v1.at(i));
            }
        }
        return novi;
}

int main ()
{
    for(int i = 0; i < 1; i++){
        std::cout << "Test za realne brojeve..." << std::endl;
        int n, m;
        std::cout << "Unesite broj elemenata prvog vektora: ";
        std::cin >> n;
        std::vector <float> v1(n);
        std::cout << "Unesite elemente prvog vektora: ";
        for(int i = 0; i < n; i++){
            int m;
            std::cin >> m;
            v1[i] = m;
        }
        int l;
        std::cout << "Unesite broj elemenata drugog vektora: ";
        std::cin >> l;
        std::vector <float> v2(l);
        std::cout << "Unesite elemente drugog vektora: ";
        for(int i = 0; i < l; i++){
            int m;
            std::cin >> m;
            v2[i] = m;
        }
        std::vector <float> v3;
        v3 = Presjek(v1, v2);
        std::cout << "Zajednicki elementi su: ";
        for(int i = 0; i < v3.size(); i++)
            std::cout << v3.at(i) << " ";
    }
   std:: cout << std::endl << std::endl;
   
   std::cout << "Test za stringove..." << std::endl;
   for(int j = 0; j < 1; j++){
        int n, m;
        std::cout << "Unesite broj elemenata prvog vektora: ";
        std::cin >> n;
        std::cin.ignore(10000, '\n');
        std::vector <std::string> v1(n);
        std::cout << "Unesite elemente prvog vektora (ENTER nakon svakog unosa): ";
        for(int i = 0; i < n; i++){
            std::string m;
            std::getline(std::cin, m);
            v1.at(i) = m;
        }
        int l;
        std::cout << "Unesite broj elemenata drugog vektora: ";
        std::cin >> l;
        std::vector <std::string> v2(l);
        std::cout << "Unesite elemente drugog vektora (ENTER nakon svakog unosa): ";
        for(int i = 0; i < l; i++){
            std::string m;
            std::getline(std::cin, m);
            v2.at(i) = m;
        }
        std::vector <std::string> v3;
        v3 = Presjek(v1, v2);
        std::cout << "Zajednicki elementi su: ";
        for(int i = 0; i < v3.size(); i++)
            std::cout << std::endl << v3.at(i);
   }
    
	return 0;
}