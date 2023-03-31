#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>
using namespace std;
vector<vector<int> >adj;
vector<int>dist;
vector<bool>vis;
vector<bool>sup;
queue<pair<int,int> >coda;
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n,m,k;
    in>>n>>m>>k;
    adj.resize(n);
    dist.resize(n,1e9);
    vis.resize(n,false);
    sup.resize(n,false);
    for(int i=0;i<k;i++)
    {
        int tmp;
        in>>tmp;
        tmp--;
        sup[tmp]=true;
    }
    for(int i=0;i<m;i++)
    {
        int tmp1,tmp2;
        in>>tmp1>>tmp2;
        tmp1--;
        tmp2--;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }
    dist[0]=0;
    coda.push(make_pair(0,-1));
    vis[0]=true;
    while(!coda.empty())
    {
        pair<int,int>tmp=coda.front();
        int source=tmp.first;
        if(tmp.second!=-1)
            dist[source]=dist[tmp.second]+1;
        coda.pop();
        for(int i=0;i<adj[source].size();i++)
        {
            if(!vis[adj[source][i]])
            {
                vis[adj[source][i]]=true;
                coda.push(make_pair(adj[source][i],source));
            }
        }
    }
    int minimo=1e9;
    vector<bool>v;
    vector<int>dist2(n,1e9);
    v.clear();
    int p=n-1;
    queue<pair<int,int> >cod;
    dist2[p]=0;
    v.resize(n,false);
    int soure=p;
    cod.push(make_pair(p,-1));
    v[p]=true;
    while(!cod.empty()&&dist2[soure]<minimo)
    {
        pair<int,int>tmp=cod.front();
        soure=tmp.first;
        if(tmp.second!=-1)
            dist2[soure]=dist2[tmp.second]+1;
        cod.pop();
        for(int i=0;i<adj[soure].size();i++)
        {
            if(!v[adj[soure][i]])
            {
                v[adj[soure][i]]=true;
                cod.push(make_pair(adj[soure][i],soure));
            }
        }
    }
    for(int c=0;c<n;c++)
    {
        if(sup[c])
        {

            if(minimo>dist2[c]+dist[c])
                minimo=dist2[c]+dist[c];
        }
    }
    out<<minimo;
    return 0;
}
