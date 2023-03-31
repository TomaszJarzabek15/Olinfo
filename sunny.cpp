#include <iostream>

using namespace std;

int main(){
	
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
	int i,j,k,t,t2,l;
	bool controllo=0;
	unsigned n,m,h,s;
	cin >> n >> m >> h >> s;
	unsigned c=0;
	bool fg[50001]={0};
	int g[50001];
	unsigned min[50001]={50001};
	for(i=0;i<m;i++){
		cin >> t >> t2 >> l;
		if(l<min[t]){
			g[t]=t2;
			min[t]=l;
		}
		if(l<min[t2]){
			g[t2]=t;
			min[t2]=l;
		}
	}
	while(!fg[h]){
		fg[h]=1;
		if(h==s){
			controllo=1;
			break;
		}
		h=g[h];
		c++;
	}
	if(controllo==1)
		cout << c;
	else
		cout << -1;
	return 0;
}
