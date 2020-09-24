#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_set>
#include<stack>
#include<queue>
#include<unordered_map>
#include<limits>
#include<climits>
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
bool comp(pair<ll,ll>a,pair<ll,ll>b)
{
    if(a.first>b.first)
    {
        return true;
    }
    else if(a.first==b.first)
    {
        return a.second>b.second;
    }
    else
    {
        return a.first>b.first;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<pair<ll,ll> >ratRank(n,make_pair(0,INT_MAX));
        FOR(i,0,n)
        {
            cin>>ratRank[i].first;
            ratRank[i].second=i;
        }
        vector<vector<ll> >v(n,vector<ll>(m,0));
        FOR(i,0,n)
        {
            FOR(j,0,m)
            {
                cin>>v[i][j];
            }
        }
        vector<pair<ll,ll> >bestRank(n,make_pair(INT_MAX,INT_MAX));
        vector<pair<ll,ll> >bestRat(n,make_pair(INT_MIN,INT_MIN));
        FOR(i,0,m)
        {
            FOR(j,0,n)
            {
                ratRank[j].first+=v[ratRank[j].second][i];
            }
            sort(ratRank.begin(),ratRank.end(),comp);
            // FOR(j,0,n)
            // {
            //     cout<<ratRank[j].first<<" "<<ratRank[j].second<<"\n";
            // }
            // cout<<"((\n";
            ll cur=0;
            ll curScore=INT_MAX;
            ll x=1;
            FOR(j,0,n)
            {
                if(ratRank[j].first<curScore)
                {
                    curScore=ratRank[j].first;
                    cur+=x;
                    x=1;
                }
                else
                {
                    x+=1;
                }
                if(bestRank[ratRank[j].second].first>cur)
                {
                    bestRank[ratRank[j].second].first=cur;
                    bestRank[ratRank[j].second].second=i;
                }
                if(bestRat[ratRank[j].second].first<curScore)
                {
                    bestRat[ratRank[j].second].first=curScore;
                    bestRat[ratRank[j].second].second=i;
                }
            }
            // FOR(j,0,n)
            // {
            //     cout<<bestRank[j].first<<" "<<bestRank[j].second<<"\n";
            // }
            // cout<<"&&\n";
            // FOR(j,0,n)
            // {
            //     cout<<bestRat[j].first<<" "<<bestRat[j].second<<"\n";
            // }
            // cout<<"^^\n";
        }
        ll count=0;
        FOR(i,0,n)
        {
            
            if(bestRank[i].second!=bestRat[i].second)
            {
                count+=1;
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}