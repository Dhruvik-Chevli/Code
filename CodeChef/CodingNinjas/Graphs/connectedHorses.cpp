#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_set>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
ll fact(int n)
{
    if(n==1)
        return 1;
    return n*fact(n-1);
}
void dfs(vector<vector<int> >graph,ll start,vector<bool>&visited,unordered_set<int>*component)
{
    visited[start]=true;
    component->insert(start);
    FOR(i,0,graph[start].size())
    {
        if(!visited[graph[start][i]])
        {
            dfs(graph,graph[start][i],visited,component);
        }
    }
}
unordered_set<unordered_set<int>*>* getComponents(vector<vector<int> >&graph, ll n)
{
    vector<bool>visited(n,false);
    unordered_set<unordered_set<int>*>*output=new unordered_set<unordered_set<int>*>();
    FOR(i,0,n)
    {
        if(!visited[i])
        {
            unordered_set<int>* component=new unordered_set<int>();
            dfs(graph,i,visited,component);
            output->insert(component);
        }
    }
    return output;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,q;
        cin>>n>>m>>q;
        vector<vector<int> >board(n,vector<int>(m,0));
        vector<vector<int> >graph(n);
        FOR(i,0,q)
        {
            ll u,v;
            cin>>u>>v;
            u=u-1;
            v=v-1;
            board[u][v]=i+1;
            if(u-2>=0 and u-2<n and v-1>=0 and v-1<m and board[u-2][v-1]!=0)
            {
                graph[i-1].pb(board[u-2][v-1]-1);
                graph[board[u-2][v-1]-1].pb(i);
            }
            if(u-2>=0 and u-2<n and v+1>=0 and v+1<m and board[u-2][v+1]!=0)
            {
                graph[i-1].pb(board[u-2][v+1]-1);
                graph[board[u-2][v+1]-1].pb(i);
            }
            if(u+2>=0 and u+2<n and v-1>=0 and v-1<m and board[u+2][v-1]!=0)
            {
                graph[i-1].pb(board[u+2][v-1]-1);
                graph[board[u+2][v-1]-1].pb(i);
            }
            if(u+2>=0 and u+2<n and v+1>=0 and v+1<m and board[u+2][v+1]!=0)
            {
                graph[i-1].pb(board[u+2][v+1]-1);
                graph[board[u+2][v+1]-1].pb(i);
            }
            if(u-1>=0 and u-1<n and v-2>=0 and v-2<m and board[u-1][v-2]!=0)
            {
                graph[i-1].pb(board[u-1][v-2]-1);
                graph[board[u-1][v-2]-1].pb(i);
            }
            if(u-1>=0 and u-1<n and v+1>=0 and v+1<m and board[u-1][v+1]!=0)
            {
                graph[i-1].pb(board[u-1][v+2]-1);
                graph[board[u-1][v+2]-1].pb(i);
            }
            if(u+1>=0 and u+1<n and v-2>=0 and v-2<m and board[u+1][v-2]!=0)
            {
                graph[i-1].pb(board[u+1][v-2]-1);
                graph[board[u+1][v-2]-1].pb(i);
            }
            if(u+1>=0 and u+1<n and v+2>=0 and v+2<m and board[u+1][v+2]!=0)
            {
                graph[i-1].pb(board[u+1][v+2]-1);
                graph[board[u+1][v+2]-1].pb(i);
            }
        }
        unordered_set<unordered_set<int>*>*components=getComponents(graph,n);
        unordered_set<unordered_set<int>*>::iterator it1=components->begin();
        ll ans=1;
        while(it1!=components->end())
        {
            ans=(ans*fact((*it1)->size()))%MOD;
            it1++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}