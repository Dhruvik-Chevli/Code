#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
vector<ll> getPathBFS(vector<vector<ll> >&graph,ll n,ll start,ll end,vector<bool>&visited)
{
    queue<ll>nodes;
    visited[start]=true;
    nodes.push(start);
    unordered_map<ll,ll>map;
    int f=0;
    while(!nodes.empty())
    {
        ll cur=nodes.front();
        nodes.pop();
        FOR(i,0,n)
        {
            if(!visited[i] && graph[cur][i])
            {
                map[i]=cur;
                nodes.push(i);
                visited[i]=1;
                if(i==end)
                {
                    f=1;
                    break;
                }
            }
        }
        if(f)
            break;
    }
    vector<ll>ans;
    if(f)
    {
        while(map.count(end))
        {
            ans.pb(end);
            end=map[end];
        }
        ans.pb(start);
        return ans;
    }
    else
        return ans;
}
vector<ll> getPathDfs(vector<vector<ll> >&graph,ll n,ll start,ll end, vector<bool>&visited)
{
    if(start==end)
    {
        vector<ll>v;
        v.pb(start);
        return v;
    }
    visited[start]=true;
    FOR(i,0,n)
    {
        if(!visited[i] && graph[start][i])
        {
            visited[i]=true;
            vector<ll> ans=getPathDfs(graph,n,i,end,visited);
            if(ans.size()!=0)
            {
                ans.pb(start);
                return ans;
            }
            else
            {
                visited[i]=false;
            }
        }
    }
    visited[start]=false;
    vector<ll>v;
    return v;
}
bool hasPath(vector<vector<ll> >&graph,ll n,ll start,ll end,vector<bool>&visited)
{
    if(start==end or graph[start][end])
        return true;
    visited[start]=true;
    FOR(i,0,n)
    {
        if(!visited[i]&&graph[start][i])
        {
            if(hasPath(graph,n,i,end,visited))
                return true;
        }
    }
    return false;
}
void bfs(vector<vector<ll> >&graph,ll n,ll start,vector<bool>&visited)
{
    queue<ll>nodes;
    nodes.push(start);
    //vector<bool>visited(n+1,false);
    visited[start]=true;
    while(!nodes.empty())
    {
        ll cur=nodes.front();
        nodes.pop();
        cout<<cur<<" ";
        FOR(i,0,n)
        {
            if(!visited[i] && graph[cur][i])
            {
                nodes.push(i);
                visited[i]=true;
            }
        }
    }
    //cout<<endl;
    return;
}
void dfs(vector<vector<ll> >&graph,ll n,ll start,vector<bool>&visited)
{
    visited[start]=true;
    FOR(i,0,n)
    {
        if(!visited[i] and graph[start][i])
            dfs(graph,n,i,visited);
    }
    return;
}
vector<ll> bfs(vector<vector<ll> >&graph,ll n,ll start,vector<bool>&visited)
{
    vector<ll>ans;
    queue<ll>nodes;
    nodes.push(start);
    visited[start]=true;
    while(!nodes.empty())
    {
        ll cur=nodes.front();
        nodes.pop();
        ans.pb(cur);
        FOR(i,0,n)
        {
            if(!visited[i] && graph[cur][i])
            {
                nodes.push(i);
                visited[i]=true;
            }
        }
    }
    return ans;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<vector<ll> >graph(n+1,vector<ll>(n+1,0));
    //cin>>v;
    FOR(i,0,m)
    {
        ll u,v;
        cin>>u>>v;
        graph[v][u]=1;
        graph[u][v]=1;
    }
    vector<bool>visited(n,false);
    //ll v,u;
    //cin>>v>>u;
    //vector<ll>path=getPathBFS(graph,n,v,u,visited);
    //FOR(i,0,path.size())
    //{
    //    cout<<path[i]<<" ";
    //}
    dfs(graph,n,0,visited);
    int f=0;
    FOR(i,0,n)
    {
        if(visited[i]==false)
        {
            f=1;
        }
    }
    if(f)
    {
        cout<<"false\n";
    }
    else
        cout<<"true\n";
    return 0;
}