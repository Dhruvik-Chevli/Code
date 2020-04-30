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
        ll n;
        cin>>n;
        vector<int>p(n,0);
        FOR(i,0,n)
        {
            cin>>p[i];
        }
        sort(p.rbegin(),p.rend());
        ll ans=0;
        FOR(i,0,n)
        {
            if(p[i]-i<=0)
                break;
            p[i]-=i;
            ans=(ans+p[i])%MOD;
        }
        ans=ans%MOD;
        cout<<ans<<endl;
    }
    return 0;
}