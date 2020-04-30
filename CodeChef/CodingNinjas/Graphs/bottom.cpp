#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<stack>
#include<unordered_set>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
void dfs(vector<vector<ll> >graph,ll start,vector<ll>&visited,stack<ll>&finishedVertices)
{
    visited[start]=1;
    FOR(i,0,graph[start].size())
    {
        if(!visited[graph[start][i]])
        {
            dfs(graph,graph[start][i],visited,finishedVertices);
        }
    }
    finishedVertices.push(start);
}
void dfs2(vector<vector<ll> >&graph,ll start,vector<ll>&visited, unordered_set<ll>* component)
{
    visited[start]=1;
    component->insert(start);
    FOR(i,0,graph[start].size())
    {
       if(!visited[graph[start][i]])
        {
            dfs2(graph,graph[start][i],visited,component);
        } 
    }
}
unordered_set<unordered_set<ll>*>* getSCC(vector<vector<ll> >&graph, vector<vector<ll> >&graphT,ll n)
{
    vector<ll>visited(n,0);
    stack<ll>finishedVertices;
    FOR(i,0,n)
    {
        if(!visited[i])
        {
            dfs(graph,i,visited,finishedVertices);
        }
    }
    visited=vector<ll>(n,0);
    unordered_set<unordered_set<ll>*>* output=new unordered_set<unordered_set<ll>*>();
    while(!finishedVertices.empty())
    {
        ll k=finishedVertices.top();
        finishedVertices.pop();
        if(!visited[k])
        {
            unordered_set<ll>* component=new unordered_set<ll>();
            dfs2(graphT,k,visited,component);
            output->insert(component);
        }
    }
    return output;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true)
    {
        ll n;
        cin>>n;
        if(n==0)
            break;
        vector<vector<ll> >graph(n);
        vector<vector<ll> >graphT(n);
        ll e;
        cin>>e;
        FOR(i,0,e)
        {
            ll u,v;
            cin>>u>>v;
            graph[u-1].pb(v-1);
            graphT[v-1].pb(u-1);
        }
        int f=1;
        unordered_set<unordered_set<ll>*>* components=getSCC(graph,graphT,n);
        unordered_set<unordered_set<ll>*>::iterator it1=components->begin();
        vector<int>ans;
        //cout<<components->size();
        // while(it1!=components->end())
        // {
        //     unordered_set<ll>::iterator it2=(*it1)->begin();
        //     while(it2!=(*it1)->end())
        //     {
        //         cout<<*it2+1<<" ";
        //         it2++;
        //     }
        //     cout<<endl;
        //     it1++;
        // }
        while(it1!=components->end())
        {
            unordered_set<ll>::iterator it2=(*it1)->begin();
            int f=1;
            while(it2!=(*it1)->end() and f==1)
            {
                FOR(i,0,graph[*it2].size())
                {
                    if((*it1)->count(graph[*it2][i])==0)
                    {
                        f=0;
                        break;
                    }
                }
                it2++;
            }
            it2=((*it1)->begin());
            while(it2!=(*it1)->end() and f==1)
            {
                ans.pb(*it2);
                it2++;
            }
            it1++;
        }
        sort(ans.begin(),ans.end());
        FOR(i,0,ans.size())
        {
            cout<<ans[i]+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}