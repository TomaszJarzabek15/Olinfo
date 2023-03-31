#include <iostream>
#include <string>

using namespace std;

struct cella{
	
	char c;
	cella* next;
	
};

using lista = cella*;

void append(lista& F, lista& L, char c){
	
	if(L == nullptr){
		
		L = new cella {c,nullptr};
		F = L;
		
	}else{
		
		L->next = new cella {c,nullptr};
		L = L->next;
		
	}
	
}

void print(lista F){
	
	while(F != nullptr){
		
		cout << F->c;
		F = F->next;
		
	}
	
}

void insert(lista& F, lista& L, cella* ptr, char c){
	
	if(F == nullptr){
			
		append(F,L,c);
			
	}else{

		ptr->next = new cella{c,ptr->next};
		
		if(ptr == L) L = ptr->next;
		
	}
	
}




int main(){
	
	lista F = nullptr;
	lista L = nullptr;
	
	append(F,L,'c');
	append(F,L,'i');
	append(F,L,'a');
	append(F,L,'o');

	cella* ptr = F;
	ptr = ptr->next;
	ptr = ptr->next;

	insert(F,L,ptr,'d');

	print(F);

}
