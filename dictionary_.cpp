#include <bits/stdc++.h>
using namespace std;
map<string,int>mappa;
vector<vector<int> >adj(1001);
vector<vector<int> >inv_adj(1001);
vector<string> prova(vector<bool>vis,int n,vector<bool>impara,vector<int>requisiti){
    while (true) {
        vector<pair<int,int> >rimanenti;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                int cnt=0;
                for(int x:inv_adj[i]){
                    if(!vis[x])cnt++;
                }
                rimanenti.push_back({cnt,i});
            }

        }
        if(rimanenti.size()==0)break;
        sort(rimanenti.rbegin(),rimanenti.rend());
        int nodo=rimanenti[0].second;
        for(auto x:rimanenti){
            if(rand()%2){
                nodo=x.second;
                break;
            }
        }
        vis[nodo]=1;
        impara[nodo]=1;
        queue<int>coda;
        coda.push(nodo);
        while (!coda.empty()) {
            int tmp=coda.front();
            coda.pop();
            for(int x:inv_adj[tmp])
            {
                if(vis[x])continue;
                requisiti[x]--;
                if(requisiti[x]==0)
                {
                    vis[x]=true;
                    coda.push(x);
                }
            }
        }
    }
    vector<string>ris;
    for(auto x:mappa){
        if(impara[x.second])ris.push_back(x.first);
    }
    return ris;
}
int main()
{
	int n,d;
	cin>>n>>d;
	int conta=1;

    //costruzione grafo
	for(int i=0;i<d;i++)
	{
		string s;
		cin>>s;
		int pos;
		if(mappa[s]!=0){
            pos=mappa[s];
        }
		else{
			pos=conta;
			mappa[s]=conta++;
		}
		int tmp;
		cin>>tmp;
		for(int j=0;j<tmp;j++)
		{
			cin>>s;
			int p2=mappa[s];
			if(p2==0){
				p2=conta;
				mappa[s]=conta++;
			}
			adj[pos].push_back(p2);
			inv_adj[p2].push_back(pos);
		}
	}

    //prima imparo tutte le parole con in_degree 0, poi imp
	queue<int>coda;
	vector<bool>impara(n+1,false);
	vector<bool>vis(n+1,false);
	vector<int>requisiti(n+1);//tiene quante parole servono alla parola i per essere imparata
	for(int i=1;i<=n;i++)
	{
		requisiti[i]=adj[i].size();
		if(adj[i].size()==0){
			vis[i]=true;
			impara[i]=true;
			coda.push(i);
		}
	}
	while (!coda.empty()) {
		int tmp=coda.front();
		coda.pop();
		for(int x:inv_adj[tmp])
		{
			if(vis[x])continue;
			requisiti[x]--;
			if(requisiti[x]==0)
			{
				vis[x]=true;
				coda.push(x);
			}
		}
	}
	int casi=80;
    vector<string>fine=prova(vis,n,impara,requisiti);
    while (casi--) {
        vector<string>pr=prova(vis,n,impara,requisiti);
        if(pr.size()<fine.size()){
            fine=pr;
        }
    }
	cout<<fine.size()<<"\n";
    for(string x:fine)cout<<x<<" ";
    cout<<"\n";
}
