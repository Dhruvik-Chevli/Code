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
void dfs(vector<vector<ll> >&graph,vector<bool>&visited,ll start,vector<pair<pair<ll,ll>,ll> >&ans,ll sta,ll minDiameter,ll n)
{
    visited[start]=true;
    bool f=true;
    FOR(i,0,n+1)
    {
        if(graph[start][i]!=0)
        {
            if(visited[i])
                return;
            f=false;
            if(graph[start][i]<minDiameter)
            {
                minDiameter=graph[start][i];
            }
            dfs(graph,visited,i,ans,sta,minDiameter,n);
            return;
        }
    }
    if(f)
    {
        ans.pb(make_pair(make_pair(sta,start),minDiameter));
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
    ll n,p;
    cin>>n>>p;
    unordered_map<ll,ll>map1,map2;
    vector<vector<ll> >graph(n+5,vector<ll>(n+5,0));
    vector<ll>start(p,0);
    FOR(i,0,p)
    {
        ll a,b,d;
        cin>>a>>b>>d;
        if(map1.count(a)>0)
        {
            map1[a]+=1;
        }
        else
        {
            map1[a]=1;
        }
        if(map2.count(b)>0)
        {
            map2[b]+=1;
        }
        else
        {
            map2[b]=1;
        }
        graph[a][b]=d;
    }
    vector<pair<pair<ll,ll>,ll> >ans;
    vector<bool>visited(n,false);
    unordered_map<ll,ll>::iterator it1=map1.begin();
    while(it1!=map1.end())
    {
        if((*it1).second==1 and map2.count((*it1).first)==0 and !visited[(*it1).first])
        {
            dfs(graph,visited,(*it1).first,ans,(*it1).first,INT_MAX,n);
        }
        it1++;
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    FOR(i,0,ans.size())
    {
        cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<"\n";
    }
    return 0;
}