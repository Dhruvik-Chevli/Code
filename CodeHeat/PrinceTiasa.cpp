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
ll gcd(ll m,ll n)
{
    if(n==0)
    {
        return m;
    }
    return gcd(n,m%n);
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //vector<vector<ll> >&
    ll g;
    cin>>g;
    vector<ll>coins(g,0);
    FOR(i,0,g)
    {
        cin>>coins[i];
    }
    sort(coins.begin(),coins.end());
    vector<bool>coin(55,false);
    FOR(i,0,g)
    {
        bool flag=true;
        for(int j=2;j<coins[i];j++)
        {
            if(coins[i]%j==0 and coin[j]==true)
            {
                flag=false;
                break;
            }
        }
        if(flag)
            coin[coins[i]]=true;
    }
    // FOR(i,0,55)
    // {
    //     cout<<coin[i]<<" ";
    // }
    // cout<<"\n";
    ll v;
    cin>>v;
    FOR(i,0,v)
    {
        ll a,b;
        cin>>a>>b;
        ll ans=0;
        FOR(j,0,55)
        {
            if(coin[j]==false)
            {
                continue;
            }
            if(a%j==0)
            {
                ans+=((b/j)-(a/j)+1);
            }
            else
            {
                ans+=((b/j)-(a/j));
            }
            FOR(k,1,j)
            {
                if(coin[k]==false)
                    continue;
                ll u=gcd(k,j);
                u=(k*j)/u;
                if(a%u==0)
                {
                    ans-=((b/u)-(a/u)+1);
                }
                else
                {
                    ans-=((b/u)-(a/u));
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}