#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<queue>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
int countIndus(vector<vector<ll> >&graph,vector<bool>&visited,vector<bool>&isIndus,vector<ll> &count, int start)
{
    if(count[start]!=-1)
    {
        return count[start];
    }
    visited[start]=true;
    ll c=0;
    FOR(i,0,graph[start].size())
    {
        if(!visited[graph[start][i]])
        {
            c+=countIndus(graph,visited,isIndus,count,graph[start][i]);
        }
    }
    if(isIndus[start])
    {
        count[start]=c+1;
        return c+1;
    }
    else
    {
        count[start]=c;
        return c;
    }
}
void setTree(vector<vector<ll> >&graph,ll &k,vector<bool>&isIndus,ll start,ll n)
{
    vector<bool>visited(n+1,false);
    queue<ll>nodes;
    nodes.push(start);
    ll passed=n;
    visited[start]=true;
    while(!nodes.empty())
    {
        ll cur=nodes.front();
        nodes.pop();
        int f=0;
        for(ll i=0;i<graph[cur].size();i++)
        {
            if(!visited[graph[cur][i]])
            {
                f=1;
                nodes.push(graph[cur][i]);
                visited[graph[cur][i]]=true;
            }        
        }
        if(passed<=k)
        {
            isIndus[cur]=true;
        }
        if(f==0 and --k)
        {
            isIndus[cur]=true;
        }
        passed-=1;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<vector<ll> >graph(n+1,vector<ll>());
    ll u,v;
    FOR(i,0,n-1)
    {
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    vector<bool>isIndus(n+1,false);
    setTree(graph,k,isIndus,1,n);
    FOR(i,0,n+1)
    {
        cout<<isIndus[i]<<" ";
    }
    cout<<endl;
    //countAns(graph,isIndus,1);
    vector<ll>count(n+1,-1);
    vector<bool>visited(n+1,0);
    countIndus(graph,visited,isIndus,count,1);
    ll  ans=0;
    FOR(i,0,n+1)
    {
        if(count[i]!=-1 && isIndus[i]==false)
        {
            ans+=count[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}