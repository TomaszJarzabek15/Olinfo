#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

 //100/100
 
int m[30][30];
int c=0; //amogus sus
int k,n;
int a[30]; //valore crediti esami
vector <bool> fm(30,0); //flag

int solve(int idx, int tot, int ore){
	fm[idx]=1;
	if(tot>=k){
		return ore;
	}
	int i;
	int min=30;
	for(i=0;i<n;i++){
		if(m[idx][i]==0 || fm[i])
			continue;
		
		int t = solve(i,tot+a[i], ore+m[idx][i]);
		fm[i]=0;
		
		if(min>t){
			min=t;
		}
	}
	
	return min;
}

int main(){
	
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int min=30;
	cin >> k;
	cin >> n;
	int i,j;
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin >> m[i][j];
		}
	}
	
	for(i=0;i<n;i++){
			int t = solve(i,a[i],0);
			if(min>t){
				min=t;
			}
		for(j=0;j<n;j++)
			fm[j]=0;
	}
	
	cout << min << endl;
	
	return 0;
}
