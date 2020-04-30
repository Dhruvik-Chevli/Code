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
pair<int,int> bfs(vector<vector<int> >graph,int start,int n)
{
    vector<bool>visited(n+1);
    queue<int>q;
    vector<int>distance(n+1);
    q.push(start);
    visited[start]=true;
    distance[start]=0;
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        FOR(i,0,graph[k].size())
        {
            if(!visited[graph[k][i]])
            {
                visited[graph[k][i]]=true;
                distance[graph[k][i]]=distance[k]+1;
                q.push(graph[k][i]);
            }
        }
    }
    ll ind=-1;
    ll max=-1;
    FOR(i,1,n+1)
    {
        if(distance[i]>max)
        {
            ind=i;
            max=distance[i];
        }
    }
    return make_pair(ind,max);
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
        vector<vector<int> >graph(n+1,vector<int>());
        FOR(i,0,n-1)
        {
            ll u,v;
            cin>>u>>v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        pair<int,int>first=bfs(graph,1,n);
        pair<int,int>second=bfs(graph,first.first,n);
        cout<<second.second<<endl;
    }
    return 0;
}