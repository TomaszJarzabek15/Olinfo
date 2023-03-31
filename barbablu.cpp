#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//100/100

int n,m,e,k;
vector <pair <int,int> > *l = new vector <pair <int,int> >[31]; //adj list
vector <bool> f(31,0); //flag

int main(){
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	
	cin >> n >> m >> e >> k;
	int i,j,t,t2,t3;
	for(i=0;i<k;i++){
		cin >> t;
		f[t]=1; //aria = 1
	}
	for(i=0;i<m;i++){
		cin >> t >> t2 >> t3;
		if(t3>20)
			continue;
		l[t].push_back(make_pair(t2,t3));
		l[t2].push_back(make_pair(t,t3));
	}
	
	//dijkstra
	
	vector <int> d(31,1e9);
	vector <int> dprec(31,0);
	vector <pair <int,int> > q;
	d[1]=0;
	int sus=0; //ul
	q.push_back(make_pair(1,0));
	while(!q.empty()){
		sus++; //ul
		int min=1e9,imin=1;
		for(i=0;i<q.size();i++){
			if(min>q[i].second){
				min=q[i].second;
				imin=i;
			}
		}
		int nodo = q[imin].first;
		q.erase(q.begin()+imin);
		for(pair <int,int> node : l[nodo]){
			int dtemp = d[nodo]+node.second;
			if(f[nodo]!=1 && node.second+dprec[nodo]>20)
				continue;
			if(dtemp<d[node.first]){
				d[node.first]=dtemp;
				if(f[node.first]!=1)
					dprec[node.first]=node.second+dprec[nodo];
				q.push_back(make_pair(node.first,dtemp));
			}
		}
	}
	if(d[e]==1e9)
		cout << -1 <<endl;
	else
		cout << d[e] << endl;
	return 0;
}
