#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_set>
#include<stack>
#include<queue>
#include<climits>
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
vector<ll> getPathDfs(vector<vector<ll> >&graph,ll n,ll start,ll end, vector<bool>&visited,vector<ll>&val)
{
    if(start==end)
    {
        vector<ll>v;
        v.pb(val[start]);

        return v;
    }
    visited[start]=true;
    FOR(i,0,graph[start].size())
    {
        if(!visited[graph[start][i]])
        {
            visited[graph[start][i]]=true;
            vector<ll> ans=getPathDfs(graph,n,graph[start][i],end,visited,val);
            if(ans.size()!=0)
            {
                ans.pb(val[start]);
                return ans;
            }
            else
            {
                visited[i]=false;
            }
        }
    }
    visited[start]=false;
    vector<ll>v;
    return v;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        vector<vector<ll> >graph(n,vector<ll>());
        vector<ll>val(n,0);
        FOR(i,0,n)
        {
            cin>>val[i];
        }
        FOR(i,0,n-1)
        {
            ll u,v;
            cin>>u>>v;
            graph[u-1].pb(v-1);
            graph[v-1].pb(u-1);
        }
        FOR(i,0,q)
        {
            ll a,b;
            cin>>a>>b;
            a--;b--;
            vector<bool>visited(n,false);
            vector<ll>ans=getPathDfs(graph,n,a,b,visited,val);
            sort(ans.begin(),ans.end());
            // FOR(i,0,ans.size())
            // {
            //     cout<<ans[i]<<" ";
            // }
            ll mi=INT_MAX;
            FOR(i,1,ans.size())
            {
                if(ans[i]-ans[i-1]<mi)
                {
                    mi=ans[i]-ans[i-1];
                }
            }
            cout<<mi<<"\n";
        }
    }
    return 0;
}