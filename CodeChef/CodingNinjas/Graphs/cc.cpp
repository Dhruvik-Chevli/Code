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
void dfs(vector<vector<int> >&graph,int start,unordered_set<int>*component,vector<bool>&visited )
{
    cout<<"*";
    visited[start]=1;
    component->insert(start);
    FOR(i,0,graph[start].size())
    {
        if(!visited[graph[start][i]])
        {
            dfs(graph,graph[start][i],component,visited);
        }
    }
}
unordered_set<unordered_set<int>*>* getComponents(vector<vector<int> >graph,int n)
{
    vector<bool>visited(n,false);
    unordered_set<unordered_set<int>*>* output=new unordered_set<unordered_set<int>*>();
    for(int i=0;i<n;i++)
    {
        cout<<"*";
        if(!visited[i])
        {
            unordered_set<int>* component=new unordered_set<int>();
            dfs(graph,i,component,visited);
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
        int n;
        cin>>n;
        vector<vector<int> >graph(n);
        int m;
        cin>>m;
        FOR(i,0,m)
        {
            int u,v;
            cin>>u>>v;
            graph[u-1].pb(v-1);
            graph[v-1].pb(u-1);
        }
        unordered_set<unordered_set<int>*>*components=getComponents(graph,n);
        cout<<"&&";
        unordered_set<unordered_set<int>*>iterator::it1=components->begin();
        ll max=0;
        while(it1!=components.end())
        {
            ll u=(*it1)->size();
            if(u>max)
            {
                max=u;
            }
        }
        cout<<max<<endl;
    }
    return 0;
}