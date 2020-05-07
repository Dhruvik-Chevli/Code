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
ll solve(ll* count,ll v[],ll start)
{
    if(count[start]==1)
    {
        return start;
    }
    count[start]=1;
    return solve(count,v,v[start]);
}
// ll solveHelp(ll count[],ll v[],ll start)
// {
//     return solve(count,v,start);
// }
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll v[n+1];
    
    ll ans[n+1];
    FOR(i,1,n+1)
    {
        cin>>v[i];
    }
    FOR(i,1,n+1)
    {
        ll count[n+1];
        FOR(j,0,n+1)
        {
            count[j]=0;
        }
        count[i]=1;
        ll k=solve(count,v,v[i]);
        ans[i]=k;
    }
    FOR(i,1,n+1)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}