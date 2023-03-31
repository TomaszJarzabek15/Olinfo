#include <iostream>
#include <vector>
#include <cmath>

struct nodo{
    int monete;
    std::vector <int> figli;
};

int DFS (std::vector <nodo> &grafo, int u, int &totale){
    for(int i = 0; i < grafo[u].figli.size(); i++){
        grafo[u].monete += DFS(grafo, grafo[u].figli[i], totale);
    }
    int monete = grafo[u].monete - 1;
    grafo[u].monete = 1;
    totale += abs(monete);
    return monete;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    std::cin >> n;

    std::vector <nodo> grafo (n);

    for(auto &i:grafo)
        std::cin >> i.monete;

    for(int i = 1; i < n; i++){
        int padre;
        std::cin >> padre;
        grafo[padre-1].figli.push_back(i);
    }

    int totale = 0;
    DFS(grafo, 0, totale);

    std::cout << totale;
}