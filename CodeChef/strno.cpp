#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
void solve(int n, int k) 
{ 
    vector<int> P; 
  
    while (n%2 == 0) 
    { 
        P.push_back(2); 
        n /= 2; 
    } 
  
    for (int i=3; i*i<=n; i=i+2) 
    { 
        while (n%i == 0) 
        { 
            n = n/i; 
            P.push_back(i); 
        } 
    } 
    if (n > 2) 
        P.push_back(n); 
  
    if (P.size() < k) 
    { 
        cout << "0" << endl; 
        return; 
    } 
  
    // printing first k-1 factors 
    cout<<"1"<<endl; 
  
    // calculating and printing product of rest 
    // of numbers 
} 
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll x,k;
        cin>>x>>k;
        ll count=0;
        solve(x,k);
    }
    return 0;
}