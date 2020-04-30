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
#define MOD 1000000007
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<ll,ll>map;
    ll t;
    cin>>t;
    while(t--)
    {
        map.clear();
        ll n;cin>>n;
        ll ans=0;
        ll block=0;
        ll cnt=0;
        FOR(i,0,n)
        {
            ll k;
            cin>>k;
            if(map.count(k)>0)
            {
                block=max(block,map[k]);
                cnt=i-blk-1;
            }
            cnt++;
            map[k]=i;
            ans=max(ans,cnt);
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}