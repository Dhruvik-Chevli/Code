#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_set>
#include<stack>
#include<queue>
#include<unordered_map>
#include<cstring>
#include<limits>
#include<climits>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
int* cnt=new int[300005];
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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll c0=0;
        ll om=0;
        ll em=0;
        ll ma=INT_MIN;
        ll sma=INT_MIN;
        memset(cnt,0,300005);
        FOR(i,0,n)
        {
            ll k;
            cin>>k;
            if(k==1)
            {
                if(c0>0)
                {
                    if(c0%2)
                    {
                        if(c0>om)
                        {
                            om=c0;
                        }
                    }
                    else
                    {
                        if(c0>em)
                        {
                            
                            em=c0;
                        }
                    }
                    cnt[c0]+=1;
                    if(ma==INT_MIN and sma==INT_MIN)
                    {
                        ma=c0;
                    }
                    else
                    {
                        if(c0>=ma)
                        {
                            sma=ma;
                            ma=c0;
                        }
                        else if(c0>sma)
                        {
                            sma=c0;
                        }
                    }
                }
                c0=0;
            }
            else
            {
                c0+=1;
            }
        }
        if(c0==n)
        {
            if(c0%2)
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
            continue;
        }
        if(ma%2==0)
        {
            cout<<"No\n";
        }
        else{
            if(ma/2+1>sma)
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
            
        }
        // if(om/2+1>em and cnt[om]==1)
        // {
        //     cout<<"Yes\n";
        // }
        // FOR(i,om/2+1,om)
        // {
        //     if(cnt[i]>0)
        //     {
        //         cout<<"Yes\n";
        //     }
        //     else
        //     {
        //         cout<<"No\n";
        //     }
            
        // }
    }
    return 0;
}