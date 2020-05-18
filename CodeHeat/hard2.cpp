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
ll merge(vector<ll>&v,vector<ll>&temp,ll left, ll mid, ll right)
{
    ll i=left,j=mid,k=left;
    ll inv=0;
    while((i<=mid-1) and j<=right)
    {
        if(v[i]<=v[j])
        {
            temp[k++]=v[i++];
        }
        else{
            temp[k++]=v[j++];
            inv=inv+(mid-i);
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
    for(i=left;i<=right;i++)
    {
        v[i]=temp[i];
    }
    return inv;
}
ll mergeSort(vector<ll>&v,vector<ll>&temp,ll left,ll right)
{
    ll inv=0;
    if(right>left)
    {
        ll mid=(left+right)/2;
        inv+=mergeSort(v,temp,left,mid);
        inv+=mergeSort(v,temp,mid+1,right);
        inv+=merge(v,temp,left,mid+1,right);
    }
    return inv;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll>v(n);
    FOR(i,0,n)
    {
        cin>>v[i];
    }
    vector<ll>temp(n,0);
    cout<<mergeSort(v,temp,0,n-1)<<"\n";
    return 0;
}