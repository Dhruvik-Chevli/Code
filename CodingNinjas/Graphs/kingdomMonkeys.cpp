#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<climits>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
void dfs(vector<vector<ll> >&graph,vector<ll>&visited,vector<ll>&ban,ll &cost,ll start)
{
    visited[start]=1;
    FOR(i,0,graph[start].size())
    {
        if(!visited[graph[start][i]])
        {
            cost+=ban[graph[start][i]];
            dfs(graph,visited,ban,cost,graph[start][i]);
        }
    }
}
void solve(vector<vector<ll> >&graph,vector<ll>ban,ll n)
{
    vector<ll>visited(n,0);
    ll cost;
    ll max=-INT_MAX;
    FOR(i,0,n)
    {
        if(!visited[i])
        {
            cost=ban[i];
            dfs(graph,visited,ban,cost,i);
            if(cost>max)
            {
                max=cost;
            }
        }
    }
    cout<<max<<"\n";
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vector<ll> >graph(n);
        FOR(i,0,m)
        {
            ll u,v;
            cin>>u>>v;
            graph[u-1].pb(v-1);
            graph[v-1].pb(u-1);
        }
        vector<ll>ban(n,0);
        FOR(i,0,n)
        {
            cin>>ban[i];
        }
        solve(graph,ban,n);
    }
    return 0;
}