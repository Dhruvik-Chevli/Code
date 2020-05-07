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
void dfs(vector<vector<ll> >&graph,ll start,vector<bool>&visited,vector<ll>&level, ll lev)
{
    visited[start]=true;
    level[start]=lev;
    FOR(i,0,graph[start].size())
    {
        if(!(visited[graph[start][i]]))
        {
            dfs(graph,graph[start][i],visited,level,lev+1);
        }
    }
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<vector<ll> >graph(n,vector<ll>());
    FOR(i,0,n-1)
    {
        ll u,v;
        cin>>u>>v;
        graph[u-1].pb(v-1);
        graph[v-1].pb(u-1);
    }
    vector<bool>visited(n,false);
    vector<ll>level(n,-1);
    dfs(graph,0,visited,level,0);
    ll l=0;
    FOR(i,0,n)
    {
        if(level[i]%2==1)
        {
            l+=1;
        }
    }
    cout<<l*(n-l)-(n-1)<<endl;
    return 0;
}