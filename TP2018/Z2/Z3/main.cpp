/* TP, 2018/2019
*/
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>


template <typename Tip1, typename Tip2, typename Tip3>
auto SimetricnaRazlikaBlokova (Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip3 p5) -> Tip3
{
    Tip1 p1_pom = p1;
    Tip1 p1_pompom = p1;
    Tip2 p3_pom = p3;
    Tip3 p5_pom = p5;
    int p5_vel = 0;

    while(p1 != p2) {
        bool razlika = true;
        while(p3 != p4) {
            if (*p1 == *p3) razlika = false;
            p3++;
        }
        p3 = p3_pom;
        if(!razlika) {
            p1++;
            continue;
        }

        p5_pom = p5 - p5_vel;
        bool postoji = false;
        while(p5_pom != p5) {
            if(*p5_pom == *p1) postoji = true;
            p5_pom++;
        }

        if(postoji) {
            p1++;
            continue;
        }

        *p5 = *p1;
        p5_vel++;
        p5++;
        p1++;
    }

    while(p3_pom != p4) {
        bool razlika = true;
        while(p1_pom != p2) {
            if(*p1_pom == *p3_pom) razlika = false;
            p1_pom++;
        }
        p1_pom = p1_pompom;
        if(!razlika) {
            p3_pom++;
            continue;
        }

        p5_pom = p5 - p5_vel;
        bool postoji = false;

        while(p5_pom != p5) {
            if(*p5_pom == *p3_pom) postoji = true;
            p5_pom++;
        }

        if(postoji) {
            p3_pom++;
            continue;
        }

        *p5 = *p3_pom;
        p5_vel++;
        p5++;
        p3_pom++;
    }

    return p5;
}

int main ()
{
    int n1, n2;
    std::cout << "Unesite broj elemenata niza" << std::endl;
    std::cin >> n1;
    std::cout << "Unesite elemente niza" << std::endl;
    int niz[100];
    for(int i = 0; i < n1; i++)
        std::cin >> niz[i];

    std::cout << "Unesite broj elemenata deka" << std::endl;
    std::cin >> n2;
    std::cout << "Unesite elemente deka" << std::endl;
    std::deque<int> dek(n2);
    std::for_each(dek.begin(), dek.end(), [](int &a) {
        std::cin >> a;
    });

    std::vector<int> niz3(200);
    auto kraj = SimetricnaRazlikaBlokova(niz, niz + n1, dek.begin(), dek.end(), niz3.begin());

    if(niz3.begin() == kraj) std::cout << "Blokovi nemaju simetricnu razliku";
    else {
        std::cout << "Simetricna razlika blokova je:";
        std::for_each(niz3.begin(), kraj, [](int x) {
            std::cout << " " << x;
        });
    }

    return 0;
}
