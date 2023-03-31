#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdio>
#include <cstring>

struct sito
{
    char nome[20];
    char indirizzo[20];
    char password[20];
};

using namespace std;
    
void Ordina(struct sito vet[], int dim);
void LeggiRubrica(struct sito vet[], int &dim);
void Inserisci(struct sito vet[], int &n);
void Visualizza(struct sito vet[], int dim);
void Cerca(struct sito vet[], int n);
void Elimina(struct sito vet[], int &n);
void Inserisci(struct sito vet[], int &n);

int main()
{
    struct sito vet[100]; //Dimensione fisica del vettore
    int i,n; 
    
    int dim;
    
    LeggiRubrica(vet, dim);
    
    //Ordina(vet, dim);
    
    //Stampa per controllo 
    for(i=0; i<dim; i++)
    {
        printf("nome: %s\n", vet[i].nome);
        printf("\n");
    }
    
    int scelta;
    n=dim;

	do
	{
		
	    cout<<"Scegliere un opzione:"<<endl;
	    cout<<endl<<"1. Inserisci nuovo contatto"<<endl<<"2. Cerca sito"<<endl<<"3. Elimina sito"<<endl<<"4. Visualizza rubrica"<<endl<<"5. Esci dal programma"<<endl<<endl;
	    cin>>scelta;
	
	    switch(scelta)
	    {
	    	case 1:
				Inserisci(vet, n);
        		
        		break;
	    	
		    case 2:
		    	
		    	Cerca(vet, n);
	 
	        break;
	    
		    case 3:
		    	
		    	Elimina(vet, n);
	
		    break;
		
		    case 4:
		    	
		    	Visualizza(vet, n);

		    break;
		    
		    case 5:
		    	
		    	return 0;
		    	
		    break;
	    }
    }while(scelta<0 || scelta>5);
	
	//Stampa per controllo ordinamento
    for(i=0; i<n; i++)
    {
        printf("nome: %s\n", vet[i].nome);
        printf("\n");
    }
}
    
void Ordina(struct sito vet[], int dim)
{
    int i, confronta; 
    bool sentinella;
    struct sito app;
    do
    {
        sentinella=false;
        for(i=0; i<dim+1; i++)
        {
            confronta=strcmp(vet[i].nome, vet[i+1].nome);
            if(confronta>0)
            {
                sentinella=true;
                app=vet[i];
                vet[i]=vet[i+1];
                vet[i+1]=app;
            }   
        }
    } while(sentinella);
}

void LeggiRubrica(struct sito vet[], int &dim){
	
	int i=0;
	
	ifstream fin;
	fin.open("Rubrica.txt");
	
	if(fin.is_open()==false)
    {
        cout<<"File inesistente!";
        dim=0;
    }
    else
    {
    
        while(fin.eof()==false)
        {
        	fin>>dim;
			for(i=0; i<dim; i++){
				fin>>vet[i].nome;
				fin>>vet[i].indirizzo;
				fin>>vet[i].password;
			}
        }
    }
    
    fin.close();
    
    ofstream fout;
    fout.open("Rubrica.txt");
 
	fout<<endl<<dim;
	
	for(i=0; i<dim; i++)
    {
        fout<<endl<<vet[i].nome;
        fout<<endl<<vet[i].indirizzo;
        fout<<endl<<vet[i].password;
    }

	fout.close();
}

void Visualizza(struct sito vet[], int dim){
	int i;
	
	for(i=0; i<dim; i++)
    {
        printf("\nnome: %s\n", vet[i].nome);
        printf("indirizzo: %s\n", vet[i].indirizzo);
        printf("password: %s\n", vet[i].password);
        printf("\n");
    }
    
    //Ordina(vet, dim);
}

void Cerca(struct sito vet[ ], int n)
{
	char cerca[100];
	cout<<endl<<"inserire sito da cercare: ";
	cin>>cerca;
	
	for(int i=0; i<n; i++)
	{
		if(strcmp(vet[i].nome, cerca)==0)
		{
			cout<<endl<<vet[i].nome<<endl<<vet[i].indirizzo<<endl<<vet[i].password;
		}
    }
} 

void Elimina(struct sito vet[ ], int &n)
{
	char elimina[100];
	cout<<endl<<"inserire sito da eliminare: ";
	cin>>elimina;
	for(int i=0; i<n; i++)
	{
		if(strcmp(vet[i].nome, elimina)==0){
			strcpy(vet[n].nome, vet[i].nome);
			strcpy(vet[n].indirizzo, vet[i].indirizzo);
			strcpy(vet[n].password, vet[i].password);
		}; 
	}
	n--;
	
	Visualizza(vet, n);
}

void Inserisci(struct sito vet[], int &n){
	
	printf("nome: ");
    scanf("%s",vet[n].nome);
    printf("url: ");
    scanf("%s",vet[n].indirizzo);
    printf("password: ");
    scanf("%s",vet[n].password);
    
    n++;
    
    //Ordina(vet,n);
}
    
