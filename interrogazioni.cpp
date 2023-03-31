#include <iostream>
#include <fstream>
#include <cstdio>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main() {
	
	ifstream fin;
	fin.open("classe.txt");
	
	srand(time(0));
	
	int n, i=0, interrogato, continua;
	char studente[20], s_interrogato[20];
	fin>>n;
	int interrogati[n]={0};
	char valutato[20];
	

	
	if(fin.is_open()==false)
    {
        cout<<"File inesistente!";
    }
    else
    {
    	fin>>n;
    	int cognome [n][20];
    	
    	for(i=0; i<n; i++){
    		fin>>cognome;
		}
    	
    	do{
    		
		}
    	
    	interrogato=rand()%n;
		for(i=0; i<n; i++){
			fin>>studente;
			if(i==interrogato) strcpy(s_interrogato, studente);
		 
			cout<<endl<<studente;
		}
		cout<<endl<<"Interrogato: "<<cognome[interrogato];
		strcpy(cognome[interrogato], cognome[n-1]);
		n--;
    }


	
	do{
		cout<<endl<<"ancora (1=si)?";
		cin>>continua;
	}while();
	fin.close();
	
	ofstream fout;
	fout.open("interrogati.txt");
	int valutazione;
	
	fout<<valutato;
	cout<<endl<<"che valutazione (numerica): ";
	cin>>valutazione;
	fout<<valutazione;
}

