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
void merge(pair<int,int>&node,pair<int,int>&lc,pair<int,int>&rc)
{
    if (lc.first>=rc.first)
    {
        node.first = lc.first;
        if(lc.second>=rc.first)
        {
            node.second = lc.second;
        }
        else
        {
            node.second = rc.first;
        }
    }
    else
    {
        node.first = rc.first;
        if(rc.second>=lc.first)
        {
            node.second=rc.second;
        }
        else
        {
            node.second=lc.first;
        }
    }
}
void buildTree(vector<int>&v, vector<pair<int,int> >&tree, int start, int end, int treeNode)
{
    if(start==end)
    {
        tree[treeNode].first=v[start];
        return;
    }
    int mid=(start+end)/2;
    buildTree(v,tree,start,mid,2*treeNode);
    buildTree(v,tree,mid+1,end,2*treeNode+1);
    merge(tree[treeNode],tree[2*treeNode],tree[2*treeNode+1]);
}
void update(vector<int>&v, vector<pair<int,int> >&tree, int start, int end, int treeNode, int idx, int value)
{
    if(start==end)
    {
        v[idx]=val;
        tree[treeNode].first = val;
        return;
    }
    int mid = (start+end)/2;
    if(idx>mid)
    {
        update(v,tree,mid+1,end,2*treeNode+1,idx,val);
    }
    else{
        update(v,tree,start,mid,2*treeNode,idx,val);
    }
    merge(tree[treeNode], tree[2*treeNode], tree[2*treeNode+1]);
}
pair<int,int> query(vector<pair<int,int> >&tree,int start, int end, int treeNode,int l, int r)
{
    if(start>r||end<l)
    {
        return make_pair(0,0);
    }
    if(start>=l&&end<=r)
    {
        return make_pair(tree[treeNode].first, tree[treeNode].second);
    }
    int mid=(start+end)/2;
    pair<int,int>ans1 = query(tree,start,mid,2*treeNode,l,r);
    pair<int,int>ans2 = query(tree,mid+1,end,2*treeNode+1,l,r);
    pair<int,int>ans3;
    merge(ans3,ans1,ans2);
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll>v(n,0);
    FOR(i,0,n)
    {
        cin>>v[i];
    }
    vector<pair<int,int> >tree(4*n, make_pair(0,0));
    buildTree(v,tree,0,n-1,1);
    return 0;
}