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
int arr[10][10][10][10][10][10];
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
ll maxKnow(vector<ll>e,vector<ll>m,vector<ll>h,vector<ll>coin,ll fe,ll le,ll fm,ll lm,ll fh,ll lh,ll c)
{
    if(c==coin.size() or le<0 or fe>=e.size() or fm>=m.size() or lm<0 or lh<0 or fh>=h.size())
    {
        return 0;
    }
    if(arr[fe][le][fm][lm][fh][lh]!=0)
    {
        return arr[fe][le][fm][lm][fh][lh];
    }
    ll ef=0,el=0;
    ll ma=0;
    ll mo=0;
    if(fe+1<=le)
    {
        ef=maxKnow(e,m,h,coin,fe+1,le,fm,lm,fh,lh,c+1);
        if(ef+coin[c]*e[fe]>ma)
        {
            ma=ef+coin[c]*e[fe];
            mo=1;
        }
    }
    if(fe==le or fe<le)
    {
        el=maxKnow(e,m,h,coin,fe,le-1,fm,lm,fh,lh,c+1);
        if(el+coin[c]*e[le]>ma)
        {
            ma=el+coin[c]*e[le];
        }
    }
    ll mf=0,ml=0,hf=0,hl=0;
    if(fm+1<=lm)
    {
        mf=maxKnow(e,m,h,coin,fe,le,fm+1,lm,fh,lh,c+1);
        if(mf+coin[c]*m[fm]>ma)
        {
            ma=mf+coin[c]*m[fm];
            mo=3;
        }
    }
    if(fm==lm or fm<lm)
    {
        ml=maxKnow(e,m,h,coin,fe,le,fm,lm-1,fh,lh,c+1);
        if(ml+coin[c]*m[lm]>ma)
        {
            ma=ml+coin[c]*m[lm];
            mo=4;
        }    
    }
    if(fh+1<=lh)
    {
        hf=maxKnow(e,m,h,coin,fe,le,fm,lm,fh+1,lh,c+1);
        if(hf+coin[c]*h[fh]>ma)
        {
            ma=hf+coin[c]*h[fh];
            mo=5;
        }
    }
    if(fh==lh or fh<lh)
    {
        hl=maxKnow(e,m,h,coin,fe,le,fm,lm,fh,lh-1,c+1);
        if(hl+coin[c]*h[lh]>ma)
        {
            ma=hl+coin[c]*h[lh];
        }
    }
    arr[fe][le][fm][lm][fh][lh]=ma;
    return ma;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    FOR(i,0,10)
    {
        FOR(j,0,10)
        {
            FOR(k,0,10)
            {
                FOR(l,0,10)
                {
                    FOR(m,0,10)
                    {
                        FOR(n,0,10)
                        {
                            arr[i][j][k][l][m][n]=0;
                        }
                    }
                }
            }
        }
    }
    ll en,mn,hn;
    cin>>en>>mn>>hn;
    vector<ll>e(en,0);
    FOR(i,0,en)
    {
        cin>>e[i];
    }
    vector<ll>m(mn,0);
    FOR(i,0,mn)
    {
        cin>>m[i];
    }
    vector<ll>h(hn,0);
    FOR(i,0,hn)
    {
        cin>>h[i];
    }
    ll n=en+mn+hn;
    vector<ll>coin(n,0);
    FOR(i,0,n)
    {
        cin>>coin[i];
    }
    cout<<maxKnow(e,m,h,coin,0,e.size()-1,0,m.size()-1,0,h.size()-1,0)<<"\n";
    
    return 0;
}