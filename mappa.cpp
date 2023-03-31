#include <bits/stdc++.h>
using namespace std;

int mappa[100][100];

void solve(int i, int j, int n)
{
	//Visito le celle vicino a i,j includendo la stessa casella anche
	for(int a =-1;a<2;a++)
	{
		for(int b=-1;b<2;b++)
		{
			if( i+a < 0 || i+a > n-1 || b+j < 0 || j+b > n-1)
			{
				continue;
			}
			
			if(mappa[i+a][j+b] == 0 || mappa[i+a][j+b] > mappa[i][j] + 1)
			{
				mappa[i+a][j+b] = mappa[i][j] +1;
				solve(i+a,j+b,n);
			}
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin); 
	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		for(int y= 0;y<n;y++)
		{
			char appo;
			cin>>appo;
			if(appo == '*')
				mappa[i][y] = 0;
			else 
				mappa[i][y] = -1;
		}
	}
	
	mappa[0][0] = 1;
	solve(0,0,n);
	cout<<mappa[n-1][n-1];
	
	return 0;
}

