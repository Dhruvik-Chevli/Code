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
        ll n,x;
        cin>>n>>x;
        vector<ll>v(n,0);
        FOR(i,0,n)
        {
            cin>>v[i];
        }
        sort(v.rbegin(),v.rend());
        vector<ll>sum(n,0);
        sum[0]=v[0];
        FOR(i,1,n)
        {
            sum[i]=sum[i-1]+v[i];
        }
        // FOR(i,0,n)
        // {
        //     cout<<sum[i]<<" ";
        // }
        // cout<<endl;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            if(sum[i]/(i+1)>=x)
            {
                ans=i+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}