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
int main()
{
    std::ios_base::sync_with_stdio(true);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll>v(n+1,0);
    FOR(i,1,n+1)
    {
        cin>>v[i];
    }
    vector<ll>vs=v;
    sort(vs.begin(),vs.end());
    vector<ll>v1(n+1,0);
    vector<ll>v2(n+1,0);
    v1[1]=v[1];
    v2[1]=vs[1];
    
    FOR(i,2,n+1)
    {
        v1[i]=v1[i-1]+v[i];
        v2[i]=v2[i-1]+vs[i];
    }
    ll m;
    // FOR(i,0,n+1)
    // {
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    // FOR(i,0,n+1)
    // {
    //     cout<<vs[i]<<" ";
    // }
    // cout<<endl;
    // FOR(i,0,n+1)
    // {
    //     cout<<v1[i]<<" ";
    // }
    // cout<<endl;
    // FOR(i,0,n+1)
    // {
    //     cout<<v2[i]<<" ";
    // }
    // cout<<endl;
    cin>>m;

    FOR(i,0,m)
    {
        ll q,l,r;
        cin>>q>>l>>r;
        if(q==1)
        {
            cout<<v1[r]-v1[l-1]<<"\n";
        }
        else
        {
            cout<<v2[r]-v2[l-1]<<"\n";
        }
    }
    return 0;
}