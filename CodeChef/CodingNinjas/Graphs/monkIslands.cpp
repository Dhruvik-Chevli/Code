#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
void solve(vector<vector<ll> >&graph, ll n)
{
    queue<ll>q;
    vector<ll>visited(n,0);
    vector<ll>level(n,-1);
    level[0]=0;
    visited[0]=1;
    q.push(0);
    if(n==1)
    {
        cout<<0<<"\n";
        return;
    }
    while(!q.empty())
    {
        ll k=q.front();
        q.pop();
        FOR(i,0,graph[k].size())
        {
            ll u=graph[k][i];
            if(!visited[u])
            {
                level[u]=level[k]+1;
                q.push(u);
                visited[u]=1;
                if(u==n-1)
                {
                    cout<<level[n-1]<<endl;
                    return;
                }
            }
        }
    }
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
        vector<vector<ll> >graph(n);
        FOR(i,0,m)
        {
            ll u,v;
            cin>>u>>v;
            graph[u-1].pb(v-1);
            graph[v-1].pb(u-1);
        }
        solve(graph,n);
    }
    return 0;
}