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
void DSUinit(vector<ll>&a,vector<ll>&size,ll n)
{
    FOR(i,0,n)
    {
        a[i]=i;
        size[i]=1;
    }
    return;
}
ll root(vector<ll>&a,ll i)
{
    return (i==a[i])?i:a[i]=root(a,a[i]);
}
bool DSUfind(vector<ll>a,ll x,ll y)
{
    if(root(a,x)==root(a,y))
    {
        return true;
    }
    return false;
}
void DSUunion(vector<ll>&a,vector<ll>&size, ll x,ll y)
{
    x=root(a,x);
    y=root(a,y);
    if(x==y)
    {
        return;
    }
    if(size[x]<size[y]) swap(x,y);
    a[y]=x;
    size[x]+=size[y];
}
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
bool isPrime(int n) 
{
    if (n <= 1)  return false; 
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
          return false;
    return true; 
}
ll power(ll x,ll y,ll p)
{
    ll ans=1;
    x = x%p;
    if(x==0) return 0;
    while(y)
    {
        if(y&1) ans=(ans*x)%p;
        y>>=1;
        x=(x*x)%p;
    }
    return ans;
}
ll bfs(ll start,vector<bool>&visited, vector<vector<ll> >&graph,vector<ll>&a)
{
    visited[start]=true;
    queue<ll>q;
    ll ans=a[start];
    q.push(start);
    while(!q.empty())
    {
        ll k=q.front();
        q.pop();
        FOR(i,0,graph[k].size())
        {
            if(!visited[graph[k][i]])
            {
                visited[graph[k][i]]=true;
                q.push(graph[k][i]);
                if(a[graph[k][i]]<ans)
                {
                    ans=a[graph[k][i]];
                }
            }
        }
    }
    return ans;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<ll> >graph(n+1,vector<ll>());
    vector<ll>a(n+1,0);
    FOR(i,1,n+1)
    {
        // cout<<"&";
        cin>>a[i];
    }
    FOR(i,0,m)
    {
        // cout<<"*";
        ll u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
        // cout<<"*\n";
    }
    // cout<<"&";
    ll ans=0;
    vector<bool>visited(n+1,false);
    // cout<<"&";
    FOR(i,1,n+1)
    {
        // cout<<"(";
        if(!visited[i])
            ans+=bfs(i,visited,graph,a);
    }
    cout<<ans<<"\n";
    return 0;
}