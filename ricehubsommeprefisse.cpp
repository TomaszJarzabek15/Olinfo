#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <numeric>
#include <assert.h>
#include <algorithm>

using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector <long long> v;

long long sum(int l, int r){
	assert(l <= r);
    return v[r] - (l > 0 ? v[l-1] : 0);
}

int main() {
	
	int n; long long b;
	fin >> n >> b;
	
	//vector<long long> s(n);			//non c'è molta memoria quindi fare due vettori long long forse non sta nei tempi
	//s[0] = v[0];					//allora basta fare solo il vettore delle somme prefisse perchè quello normale non serve più
	/*
	for(int i = 1; i < n; i++){
		s[i] = v[i] + s[i-1];
	}
	*/
	v.resize(n);
	for(auto &x : v){
		fin >> x;
	}
	
	
	partial_sum(v.begin(), v.end(), v.begin());
	//for(int i = 1; i < n; i++) v[i] += v[i-1]
	
	int ans = 0;
	
	for(int i = 0; i< n; i++){
		
		long long pos = sum(i,i);
		
		int l = 0, r = n/2;
		
		while(l != r){
			//approssimo per eccesso per non dover mai controllare m=0
			int m = (l+r+1) /2;
			
			bool ok = 0;
			
			if(i-m >= 0 && i+m < n) {
				//long long pos = v[i] - v[i-1];
				// calcolo il costo del blocco di sinistra
				long long sx = pos * m - sum(i-m, i-1); 
				//calcolo il costo del blocco di destra
				long long dx = sum(i+1, i+m) - pos * m;
				//controllo se ho sforato il budget
				if(sx +dx <= b){
					ok = 1;
				}
			}
			if(ok)
				l = m;
				
			else
        		r = m - 1;
		}
	
	
		int covered = 1 + l * 2;
		//calcolo quanto mi rimane dopo aver preso [i-l, i-1] e [i+1, i+l]
		long long sx = (l > 0 ? pos * l - sum(i-l, i-1) : 0);  
    	long long dx = (l > 0 ? sum(i+1, i+l) - pos * l : 0);
   		long long budget_left = b - sx - dx;
   		 //prendo uno in più a sinistra se si può
   		if(i - l -1 >= 0) {
   	 	
    		if(pos - sum(i-l-1, i-l-1) <= budget_left){
    			covered++;
    			budget_left = 0;
    			
			} 	
		}
			//provo a destra
		if(i + l + 1 < n) {
			if(sum(i+l+1, i+l+1) - pos <= budget_left) {
				covered++;
				budget_left = 0;
			}
		}
	
		ans = max(ans, covered);
	}
	
	fout << ans;
}
