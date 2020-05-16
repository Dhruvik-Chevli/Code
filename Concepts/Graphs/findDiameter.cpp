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
pair<ll,ll> bfs(vector<vector<ll> >graph,ll start,ll n)
{
    vector<bool>visited(n,false);
    vector<ll>distance(n,-1);
    queue<ll>q;
    q.push(start);
    distance[start]=0;
    while(!q.empty())
    {
        ll k=q.front(); q.pop();
        FOR(i,0,graph[k].size())
        {
            if(!(visited[graph[k][i]]))
            {
                distance[graph[k][i]]=distance[k]+1;
                visited[graph[k][i]]=true;
                q.push(graph[k][i]);
            }
        }
    }
    int mi;
    int ma=-1000000;
    FOR(i,0,n)
    {
        if(distance[i]>ma)
        {
            mi=i;
            ma=distance[i];
        }
    }
    return make_pair(mi,ma);
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}