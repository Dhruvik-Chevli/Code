#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_set>
#include<stack>
#include<limits.h>
#include<queue>
#include<unordered_map>
using namespace std;
#include<map>
#include<set>
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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>a(n,0);
        vector<ll>b(n,0);
        map<ll,ll>ma;
        map<ll,ll>mb;
        set<ll>as;
        set<ll>bs;
        ll mi=INT_MAX;
        FOR(i,0,n)
        {
            cin>>a[i];
            ma[a[i]]+=1;
            as.insert(a[i]);
            if(a[i]<mi)
            {
                mi=a[i];
            }
        }
        FOR(i,0,n)
        {
            cin>>b[i];
            mb[b[i]]+=1;
            bs.insert(b[i]);
            if(b[i]<mi)
            {
                mi=b[i];
            }
        }
        ll ca=0;
        ll cb=0;
        bool flag=true;
        priority_queue<ll,vector<ll>,greater<ll> >ha;
        priority_queue<ll>hb;
        for(auto x: as)
        {
            if(bs.count(x)>0)
            {
                ll k=ma[x]-mb[x];
                if(k<0)
                {
                    continue;
                }
                else if(k==0)
                {
                    continue;
                }
                else
                {
                    if(k%2==1)
                    {
                        // cout<<"%"<<x<<"\n";
                        flag=false;
                        break;
                    }
                    else
                    {
                        FOR(i,0,k/2)
                        {
                            ha.push(x);
                        }
                    }
                }
            }
            else
            {
                ll k=ma[x];
                if(k%2==1)
                {
                    // cout<<"$"<<x<<"\n";
                    flag=false;
                    break;
                }
                else
                {
                    FOR(i,0,k/2)
                    {
                        ha.push(x);
                    }
                }
            }
        }
        for(auto x: bs)
        {
            if(as.count(x)>0)
            {
                ll k=mb[x]-ma[x];
                if(k<0)
                {
                    continue;
                }
                else if(k==0)
                {
                    continue;
                }
                else
                {
                    if(k%2==1)
                    {
                        // cout<<"^"<<x<<"\n";
                        flag=false;
                        break;
                    }
                    else
                    {
                        FOR(i,0,k/2)
                        {
                            hb.push(x);
                        }
                    }
                }
            }
            else
            {
                ll k=mb[x];
                if(k%2)
                {
                    // cout<<"#"<<x<<"\n";
                    flag=false;
                    break;
                }
                else
                {
                    FOR(i,0,k/2)
                    {
                        hb.push(x);
                    }
                }
            }
        }
        ll ans=0;
        if(ha.size()!=hb.size())
        {
            // cout<<"*"<<"\n";
            flag=false;
        }
        else
        {
            while(ha.size()!=0 and hb.size()!=0)
            {
                ans+=min(2*mi,min(ha.top(),hb.top()));
                ha.pop();
                hb.pop();
            }
        }
        if(flag)
            cout<<ans<<"\n";
        else
        {
            cout<<"-1\n";
        }
        
    }
    return 0;
}