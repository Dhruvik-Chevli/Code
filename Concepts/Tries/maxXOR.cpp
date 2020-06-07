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
class trieNode 
{
    public:
        trieNode* left;
        trieNode* right;
};
ll power(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)
        {
            res*=x;
        }
        y>>=1;
        x*=x;
    }
    return res;
}
void insert(ll n,trieNode* root)
{
    trieNode* cur=root;
    for(int i=31;i>=0;i--)
    {
        ll b=(n>>i)&1;
        if(b)
        {
            if(cur->right)
            {
                cur=cur->right;
            }
            else
            {
                cur->right=new trieNode();
                cur=cur->right;
            }
        }
        else
        {
            if(cur->left)
            {
                cur=cur->left;
            }
            else
            {
                cur->left=new trieNode();
                cur=cur->left;
            }
        }
    }
    return;
}
ll findMax(vector<ll>v,trieNode* root)
{
    int maxXOR=INT_MIN;
    FOR(i,0,v.size())
    {
        trieNode* cur=root;
        ll curxor=0;
        ll n=v[i];
        for(int j=31;j>=0;j--)
        {
            ll b=(n>>j)&1;
            if(b)
            {
                if(cur->left)
                {
                    cur=cur->left;
                }
                else
                {
                    curxor+=power(2,j);
                    cur=cur->right;
                }
            }
            else
            {
                if(cur->right)
                {
                    curxor+=power(2,j);
                    cur=cur->right;
                }
                else
                {
                    cur=cur->left;
                }
            }
        }
        if(curxor>maxXOR)
        {
            maxXOR=curxor;
        }
    }
    return maxXOR;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}