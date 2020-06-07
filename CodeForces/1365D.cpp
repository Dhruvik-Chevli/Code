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
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
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
bool dfs(vector<string>&graph,vector<vector<bool> >&pos,ll si,ll sj,ll ei,ll ej,vector<vector<bool> >&visited)
{
    if(pos[si][sj])
    {
        return true;
    }
    if(si==ei and sj==ej)
    {
        pos[si][sj]=true;
        return true;
    }
    else if(si>ei or sj>ej)
    {
     //   cout<<"*****"<<"\n";
        return false;
    }
   // cout<<si<<" "<<sj<<" "<<ei<<" "<<ej<<"\n";
    bool flag=false;
    visited[si][sj]=true;
    FOR(i,0,4)
    {
        ll x=si+dx[i];
        ll y=sj+dy[i];
       // cout<<x<<" "<<y<<"\n";
        if(x>=0 and y>=0 and x<=ei and y<=ej and graph[x][y]!='#' and !visited[x][y])
        {
            bool ans=dfs(graph,pos,x,y,ei,ej,visited);
            if(ans)
            {
                flag=true;
            }
        }
        if(x>=0 and y>=0 and x<=ei and y<=ej and graph[x][y]!='#' and visited[x][y])
        {
            //bool ans=dfs(graph,pos,x,y,ei,ej,visited);
            // 
            flag=true;
        }
    }
    if(flag)
    {
        pos[si][sj]=true;
    }
    return flag;
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
        ll n,m;
        cin>>n>>m;
        vector<string>s(n);
        FOR(i,0,n)
        {
            string v;
            cin>>v;
            s[i]=v;
        }
        bool flag=true;
        FOR(i,0,n)
        {
            FOR(j,0,m)
            {
                //cout<<"&&";
                if(s[i][j]=='B')
                {
                    if(i-1>=0)
                    {
                        if(s[i-1][j]!='G' and s[i-1][j]!='B')
                            s[i-1][j]='#';
                        else if(s[i-1][j]=='G')
                        {
                            flag=false;
                        }
                    }
                    if(j-1>=0)
                    {
                        if(s[i][j-1]!='G' and s[i][j-1]!='B')
                            s[i][j-1]='#';
                        else if(s[i][j-1]=='G')
                        {
                            flag=false;
                        }
                    }
                    if(i+1<n)
                    {
                        if(s[i+1][j]!='G' and s[i+1][j]!='B')
                            s[i+1][j]='#';
                        else if(s[i+1][j]=='G')
                        {
                            flag=false;
                        }
                    }
                    if(j+1<m)
                    {
                        if(s[i][j+1]!='G' and s[i][j+1]!='B')
                            s[i][j+1]='#';
                        else if(s[i][j+1]=='G')
                        {
                            flag=false;
                        }
                    }
                }
            }
            if(flag==false)
            {
                break;
            }
        }
        if(flag==false)
        {
            cout<<"No\n";
            continue;
        }
        // FOR(i,0,n)
        // {
        //     FOR(j,0,m)
        //     {
        //         cout<<s[i][j];
        //     }
        //     cout<<"\n";
        // }
        //cout<<"****\n";
        vector<vector<bool> >pos(n,vector<bool>(m,false));
        vector<vector<bool> >visited(n,vector<bool>(m,false));
        FOR(i,0,n)
        {
            FOR(j,0,m)
            {
                if(s[i][j]=='G')
                {
                    //cout<<i<<" "<<j<<"\n";
                    bool ans=dfs(s,pos,i,j,n-1,m-1,visited);
                    if(!ans)
                        flag=false;
                }
                if(!flag)
                    break;
            }
            if(!flag)
            {
                break;
            }
        }
        if(flag)
            cout<<"Yes\n";
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}