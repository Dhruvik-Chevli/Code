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
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,sx,sy;
    cin>>n>>sx>>sy;
    ll uy=0, ly=0, lx=0,rx=0;
    FOR(i,0,n)
    {
        ll a,b;
        cin>>a>>b;
        if(a<sx)
        {
            lx+=1;
        }
        else if(a>sx)
        {
            rx+=1;
        }
        if(b<sy)
        {
            ly+=1;
        }
        else if(b>sy)
        {
            uy+=1;
        }
    }
    ll ma=max(lx,max(rx,max(uy,ly)));
    cout<<ma<<"\n";
    if(ma==lx)
    {
        cout<<sx-1<<" "<<sy<<"\n";
    }
    else if(ma==rx)
    {
        cout<<sx+1<<" "<<sy<<"\n";
    }
    else if(ma==uy)
    {
        cout<<sx<<" "<<sy+1<<"\n";
    }
    else if(ma==ly)
    {
        cout<<sx<<" "<<sy-1<<"\n";
    }
    return 0;
}