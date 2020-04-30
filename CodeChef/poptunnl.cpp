#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#define pb push_back
using namespace std;
typedef long long int ll;
ll bfs(ll n,vector< vector<int> > &graph,ll src,ll dest)
{
    vector<ll>visited(n,0);
    vector<ll>dist(n,-1);
    queue<ll>nodes;
    dist[src]=0;
    nodes.push(src);
    visited[src]=1;
    while(!nodes.empty())
    {
        ll cur=nodes.front();
        nodes.pop();
        if(cur==dest)
        {
            return dist[cur];
        }
        for(ll i=0;i<graph[cur].size();i++)
        {
            if (visited[graph[cur][i]]==0)
            {
                nodes.push(graph[cur][i]);
                dist[graph[cur][i]]=dist[cur]+1;
                visited[graph[cur][i]]=1;
            }
        }
        
    }
    return -1;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        string a;
        vector< vector<int> >graph(n);
        for(ll i=0;i<n;i++)
        {
            cin>>a;
            for(ll j=i-k;j<=i+k;j++)
            {
                if (j<0)
                    continue;
                if(j>n)
                    continue;
                if (a[j]=='1' and j!=i)
                {
                    graph[i].pb(j);
                }
            }
        }
       /* for(int i=0;i<n;i++)
    {
        cout<<i<<" : ";
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;
    }*/
    cout<<bfs(n,graph,0,n-1)<<endl;



    }

}