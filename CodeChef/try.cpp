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
#define MOD 998244353
ll gcdExtended(ll a, ll b, ll *x, ll *y); 
int power(ll x, ll y, ll p)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (modInverse(x,MOD)*modInverse(x,MOD))%MOD;  
    }  
    return res;  
}  
  
// Function to find modulo inverse of a 
ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        //cout << "Inverse doesn't exist"; 
        return 0;
    else
    { 
        // m is added to handle negative x 
        ll res = (x%m + m) % m; 
        return res; 
    } 
} 
  
// C function for extended Euclidean Algorithm 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<modInverse(4,MOD)<<endl;
    ll t=(1*(modInverse(4,MOD)))%MOD;
    cout<<((t*t)%MOD+(t*t)%MOD)%MOD;
    ll t=
    return 0;
}