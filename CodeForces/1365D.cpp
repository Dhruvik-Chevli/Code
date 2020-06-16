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
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
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
bool dfs(vector<string>&graph,ll i, ll j, ll ei, ll ej,vector<vector<bool> >&visited,vector<vector<bool> >&reachable)
{
    visited[i][j]=true;
    if(i==ei and j==ej)
    {
        return true;
    }
    FOR(k,0,4)
    {
        ll x=i+dx[k];
        ll y=j+dy[k];
        if(x>=0 and x<=ei and y>=0 and y<=ej and graph[x][y]!='#' and !visited[x][y])
        {
            bool ans=dfs(graph,x,y,ei,ej,visited,reachable);
            if(ans)
            {
                reachable[i][j]=true;
                return true;
            }
        }
        if(x>=0 and x<=ei and y>=0 and y<=ej and reachable[x][y])
        {
            reachable[i][j]=true;
            return true;
        }
    }
    return false;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<string>v(n);
        FOR(i,0,n)
        {
            string s;
            cin>>s;
            v[i]=s;
        }
        bool flag=true;
        bool g=false;
        FOR(i,0,n)
        {
            FOR(j,0,m)
            {
                if(v[i][j]=='G')
                {
                    g=true;
                }
                if(v[i][j]=='B')
                {
                    FOR(k,0,4)
                    {
                        ll x=i+dx[k];
                        ll y=j+dy[k];
                        if(x>=0 and x<n and y>=0 and y<m and v[x][y]=='.')
                        {
                            v[x][y]='#';
                        }
                        if(x>=0 and x<n and y>=0 and y<m and v[x][y]=='G')
                        {
                            g=true;
                            flag=false;
                            break;
                        }
                    }
                }
                if(!flag)
                {
                    break;
                }
            }
            if(!flag)
            {
                break;
            }
        }
        vector<vector<bool> > reachable(n,vector<bool>(m,false));
        if(flag and g and v[n-1][m-1]!='#')
        {
            FOR(i,0,n)
            {
                FOR(j,0,m)
                {
                    if(v[i][j]=='G')
                    {
                        vector<vector<bool> >visited(n,vector<bool>(m,false));
                        if(reachable[i][j])
                        {
                            continue;
                        }
                        bool ans=dfs(v,i,j,n-1,m-1,visited,reachable);
                        if(!ans)
                        {
                            flag=false;
                            break;
                        }
                    }
                }
                if(!flag)
                {
                    break;
                }
            }
        }
        if(v[n-1][m-1]!='#')
        {   if(flag)
            {
                cout<<"Yes\n";
            }
            else if(!g)
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
            
        }   
        else
        {
            if(!g)
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
            
        }
        
    }
    return 0;
}