#include <iostream>
#include<vector>
using namespace std;
bool isPrime[200];
#define FOR(i,a,b) for(int i=a;i<b;i++)
int n=201;

void SieveOfEratosthenes() 
{ 
    // Initialize all entries of boolean array 
    // as true. A value in isPrime[i] will finally 
    // be false if i is Not a prime, else true 
    // bool isPrime[n+1]; 
    isPrime[0] = isPrime[1] = false; 
    for (int i = 2; i <= n; i++) 
        isPrime[i] = true; 
  
    for (int p = 2; p * p <= n; p++) { 
        // If isPrime[p] is not changed, then it is 
        // a prime 
        if (isPrime[p] == true) { 
            // Update all multiples of p 
            for (int i = p * 2; i <= n; i += p) 
                isPrime[i] = false; 
        } 
    } 
} 
bool findPrimePair(int n) 
{ 
    //bool flag = false; 
  
    // Generating primes using Sieve 
    //bool isPrime[n + 1]; 
    //SieveOfEratosthenes(n, isPrime); 
  
    // Traversing all numbers to find first 
    // pair 
    for (int i = 2; i < n; i++) { 
        int x = n / i; 
  
        if (isPrime[i] && isPrime[x] and x != i and x * i == n) { 
            //cout << i << " " << x; 
            //flag = 1; 
            return true; 
        } 
    } 
  
    return false;
} 
int main() {
	vector<int>primes;
	
	SieveOfEratosthenes();
    // FOR(i,0,200)
    // {
    //     cout<<isPrime[i]<<" ";
    // }
    cout<<endl;
	vector<bool>ninjaNumber(n,false);
	FOR(i,2,201)
	{
		if(findPrimePair(i))
		{
			ninjaNumber[i]=true;
		}
	}
    // FOR(i,0,200)
    // {
    //     cout<<ninjaNumber[i]<<" ";
    // }
    cout<<endl;
	int t;
	cin>>t;
	while(t--)
	{
		int n1;
		cin>>n1;
		int flag=0;
		FOR(i,0,n1/2+1)
		{
			if(ninjaNumber[i]==true and ninjaNumber[n1-i]==true)
			{
				flag=1;
				break;
			}
		}
		if(flag)
		{
			cout<<"YES\n";
		}
		else
			cout<<"NO\n";
	}
    return 0;
}