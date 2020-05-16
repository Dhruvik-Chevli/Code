#include <iostream>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int nbTests; 
	cin >> nbTests;
	
	while (nbTests--) 
	{
		int nbElem; 
		cin >> nbElem;
		
		vector<int> tab(nbElem);

		for (int i = 0; i < nbElem; ++i)
			cin >> tab[i];

		int prefixEnd = -1, suffixEnd = nbElem;

		for (int i = 0; i < nbElem; ++i) 
		{
			if (tab[i] < i) break;
			prefixEnd = i;
		}
		
		for (int i = nbElem - 1; i >= 0; --i) 
		{
			if (tab[i] < (nbElem - 1) - i) break;
			suffixEnd = i;
		}

		if (suffixEnd <= prefixEnd) 
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}