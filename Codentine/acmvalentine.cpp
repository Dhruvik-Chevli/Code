#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_set>
#include<stack>
#include<queue>
#include<limits.h>
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
ll calculate(ll n, ll m,vector<ll>g,vector<ll>b)
{
    ll last=0;
    ll ans=0;
    ll left=n;
    bool flag=true;
    FOR(j,0,n)
    {
        ll diff=INT_MAX;
        ll ind;
        FOR(i,last,m)
        {
            if(diff>abs(b[i]-g[j]))
            {
                ind=i;
                diff=abs(b[i]-g[j]);
            }
        }
        if(diff==INT_MAX)
        {
            flag=false;
            break;
        }
        // cout<<diff<<"\n";
        ans+=diff;
        if(m-ind-1==left-1)
        {
            break;
        }
        left-=1;
        last=ind+1;
    }
    int i=0;
    while(left)
    {
        ans+=abs(b[m-1-i]-g[n-1-i]);
        left-=1;
        i+=1;
    }
    return ans;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<ll>g(n,0);
    vector<ll>b(m,0);
    FOR(i,0,n)
    {
        cin>>g[i];
    }
    FOR(i,0,m)
    {
        cin>>b[i];
    }
    sort(g.begin(),g.end());
    sort(b.begin(),b.end());
    ll last=0;
    ll ans=0;
    ll left=n;
    bool flag=true;
    FOR(j,0,n)
    {
        ll diff=INT_MAX;
        ll ind;
        FOR(i,last,m)
        {
            if(diff>abs(b[i]-g[j]))
            {
                ind=i;
                diff=abs(b[i]-g[j]);
            }
        }
        if(diff==INT_MAX)
        {
            flag=false;
            break;
        }
        // cout<<diff<<"\n";
        ans+=diff;
        if(m-ind-1==left-1)
        {
            break;
        }
        left-=1;
        last=ind+1;
    }
    int i=0;
    while(left)
    {
        ans+=abs(b[m-1-i]-g[n-1-i]);
        left-=1;
        i+=1;
    }
    cout<<ans<<"\n";
    return 0;
}