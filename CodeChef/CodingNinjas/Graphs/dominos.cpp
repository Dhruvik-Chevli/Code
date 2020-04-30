#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_set>
#include<stack>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

void dfs(vector<ll>*edges,ll start,vector<ll>&visited,stack<ll>&s)
{
    visited[start]=1;
    FOR(i,0,edges[start].size())
    {
        if(!visited[edges[start][i]])
        {
            dfs(edges,edges[start][i],visited,s);
        }
    }
    s.push(start);
    return;
}

void dfs2(vector<ll>*edges,ll start,vector<ll>&visited)
{
    visited[start]=1;
    FOR(i,0,edges[start].size())
    {
        if(!visited[edges[start][i]])
        {
            dfs2(edges,edges[start][i],visited);
        }
    }
}

ll getSCC(vector<ll>*edges,ll n)
{
    vector<ll>visited(n,0);
    stack<ll>s;
    ll count=0;
    FOR(i,0,n)
    {
        if(!visited[i])
        {
            //cout<<i<<"^";
            dfs(edges,i,visited,s);
        }
    }
    visited=vector<ll>(n,0);
    while(!s.empty())
    {
        ll u=s.top();
        s.pop();
        if(!visited[u])
        {
            count+=1;
            dfs2(edges,u,visited);
        }
    }
    return count;
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
        vector<ll>*edges = new vector<ll>[n];
        FOR(i,0,m)
        {
            ll u,v;
            cin>>u>>v;
            edges[u-1].pb(v-1);
        }
        cout<<getSCC(edges,n)<<"\n";
        
    }
    return 0;
}