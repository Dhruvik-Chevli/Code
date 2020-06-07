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
        ll n;
        cin>>n;
        //vector<bool>nooc(100000,false);
        //vector<bool>ele(100000,false);
        unordered_map<ll,ll>freq;
        vector<ll>v(n,0);
        FOR(i,0,n)
        {
            cin>>v[i];
        }
       // ele[v[0]]=true;
        ll prev=v[0];
        //ll count=1;
        ll flag=1;
        freq[v[0]]=1;
        FOR(i,1,n)
        {
            if(v[i]!=prev)
            {
                if(freq.count(v[i])>0)
                {
                    flag=0;
                    break;
                }
                else
                {
                    freq[v[i]]=1;
                    prev=v[i];
                }
            }
            else
            {
                freq[v[i]]+=1;
            }
        }
        if(flag)
        {
            unordered_map<ll,ll>ans;
            for(auto x: freq)
            {
                //cout<<x.first<<" "<<x.second<<"\n";
                if(ans.count(x.second)>0)
                {
                    flag=0;
                    break;
                }
                ans[x.second]=1;
            }
        }
        if(flag)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}