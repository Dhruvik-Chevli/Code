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
int flag;
void dfs(vector<vector<ll> >&graph, vector<pair<bool,int> >&visited, ll start,ll dist,ll source)
{
    if(dist<0)
    {
        return;
    }
    if(visited[start].first==true and visited[start].second!=source)
    {
        flag=0;
    }
    visited[start].first=true;
    visited[start].second=source;
    if(dist==0)
        return;
    FOR(i,0,graph[start].size())
    {
        if(visited[graph[start][i]].first==false)
        {
            dfs(graph,visited,graph[start][i],dist-1,source);
        }
        else if(visited[graph[start][i]].first==true and visited[graph[start][i]].second!=source)
        {
        	flag=0;
        	continue;
        }
    }
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        flag=1;
        ll n,r,m;
        cin>>n>>r>>m;
        vector<vector<ll> >graph(n,vector<ll>());
        FOR(i,0,r)
        {
            ll u,v;
            cin>>u>>v;
            graph[u-1].pb(v-1);
            graph[v-1].pb(u-1);
        }
        vector<pair<bool,int> >visited(n,make_pair(false,-1));
        vector<pair<int,int> >sold(m);
        FOR(i,0,m)
        {
            ll k,s;
            cin>>k>>s;
            k--;
            sold.pb(make_pair(s,k));
        }
        sort(sold.rbegin(),sold.rend());
        FOR(i,0,m)
        {
            ll k=sold[i].second;
            ll s=sold[i].first;
            if(visited[k].first==true)
            {
                flag=0;
            }
            else if(visited[k].first==false)
            {
                dfs(graph,visited,k,s,k);
            }
            // FOR(i,0,n)
            // {
            //     cout<<visited[i].first<<" ";
            // }
            // cout<<endl;
        }
        if(flag)
        {
            // FOR(i,0,n)
            // {
            //     if(visited[i].first==false)
            //     {
            //         flag=0;
            //         break;
            //     }
            // }
            // if(flag)
                cout<<"Yes\n";
            // else
            // {
            //     cout<<"No\n";
            // }
        }
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}