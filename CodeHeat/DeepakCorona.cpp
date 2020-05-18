#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_set>
#include<stack>
#include<queue>
#include<unordered_map>
//#include<priority_queue>
#include<functional>
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
void dfs(vector<vector<ll> >&graph,vector<bool>&visited,ll start,priority_queue<ll,vector<ll>,greater<ll> > &pq)
{
    visited[start]=true;
    cout<<start+1<<" ";
    FOR(i,0,graph[start].size())
    {
        if(!(visited[graph[start][i]]))
        {
            pq.push(graph[start][i]);
            visited[graph[start][i]]=true;
        }
    }
    if(!pq.empty())
    {
        ll top=pq.top();
        pq.pop();
        dfs(graph,visited,top,pq);
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
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<ll> >graph(n,vector<ll>());
    FOR(i,0,m)
    {
        ll u,v;
        cin>>u>>v;
        graph[u-1].pb(v-1);
        graph[v-1].pb(u-1);
    }
    vector<bool>visited(n,false);
    vector<ll>ans;
    priority_queue<ll,vector<ll>,greater<ll> >pq;
    dfs(graph,visited,0,pq);
    return 0;
}