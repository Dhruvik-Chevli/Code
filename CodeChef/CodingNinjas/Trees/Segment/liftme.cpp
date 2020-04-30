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
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        ll cur=0;
        ll ans=0;
        FOR(i,0,q)
        {
            ll l,r;
            cin>>l>>r;
            ans+=abs(cur-l);
            ans+=abs(r-l);
            cur=r;
        }
        cout<<ans<<"\n";
    }
    return 0;
}