#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){
	
	int N, i=0, j=0;
	int Sv=0, Sm=0;
	bool incontro=false;
	
	do{
		
		cout<<"inserire il numero di attrazioni: ";
		cin>>N;
	}while(N<0);
	
	int A[N];
	
	cout<<"inserire il numero di secondi per attrazione: ";
	
	for(i=0; i<N; i++){
		cin>>A[i];
	}
	
	j=N-1;
	/*
	for(i=0; i<N-1; i++){

		Sv=Sv+A[i];
		Sm=Sm+A[j];

		if(Sv==Sm && i!=N-1 && j!=0){
			incontro=true;
		}

		j--;
	}	*/
	
	for(i=0; i<N; i++){
		if(i!=0 && i!=N){
			for(j=0; j<N; j++){
				if(j<i) Sv= Sv+A[j];
				else Sm= Sm+A[j];
				
				if(Sm==Sv) incontro==true;
			}
		}
	}
	
	if(incontro==true) cout<<endl<<"Si incontrano, Max e' felice";
	else cout<<endl<<"Non si incontrano, Vanna e' felice";
	
	
}
