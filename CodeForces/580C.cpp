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
ll counts=0;
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
void dfs(vector<ll >*graph,vector<bool>&visited,ll start,ll cons,ll m,vector<ll> &cats)
{
    //cout<<start+1<<endl;
    visited[start]=true;
    if(cats[start]==1)
    {
        cons+=1;
    }
    else
    {
        cons=0;
    }
    if(cons>m)
    {
        return;
    }
    int flag=1;
    FOR(i,0,graph[start].size())
    {
        if(!(visited[graph[start][i]]))
        {
            flag=0;
            dfs(graph,visited,graph[start][i],cons,m,cats);
        }
    }
    if(flag)
        counts+=1;
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
    vector<ll>cats(n,0);
    FOR(i,0,n)
    {
        ll k;
        cin>>k;
        if(k)
        {
            cats[i]=1;
        }
    }
    vector<ll>graph[n];
    FOR(i,0,n-1)
    {
        ll u,v;
        cin>>u>>v;
        graph[u-1].pb(v-1);
        graph[v-1].pb(u-1);
    }
    vector<bool>visited(n,false);
    dfs(graph,visited,0,0,m,cats);
    cout<<counts<<endl;
    return 0;
}