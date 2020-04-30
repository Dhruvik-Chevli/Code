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
bool isPowerOfTwo (ll x)  
{  
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));  
}  
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans=0;
        ll cur;
        FOR(i,2,33)
        {
            cur=(1<<i)-1;
            if(n%cur==0)
            {
                ans=n/cur;
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}



1+2+4+8...+2**k-1=(2**k-1)

x*(2**k-1)=n

1
10
100


