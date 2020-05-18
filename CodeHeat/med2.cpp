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
ll power(ll x, ll y) 
{ 
    ll res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = res*x; 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = x*x;  // Change x to x^2 
    } 
    return res; 
}
ll gcd(ll m,ll n)
{
    if(n==0)
    {
        return m;
    }
    return gcd(n,m%n);
}
ll findlcm(vector<ll> arr, ll n) 
{ 
    // Initialize result 
    ll ans = arr[0]; 
  
    // ans contains LCM of arr[0], ..arr[i] 
    // after i'th iteration, 
    FOR(i,1,n)
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
    return ans; 
} 
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll>coins(n);
    FOR(i,0,n)
    {
        cin>>coins[i];
    }
    vector<vector<ll> >powerSet;
    FOR(i,0,power(2,n))
    {
        vector<ll>v;
        ll k=i;
        ll c=0;
        while(k)
        {
            if(k&1)
            {
                v.pb(coins[c]);
            }
            c+=1;
            k>>=1;
        }
        powerSet.pb(v);
    }
    // FOR(i,0,powerSet.size())
    // {
        // FOR(j,0,powerSet[i].size())
        // {
        //     cout<<powerSet[i][j]<<" ";
        // }
        // cout<<endl;
    // }
    vector<pair<ll,ll> >inc;
    FOR(i,0,powerSet.size())
    {
        if(powerSet[i].size()>0)
        {
            ll u=findlcm(powerSet[i],powerSet[i].size());
            inc.pb(make_pair(u,powerSet[i].size()));
        }
    }
    ll ans=0;
    ll v;
    cin>>v;
    while(v--)
    {
        ans=0;
        ll a,b;
        cin>>a>>b;
        FOR(i,0,inc.size())
        {
            ll n=inc[i].second;
            if(n%2)
            {
                //ll u=findlcm(powerSet[i],n);
                // cout<<u<<"\n";
                ll u=inc[i].first;
                ans+=((b/u)-((a-1)/u));
            }
            else
            {
                //ll u=findlcm(powerSet[i],n);
                // cout<<u<<"\n";
                ll u=inc[i].first;
                ans-=((b/u)-(a-1)/u);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}