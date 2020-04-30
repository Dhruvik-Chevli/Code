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
ll power(ll x, ll y)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % MOD; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % MOD;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) %MOD;  
    }  
    return res;  
}  
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,a;
        cin>>n>>a;
        ll ans=0;
        ll k=1;
        ll cur=a;
        FOR(i,0,n)
        {   //cout<<k<<" "<<cur<<" "<<ans<<" "<<endl;
            ll p=power(cur,k);
            cur=(cur*p)%MOD;
            k+=2;
            ans=(ans+p)%MOD;
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}