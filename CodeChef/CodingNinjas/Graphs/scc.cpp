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
void dfs(vector<int>*edges,int start, unordered_set<int>&visited,stack<int>&finishStack)
{
    visited.insert(start);
    for(int i=0;i<edges[start].size();i++ )
    {
        int adjacent = edges[start][i];
        if(visited.count(adjacent)==0)
        {
            dfs(edges,adjacent,visited,finishStack);
        }
    }
    finishStack.push(start);
    return;
}
void dfs2(vector<int>*edgesT,int start, unordered_set<int>* component,unordered_set<int>&visited)
{
    visited.insert(start);
    component->insert(start);
    for(int i=0;i<edges[start].size();i++ )
    {
        int adjacent = edges[start][i];
        if(visited.count(adjacent)==0)
        {
            dfs2(edges,adjacent,component,visited);
        }
    }
}
unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges,vector<int>*edgesT,int n)
{
    unordered_set<int>visited;
    stack<int> finishedVertices;
    for(int i=0;i<n;i++)
    {
        if(visited.count(i)==0)
        {
            dfs(edges,i,visited,finishedVertices);
        }
    }
    unordered_set<unordered_set<int>*>* output=new unordered_set<unordered_set<int>*>();
    visited.clear();
    while(!finishedVertices.empty())
    {
        int element=finishedVertices.top();
        finishedVertices.pop();
        if(visited.count(element)!=0)
        {
            continue;
        }
        unordered_set<int>* component=new unordered_set<int>();
        dfs2(edgesT, element,component,visited);
        output->insert(component);
    }
    return output;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>*edges = new vector<int>[n];
    vector<int>*edgesT=new vector<int>[n];
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int j,k;
        cin>>j>>k;
        edges[j-1].pb(k-1);
        edgesT[k-1].pb(j-1);
    }
    unordered_set<unordered_set<int>*>* components = getSCC(edges,edgesT,n);
    
    return 0;
}