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
        string a,b;
        cin>>a>>b;
        bool flag=true;
        bool eq=true;
        vector<vector<ll> >ca(26,vector<ll>());
        vector<vector<ll> >cb(26,vector<ll>());
        FOR(i,0,n)
        {
            if(b[i]>a[i])
            {
                flag=false;
                break;
            }
            ca[a[i]-'a'].pb(i);
            cb[b[i]-'a'].pb(i);
            // if(b[i]!=a[i])
            // {
            //     eq=false;
            // }
        }
        if(flag==false)
        {
            cout<<"-1\n";
            continue;
        }
        FOR(i,0,n)
        {
            if(a[i]!=b[i])
            {
                eq=false;
            }
        }
        if(eq)
        {
            cout<<"0\n";
        }
        else
        {
            vector<unordered_set<ll> >ans;
            for(ll i=25;i>=0;i--)
            {
                if(cb[i].size()>0)
                {
                    if(ca[i].size()==0)
                    {
                        flag=false;
                        break;
                    }
                    unordered_set<ll>s;
                    FOR(j,0,cb [i].size())
                    {
                        s.insert(cb[i][j]);
                    }                   
                    FOR(j,0,1)
                    {
                        s.insert(ca[i][j]);
                    }
                    ans.pb(s);
                }
            }
            if(flag==false)
            {
                cout<<"-1\n";
                continue;
            }
            cout<<ans.size()<<"\n";
            FOR(i,0,ans.size())
            {
                unordered_set<ll>::iterator it=ans[i].begin();
                cout<<ans[i].size();
                while(it!=ans[i].end())
                {
                    cout<<" "<<(*it);
                    it++;
                }
                cout<<"\n";
            }        
        } 
    }
    return 0;
}