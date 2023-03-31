#include <bits/stdc++.h>

using namespace std;

void pianifica(int R, int A[], int B[], int T[]) {
    

	T[0] = A[0];
	
	int l = 1, r = 1e9;		//valore minimo e massimo per la dicotomica
	
	while(l != r){
		
		int m = (l+r+1) /2;			//approssimare per eccesso serve quando è grande 2 per trovare r al posto di l
		int k = m;
		bool ok = true;
		
		for(int i = 1; i < R; i++){
			int almeno = T[i-1] + k;
			
			if(A[i] > almeno) 
				almeno = A[i];
			if(almeno > B[i]){
				ok = false;
				break;
			}
			T[i] = almeno;
		}
		if(ok){
			l = m;
		}
		else {				//perchè l'm non è buono e noi lo facciamo inclusivo
			r = m - 1;
		}
	}
	int k = l; //non è l'ultimo valore quello fa break ma quello prima
	
	for(int i = 1; i < R; i++){		//ci sono più output corretti basta che la distanza sia k
		
		int almeno = T[i-1] + k;
		if(A[i] > almeno)
			almeno = A[i];
		assert(B[i] >= almeno);
		T[i] = almeno;
			
	}
}
