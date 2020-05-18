#include <bits/stdc++.h> 
using namespace std; 
int MaximumDivisors(int X, int Y) 
{
    int arr[Y - X + 1]; 
    memset(arr, 0, sizeof(arr)); 
    int mx = INT_MIN; 
    int cnt = 0; 
  
    for (int i = 1; i * i <= Y; i++) { 
        int sq = i * i; 
        int first_divisible; 
        if ((X / i) * i >= X) 
            first_divisible = (X / i) * i; 
        else
            first_divisible = (X / i + 1) * i; 
        for (int j = first_divisible; j <= Y; j += i) { 
            if (j < sq) 
                continue; 
            else if (j == sq) 
                arr[j - X]++; 
            else
                arr[j - X] += 2; 
        } 
    } 
    for (int i = X; i <= Y; i++) { 
        if (arr[i - X] > mx) { 
            cnt = 1; 
            mx = arr[i - X]; 
        } 
        else if (arr[i - X] == mx) 
            cnt++; 
    } 
  
    return cnt; 
} 
  
// Driver code 
int main() 
{ 
    int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		cout<<MaximumDivisors(a,b)+1<<"\n";
	}
  
    return 0; 
} 