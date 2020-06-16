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
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        vector<ll>v(n,0);
        vector<ll>nds(n,0);
        ll lans=-1;
        FOR(i,0,n)
        {
            cin>>v[i];
        }
        nds[0]=v[0]%x;
        if(nds[0]%x!=0)
            lans=0;
        FOR(i,1,n)
        {
            if(v[i]%x!=0)
            {
                nds[i]=nds[i-1]+v[i];
            }
            else
            {
                nds[i]=nds[i-1];
            }
            if(nds[i]%x!=0)
            {
                lans=i;
            }
        }
        vector<ll>nrs(n,0);
        nrs[n-1]=v[n-1]%x;
        ll rans=-1;
        if(nrs[n-1]%x!=0)
        {
            rans=n-1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(v[i]%x!=0)
            {
                nrs[i]=nrs[i+1]+v[i];
            }
            else
            {
                nrs[i]=nrs[i+1];
            }
            if(nrs[i]%x!=0)
            {
                rans=i;
            }
        }
        // FOR(i,0,n)
        // {
        //     cout<<nds[i]<<" ";
        // }
        // cout<<"\n";
        // FOR(i,0,n)
        // {
        //     cout<<nrs[i]<<" ";
        // }
        // cout<<"\n";
        //  cout<<lans<<" "<<rans<<"\n";
        if(lans==-1 and rans==-1)
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<max(lans+1,n-rans)<<"\n";
        }
    }
    return 0;
}