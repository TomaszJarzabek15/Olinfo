#include <bits/stdc++.h>
#define MAXS 2000
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, r, sol = 0;
	cin >> k >> r;
	unordered_set<int>sostanzeInserite;
	vector<vector<int>>regole(MAXS + 1);
	for (int i = 0; i < k; i++)
	{
		int temp;
		cin >> temp;
		if(temp == 1) { cout << 0; return 0; }
		sostanzeInserite.insert(temp);
	}
	for (int i = 0; i < r; i++)
	{
		int sostanzaDaInserire, num;
		cin >> sostanzaDaInserire >> num;
		regole[sostanzaDaInserire].resize(num);
		for (int i = 0; i < num; i++)
		{
			cin >> regole[sostanzaDaInserire][i];
		}
	}
	unordered_set<int>sostanzeNecessarie;
	queue<int>temp;
	for(auto x : regole[1])
	{
		sostanzeNecessarie.insert(x);
	}
	while(!sostanzeNecessarie.empty())
	{
	for(auto x : sostanzeNecessarie)
	{
		if (sostanzeInserite.count(x) == 1)
		{
			temp.push(x);
		}
		else
		{
			bool flag = false;
			if(regole[x].empty())
			{
				cout << -1; return 0;
			}
			for(auto y : regole[x])
			{
				if(sostanzeInserite.count(y) == 0 && sostanzeNecessarie.count(y) == 0)
				{
					sostanzeNecessarie.insert(y);
					flag = true;
				}
			}
			if(flag == false)
			{
				temp.push(x);
				sostanzeInserite.insert(x);
				sol++;
			}
		}
	}
	while(!temp.empty()) {sostanzeNecessarie.erase(temp.front()); temp.pop();}
	}
	cout << sol + 1;
	return 0;
}