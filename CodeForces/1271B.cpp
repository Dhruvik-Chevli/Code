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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll ans=0;
    vector<ll>b;
    vector<ll>w;
    bool needb = false;
    ll countb=0;
    FOR(i,0,n)
    {
        if(s[i]=='B' and needb)
        {
            b.pb(i-1);
            needb=false;
            countb++;
        }
        else if(s[i]=='B' and !needb)
        {
            needb=true;
        }
        else{
            if(needb)
            {
                countb++;
                b.pb(i-1);
            }
        }
        if(countb>2*n)
        {
            break;
        }
    }
    bool needw = false;
    ll countw=0;
    FOR(i,0,n)
    {
        if(s[i]=='W' and needw)
        {
            w.pb(i-1);
            needw=false;
            countw++;
        }
        else if(s[i]=='W' and !needw)
        {
            needw=true;
        }
        else{
            if(needw)
            {
                countw++;
                w.pb(i-1);
            }
        }
        if(countw>2*n)
        {
            break;
        }
    }
    if(countb<=3*n and !needb)
    {
        cout<<countb<<"\n";
        FOR(i,0,countb)
        {
            cout<<b[i]+1<<" ";
        }
        if(countb!=0) cout<<"\n";
    }
    else if(countw<=3*n and !needw)
    {
        cout<<countw<<"\n";
        FOR(i,0,countw)
        {
            cout<<w[i]+1<<" ";
        }
        if(countw!=0) cout<<"\n";
    }
    else
    {
        cout<<"-1\n";
    }
    return 0;
}