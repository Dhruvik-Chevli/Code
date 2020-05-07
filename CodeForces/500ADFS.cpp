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
bool dfs(vector<vector<ll> >graph,vector<bool>&visited,ll start,ll t)
{
    if(start==t)
    {
        return true;
    }
    //cout<<"*";
    visited[start]=true;
    FOR(i,0,graph[start].size())
    {
        if(!(visited[graph[start][i]]))
        {
            if(dfs(graph,visited,graph[start][i],t))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,t;
    cin>>n>>t;
    vector<ll>a(n+1,0);
    vector<vector<ll> >graph(n+1,vector<ll>());
    FOR(i,1,n)
    {
        cin>>a[i];
        graph[i].pb(i+a[i]);
      //  cout<<"*";
    }
    //cout<<"^";
    vector<bool>visited(n,false);
    if(dfs(graph,visited,1,t))
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    return 0;
}