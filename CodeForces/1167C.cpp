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
        (!(visited[graph[start][i]]))
        {
            dfs(graph,visited,graph[start][i]);
        }
    }
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<ll>dsu(n,-1);
    vector<ll>size(n,-1);
    DSUinit(dsu,size,n);
    FOR(i,0,m)
    {
        ll k;
        cin>>k;
        ll lst=-1;
        FOR(j,0,k)
        {
            ll x;
            cin>>x;
            x--;
            if(lst!=-1)
            {
                DSUunion(dsu,size,x,lst);
            }
            // FOR(i,0,n)
            // {
            //     cout<<dsu[i]<<" ";
            // }
            // cout<<endl;
            // FOR(i,0,n)
            // {
            //     cout<<size[i]<<" ";
            // }
            // cout<<endl;
            lst=x;
        }
    }
    FOR(i,0,n)
    {
        cout<<size[root(dsu,i)]<<" ";
    }
    cout<<endl;
    return 0;
}