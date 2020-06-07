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
        ll n,k;
        cin>>n>>k;
        vector<ll>v(n);
        FOR(i,0,n)
        {
            cin>>v[i];
        }
        vector<ll>count(2*k+1,0);
        vector<ll>post(2*k+2,0);
        FOR(i,0,n/2)
        {
            ll mi=min(v[i],v[n-i-1])+1;
            ll ma=max(v[i],v[n-i-1])+k;
            post[mi]++;
            post[ma+1]--;
            count[v[i]+v[n-i-1]]++;
        }
        ll ans=n;
        FOR(i,1,2*k+2)
        {
            post[i]+=post[i-1];
        }
        FOR(i,2,2*k+1)
        {
            ll y=(n/2-post[i])*2;
            y+=post[i]-count[i];
            ans=min(ans,y);
        }
        cout<<ans<<"\n";
    }
    return 0;
}