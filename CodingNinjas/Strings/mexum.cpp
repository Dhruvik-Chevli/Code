#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_set>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 998244353
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
        x = (x*x) % MOD;  
    }  
    return res;  
}  
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,q;
    cin>>n>>m>>q;
    vector<ll>v(100005,0);
    FOR(i,0,n)
    {
        ll k;
        cin>>k;
        v[k]++;
    }
    ll sum=power(2,n-v[1]);
    ll sub=power(2,v[i])-1;
    ll cur=v[1];
    FOR(i,2,100001)
    {
        if(v[i]!=0)
        {
            ll u=power(2,v[i])-1;
            sum=sum+(u-1)*i;
            ll v=power(2,v[j]+cur);
            v-=
        }
    }
    return 0;
}