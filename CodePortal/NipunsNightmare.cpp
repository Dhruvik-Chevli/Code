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
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,l,r;
        cin>>n>>l>>r;
        ll r0=1;
        ll r1=0;
        ll r2=0;
        //ll r3=(r-l)/3;
        //ll r3=r2=r1=(r-l+1)/3;
        while(l%3!=0)
        {
            if(l%3==1)
            {
                r1+=1;
            }
            else
            {
                r2+=1;
            }
            l++;
        }
        while(r%3!=0)
        {
            if(r%3==1)
            {
                r1+=1;
            }
            if(r%3==2)
            {
                r2+=1;
            }
            r--;
        }
        ll k=(r-l)/3;
        r0+=k; r1+=k; r2+=k; 
        ll dp[n+1][3];
        dp[0][0]=r0%MOD;
        dp[0][1]=r1%MOD;
        dp[0][2]=r2%MOD;
        FOR(i,1,n)
        {
            dp[i][0]=(((dp[i-1][0]*r0)%MOD+(dp[i-1][1]*r2)%MOD)%MOD+(dp[i-1][2]*r1)%MOD)%MOD;
            dp[i][1]=(((dp[i-1][0]*r1)%MOD+(dp[i-1][1]*r0)%MOD)%MOD+(dp[i-1][2]*r2)%MOD)%MOD;
            dp[i][2]=(((dp[i-1][0]*r2)%MOD+(dp[i-1][1]*r1)%MOD)%MOD+(dp[i-1][2]*r0)%MOD)%MOD;
        }
        cout<<dp[n-1][0]<<endl;
    }
    return 0;
}