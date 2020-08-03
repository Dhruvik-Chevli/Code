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
// void dfs(vector<vector<ll> >&graph,vector<bool>&visited,ll start)
// {
//     visited[start]=true;
//     FOR(i,0,graph[start].size())
//     {
//         if(!(visited[graph[start][i]]))
//         {
//             dfs(graph,visited,graph[start][i]);
//         }
//     }
//     return;
// }
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
void dfs(vector<vector<ll> >&graph,vector<bool>&visited,ll start)
{
    cout<<start<<" ";
    visited[start] = true;
    FOR(i,0,graph[start].size())
    {
        if(!visited[graph[start][i]])
        {
            dfs(graph,visited,graph[start][i]);
        }
    }
    return;
}
void bfs(vector<int>graph[], vector<bool>&visited, vector<int>&ans,int start)
{
    ans.push_back(start);
    visited[start]=true;
    queue<int>q;
    q.push(start);
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        for(int i=0;i<graph[k].size();i++)
        {
            if(!visited[graph[k][i]])
            {
                visited[graph[k][i]]=true;
                q.push(graph[k][i]);
                ans.push_back(graph[k][i]);
            }
        }
    }
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,e;
        cin>>n>>e;
        vector<int>graph[n];
        FOR(i,0,e)
        {
            int u,v;
            cin>>u>>v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        // FOR(i,0,n)
        // {
        //     FOR(j,0,graph[i].size())
        //     {
        //         cout<<graph[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        vector<bool>visited(n,false);
        vector<int>ans;
        FOR(i,0,n)
        {
            if(!visited[i])
            {
                bfs(graph,visited,ans,i);
            }
        }
        FOR(i,0,ans.size())
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}