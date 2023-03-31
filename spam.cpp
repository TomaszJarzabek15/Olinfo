#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * function classifying an email.
 * return:
 *   1 for likely legitimate,
 *   0 for dubious,
 *  -1 for likely spam.
 */
int detect(vector<string>& bad, vector<string>& good, vector<string>& email, int length, int N) {
    // insert your code here
    int S=0, i=0, j=0;
    int res=0;
    
    for(i=0; i<N; i++){
    	for(j=0; j<bad.size(); j++){
    		if(email[i]==bad[j]){
    			S--;
			}
		}
		for(j=0; j<good.size(); j++){
			
			if(email[i]==good[j]){
				S++;
			}
		}
	}
	
	if(S<=-1) res=-1;
	if(S==0)  res=0;
	if(S>=1)  res=1;
	
    return res;
}


vector<string> bad;
vector<string> good;
vector<string> email;

int main() {
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int B, G, E, N;
    int spam = 0, legit = 0;
    int length;

    cin >> B;
    bad.resize(B);
    for (int i=0; i<B; i++) cin >> bad[i];
    cin >> G;
    good.resize(G);
    for (int i=0; i<G; i++) cin >> good[i];
    cin >> E;
    
    if(B>=G){
    	length=B;
	}
	else{
		length=G;
	}
    
    
    for (int j=0; j<E; j++) {
        cin >> N;
        email.resize(N);
        for (int i=0; i<N; i++) cin >> email[i];
        int res = detect(bad, good, email, length, N);
        if (res == -1) spam++;
        if (res == 1)  legit++;
    }
    cout << spam << " " << legit << endl;
    return 0;
}
