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
long long int merge(vector<ll>&v, vector<ll>&temp, ll left, ll mid, ll right)
{
    long long int ic=0;
    int i=left, j=mid, k=left;
    while(i<=mid-1 and j<=right)
    {
        if(v[i]<=v[j])
        {
            temp[k++]=v[i++];
        }
        else
        {
            temp[k++]=v[j++];
            ic+=(mid-i);
        }
    }
    while(i<=mid-1)
    {
        temp[k++]=v[i++];
    }
    while(j<=right)
    {
        temp[k++]=v[j++];
    }
    for(int i=left;i<=right;i++)
    {
        v[i]=temp[i];
    }
    return ic;
}
long long int inversionCount(vector<ll>&v, ll left, ll right, vector<ll>&temp)
{
    int mid;long long int ic=0;
    if(right>left)
    {
        mid = (right+left)>>1;
        ic+=(inversionCount(v,left,mid,temp));
        ic+=(inversionCount(v,mid+1,right,temp));
        ic+=merge(v,temp,left,mid+1,right); 
    }
    return ic;
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
        vector<ll>v(n,0);
        FOR(i,0,n)
        {
            cin>>v[i];
        }
        vector<ll>temp(n,0);
        cout<<inversionCount(v,0,n-1,temp)<<"\n";
    }
    return 0;
}