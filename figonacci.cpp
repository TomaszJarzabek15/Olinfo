#include <iostream>
#include <vector>
#include <cmath>

struct figonacci{
    long long num, sott;
};

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, mod;
    std::cin >> n >> mod;
    std::vector <figonacci>vet (n+1);
    vet[0].num = (-1 % mod + mod) % mod;
    vet[0].sott = (1 % mod + mod) % mod;
    vet[1].num = (0 % mod + mod) % mod;
    vet[1].sott = (1 % mod + mod) % mod;
    for(int i = 2; i < n+1; i++){
        vet[i].num = ((vet[i-1].sott + vet[i-1].num*i) % mod + mod) % mod;
        vet[i].sott = ((vet[i-1].sott - vet[i].num) % mod + mod) % mod;
    }

    std::cout << vet[n].num;
}