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
    ll n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    ll d=0;
    FOR(i,0,n)
    {
        if(s[i]=='1')
        {
            d=1;
            break;
        }
    }
    if(d==0)
    {
        cout<<s<<"\n";
        return 0;
    }
    // FOR(i,0,n)
	vector<bool>nn(n,true);
    FOR(i,0,n)
    {
		if(nn[i]==false)
			continue;
		// if(nn.count(i)<=0)
		// {
		// 	continue;
		// }
        if(y<=0)
            break;
        if(s[i]=='1')
        {
            continue;
        }
        ll j=i+x;
        ll d=y-1;
        while(d>0 and j<n)
        {
            if(j<n and s[j]=='1')
            {
                break;
            }
            j+=x;
            d-=1;
        }
        if(j<n and s[j]=='1')
        {
            swap(s[i],s[j]);
            y-=(j-i)/x;
        }
		else{
			for(ll k=i;k<n;k+=x)
			{
				nn[k]=true;
			}
		}
    }
    cout<<s<<"\n";
    return 0;
}