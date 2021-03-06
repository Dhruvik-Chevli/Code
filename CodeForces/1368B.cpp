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
  
    x = x ;//% p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) ;//% p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x);// % p;  
    }  
    return res;  
}  
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //fopen("1368BA.txt","w",stdout);
    ll k;
    cin>>k;
    //cout<<"*";
    string s;
    string ans="";
    s="codeforces";
    ll i=1;
    ll high = 1;
    while(true)
    {
        ll n=power(i,10);
        if(n>k)
        {
            //cout<<"(";
            high=i;
            break;
        }
        i+=1;
    }
    //cout<<high;
    ll count=0;
    ll n=power(high-1,10);
    while(n<k)
    {
        n=n/(high-1);
        n*=high;
        //cout<<")";
        count+=1;
    }
    FOR(i,0,count)
    {
        FOR(j,0,high)
        {
            ans+=s[i];
        }
    }
    FOR(i,count,10)
    {
        FOR(j,0,high-1)
        {
            ans+=s[i];
        }
    }
    cout<<ans<<"\n";
    return 0;
}