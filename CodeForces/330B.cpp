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
    ll n,m;
    cin>>n>>m;
    vector<bool>pres(n,false);
    FOR(i,0,m)
    {
        ll u,v;
        cin>>u>>v;
        pres[u-1]=true;
        pres[v-1]=true;
    }
    ll ans=-1;
    FOR(i,0,n)
    {
        if(pres[i]==false)
        {
            ans=i;
            break;
        }
    }
    cout<<n-1<<"\n";
    FOR(i,0,n)
    {
        if(i==ans)
        {
            continue;
        }
        cout<<ans+1<<" "<<i+1<<"\n";
    }
    return 0;
}