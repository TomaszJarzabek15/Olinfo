#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> numeri;

long long memo[501][501];			//di due dimensioni una per tenere l e l'altra per r

long long picco_massimo(int l, int r) {
	
	if(r - l == 1) {			//se c'è un solo elemento spendiamo 0
		return 0;
	}
	
	if(memo[l][r] != -1)		//vuol dire che l'abbiamo già calcolata una volta e lo returniamo
		return memo[l][r];
	

	long long ans = 2e16;
	for(int m = l + 1; m < r; m++){ 
		long long picco_l = picco_massimo(l, m);
		long long picco_r = picco_massimo(m, r);
		long long picco = max(picco_l, picco_r);
		ans = min(ans, picco);
	}
	
	long long somma = 0;
	
	for(int i = l; i < r; i++){
		somma += numeri[i];
	}
	
	memo[l][r] = max(ans, abs(somma));				//valore assoluto della somma con abs()
	return memo[l][r];
}

int main(){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin.sync_with_stdio(false);
	fin.tie(NULL);
	
	int n;
	fin >> n;
	numeri.resize(n);
	
	for(int i = 0; i < 501; i++){
		for(int j = 0; j < 501; j++){
			memo[i][j] = -1;			//perché se no 0 è un valore valido
		}
	}
	
	for(int i = 0; i < n; i++)
		fin >> numeri[i];
	
	fout << picco_massimo(0, n);		//passiamo l'array intero
}
