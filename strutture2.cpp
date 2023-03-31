#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

struct voto{
	int voto;
	char giudizio[200];
	char tipo;           
};

struct studente{
	string nome;
	string cognome;
	struct voto voti[10];
	int dimensione;
};

int main(){
	
	int n, i=0, j=0;
	
	cout<<"inserire il numero di studenti: ";
	cin>>n;
	
	struct studente studenti[n];
	
	for(i=0; i<n; i++){
		cout<<"nome: ";
		cin>>studenti[i].nome;
		cout<<"cognome: ";
		cin>>studenti[i].cognome;
		cout<<"numero voti: ";
		cin>>studenti[i].dimensione;
		
		for(j=0; j<studenti[i].dimensione; j++){
			cout<<"voto: ";
			cin>>studenti[i].voti[j].voto;
			cout<<"giudizio: ";
			cin>>studenti[i].voti[j].giudizio;
			cout<<"tipo: ";
			cin>>studenti[i].voti[j].tipo;
		}
	}
	
	for(i=0; i<n; i++){
		cout<<"nome: "<<studenti[i].nome;
		cout<<"cognome: "<<studenti[i].cognome;
		cout<<"numero voti: "<<studenti[i].dimensione;
		
		for(j=0; j<studenti[i].dimensione; j++){
			cout<<"voto: "<<studenti[i].voti[j].voto;
			cout<<"giudizio: "<<studenti[i].voti[j].giudizio;
			cout<<"tipo: "<<studenti[i].voti[j].tipo;
		}
	}
		
}
