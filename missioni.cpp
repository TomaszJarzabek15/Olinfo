#include <iostream>
#include <vector>

using namespace std;

int N;
pair<int,int> table[100];

int cache[100][365];

int solve(int t,int from){
    if(from == N) return 0;
    if(cache[from][t] != 0)
        return cache[from][t];

    if(table[from].first+t<=table[from].second)
        cache[from][t] = max(solve(table[from].first+t,from+1)+1,solve(t,from+1));
    else
        cache[from][t] = solve(t,from+1);
    
    return cache[from][t];
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);    

    cin >> N;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        table[i] = make_pair(a,b);
    }

    cout << solve(0,0) << endl;

}



