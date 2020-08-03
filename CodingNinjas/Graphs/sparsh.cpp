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
// #define pb push_back
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
void getAllPaths(int curh, int cury,int h, int y,vector<string>&ans,string s)
{
    if(curh==h and cury==y)
    {
        ans.push_back(s);
        return;
    }
    if(curh>h or cury>y)
    {
        return;
    }
    if(curh<h)
    {
        string s1=s+'H';
        getAllPaths(curh+1,cury,h,y,ans,s1);
    }
    if(cury<y)
    {
        string s1=s+'V';
        getAllPaths(curh,cury+1,h,y,ans,s1);
    }
}
vector<string> getPaths(int x,int y)
{
    vector<string>ans;
    string cur="";
    getAllPaths(0,0,x,y,ans,cur);
    sort(ans.begin(),ans.end());
    return ans;
}
vector<string>getSafePaths(vector<string> journeys)
{
    vector<string>ans;
    vector<vector<vector<string> > >poss(10,vector<vector<string> >(10,vector<string>()));
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            vector<string> ans1=getPaths(i+1,j+1);
            poss[i][j].push_back(ans1);
        }
    }
    for(int i=0;i<journeys.size();i++)
    {
        int j=0;
        int k=0;
        while(journeys[i][j]!=' ')
        {
            j++;
        }
        k=j+1;
        while(journeys[i][k]!=' ')
        {
            k++;
        }
        int x=stoi(journeys[i].substr(0,j));
        
        int y=stoi(journeys[i].substr(j+1,k-j));
        int z=stoi(journeys[i].substr(k+1));
        ans.push_back(poss[i-1][j-1][k]);
    }
    return ans;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string>journeys;
    cin.ignore();
    FOR(i,0,n)
    {
        string s;
        getline(cin,s);
        journeys.push_back(s);
    }
    FOR(i,0,n)
    {
        cout<<journeys[i]<<"\n";
    }
    vector<string>ans=getSafePaths(journeys);
    FOR(i,0,ans.size())
    {
        cout<<ans[i]<<"\n";
    }
    return 0;
}