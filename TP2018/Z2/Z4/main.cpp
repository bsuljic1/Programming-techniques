/* TP, 2018/2019
*/
#include <iostream>

long long int **StirlingoviBrojeviV1 (int n)
{
    if(n < 0) throw std::domain_error("Parametar ne smije biti negativan");
    long long int **matrica = nullptr;
    try {
        matrica = new long long int*[n+1] {};
        for(int i = 0; i < (n+1); i++)
            matrica[i] = new long long int[i+1];
        for(int i = 0; i < (n+1); i++) {
            for(int j = 0; j < (i+1); j++) {
                if(i == 0 && j == 0) matrica[i][j] = 1;
                else if(j == 0) matrica[i][j] = 0;
                else if(i == j) matrica[i][j] = matrica[i-1][j-1];
                else matrica[i][j] = matrica[i-1][j-1] + j*matrica[i-1][j];
            }
        }
    } catch(std::bad_alloc e) {
        if(matrica != nullptr)
            for(int i = 0; i < (n+1); i++) delete[] matrica[i];
        delete[] matrica;
        throw std::range_error("Parametar prevelik za raspolozivu memoriju");
    }
    return matrica;
}

long long int **StirlingoviBrojeviV2 (int n)
{
    if(n < 0) throw std::domain_error("Parametar ne smije biti negativan");
    long long int **matrica = nullptr;
    try {
        matrica = new long long int*[n+1] {};
        matrica[0] = new long long int[(n+1)*(n+2)/2];
        for(int i = 1; i < (n+1); i++)
            matrica[i] = matrica[i-1] + i;
        for(int i = 0; i < (n+1); i++) {
            for(int j = 0; j < (i+1); j++) {
                if(i == 0 && j == 0) matrica[i][j] = 1;
                else if(j == 0) matrica[i][j] = 0;
                else if(i == j) matrica[i][j] = matrica[i-1][j-1];
                else matrica[i][j] = matrica[i-1][j-1] + j*matrica[i-1][j];
            }
        }
    } catch(std::bad_alloc e) {
        if(matrica != nullptr)
            delete[] matrica[0];
        delete[] matrica;
        throw std::range_error("Parametar prevelik za raspolozivu memoriju");
    }
    return matrica;
}

int main ()
{
    int n;
    std::cout << "Unesite broj redova: ";
    std::cin >> n;

    try {
        auto matrica1 = StirlingoviBrojeviV1(n);
        for(int i = 0; i < (n+1); i++) {
            for(int j = 0; j < (i+1); j++)
                std::cout << matrica1[i][j] << " ";
            std::cout << std::endl;
        }
        for(int i = 0; i < n+1; i++) delete[] matrica1[i];
        delete[] matrica1;

        auto matrica2 = StirlingoviBrojeviV2(n);
        for(int i = 0; i < (n+1); i++) {
            for(int j = 0; j < (i+1); j++)
                std::cout << matrica2[i][j] << " ";
            std::cout << std::endl;
        }
        delete[] matrica2[0];
        delete[] matrica2;
    } catch(std::domain_error e) {
        std::cout << "Izuzetak: " << e.what();
    } catch(std::range_error e) {
        std::cout << "Izuzetak: " << e.what();
    }

    return 0;
}
