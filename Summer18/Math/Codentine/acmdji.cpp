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
    ll n, e;
    cin>>n>>e;
    vector<pair <ll, double> > graph[n];
    ll i, j, e1, e2;
    double w;
    FOR(i,0,e)
    {
        cin>>e1>>e2>>w;
        graph[e1].push_back(make_pair(e2, w));
        graph[e2].push_back(make_pair(e1, w));
    }
    bool visited[n];
    vector<double> distance(n);
    FOR(i,0,n)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    ll start, end;
    cin>>start>>end;
    distance[start] = 1;
    FOR(j,0,n-1)
    {
        double min = INT_MAX;
        ll index;
        FOR(i,0,n)
        {
            if ((visited[i] == false) && (distance[i] < min))
            {
                min = distance[i];
                index = i;
            }
        }
        visited[index] = true;
        FOR(i,0,graph[index].size())
        {
            pair<ll, double> currindex = graph[index][i];
            if (!visited[currindex.first] && distance[index] != INT_MAX && distance[index] * currindex.second <= distance[currindex.first])
            {
                distance[currindex.first] = distance[index] * currindex.second;
            }
        }
    }
    if(distance[end] == INT_MAX)
        cout<<-1<<"\n";
    else
        cout << distance[end] << "\n";
    return 0;
}