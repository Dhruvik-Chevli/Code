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
string acm="ACMMANIPAL";
int dx[8]={0,1,0,-1,-1,1,1,-1};
int dy[8]={1,0,-1,0,-1,-1,1,1};
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
// dfs(v,visited,1,10,i,j)

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
bool dfs(vector<string>&v,vector<vector<bool> >visited,ll cur,ll tot,ll si, ll sj,ll n,ll m)
{
    if(cur==tot)
    {
        return true;
    }
    visited[si][sj]=true;
    // cout<<v[si][sj]<<" "<<cur<<" "<<acm[cur]<<" "<<si<<" "<<sj<< "\n";
    FOR(i,0,8)
    {
        ll x=si+dx[i];
        ll y=sj+dy[i];
        // cout<<dx[i]<<" "<<dy[i]<<" "<<si<<" "<<sj<<" "<<x<<" "<<y<<" "<<v[x][y]<<" ";
        if(x<n and x>=0 and y<m and y>=0 and !visited[x][y] and v[x][y]==acm[cur]) 
        {
            if(dfs(v,visited,cur+1,tot,x,y,n,m))
            {
                return true;
            } 
        }
    }
    return false;
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
        vector<string>v(n,"");
        FOR(i,0,n)
        {
            cin>>v[i];
        }
        bool flag=false;
        FOR(i,0,n)
        {
            FOR(j,0,m)
            {
                if(v[i][j]=='A')
                {
                    vector<vector<bool> >visited(n,vector<bool>(m,false));
                    // cout<<i<<j<<"\n";
                    if(dfs(v,visited,1,10,i,j,n,m))
                    { 
                        cout<<"YES\n";
                        flag=true;
                        break;
                    }
                }
            }
            if(flag)
            {
                break;
            }
        }
        if(!flag)
        {
            cout<<"NO\n";
        }
    }
    return 0;
}