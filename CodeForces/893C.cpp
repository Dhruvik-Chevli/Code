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
vector<vector<ll> >graph(100000);
vector<pair<ll,ll> >prices(100000,make_pair(0,0));
vector<bool>visited(100000,false);
void dfs(vector<vector<ll> >&graph,vector<bool>&visited,ll start)
{
    visited[start]=true;
    FOR(i,0,graph[start].size())
    {
        if(!(visited[graph[start][i]]))
        {
            dfs(graph,visited,graph[start][i]);
        }
    }
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    FOR(i,0,n)
    {
        ll k;
        cin>>k;
        prices[i].first=k;
        prices[i].second=i;
    }
    FOR(i,0,m)
    {
        ll u,v;
        cin>>u>>v;
        graph[u-1].pb(v-1);
        graph[v-1].pb(u-1);
    }
    sort(prices.begin(),prices.begin()+n);
    // FOR(i,0,n)
    // {
    //     cout<<prices[i].first<<" "<<prices[i].second<<" "<<visited[i]<<"\n";
    // }
    ll cost=0;
    FOR(i,0,n)
    {
        if(!(visited[prices[i].second]))
        {
            cost+=(prices[i].first);
            dfs(graph,visited,prices[i].second);
        }
    }
    cout<<cost<<"\n";
    return 0;
}