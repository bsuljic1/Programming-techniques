#include <iostream>


int main()
{
    char sifra[] = {'A', 'B', 'C', 'D, "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
                   for(int i = 0; i < 28; i++)
                       sifra[i] = ((11*sifra[i] – 25)% 26) + 65;
    for(int i = 0; i< 28; i++)
        std::cout << sifra[i];
    return 0;
}
