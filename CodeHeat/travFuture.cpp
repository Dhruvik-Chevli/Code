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
        ll n;
        cin>>n;
        //ll ma=-INT_MAX;
        //mi=0;
        vector<ll>v(n,0);
        vector<pair<ll,ll> >ma(n);
        vector<ll>sum(n+1,0);
        FOR(i,0,n)
        {
            cin>>v[i];
            sum[i+1]=sum[i]+v[i];
            ma[i].first=v[i];
            ma[i].second=i;
        }
        sort(ma.rbegin(),ma.rend());
        ll ans=0;
        ll cur=0;
        // FOR(i,0,n+1)
        // {
        //     cout<<sum[i]<<" ";
        // }
        // cout<<endl;
        cur=0;
        FOR(i,0,n)
        {
            if(ma[i].second>cur)
            {
                ans+=(ma[i].first*(ma[i].second-cur));
                ans-=(sum[ma[i].second]-sum[cur]);
                cur=ma[i].second+1;
            }
            else if(cur==ma[i].second)
            {
                cur+=1;
            }
            else
            {
                continue;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}