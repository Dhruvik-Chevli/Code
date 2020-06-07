// YOU CAN USE PRIORITY QUEUES TO OPTIMISE PRIMS ALGORITHM FURTHER




#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<climits>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
int getMinVertex(vector<bool>&visited,vector<int>&weight,int n)
{
    int minVertex=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i]&& ((minVertex==-1)||(weight[minVertex]>weight[i])))
        {
            minVertex=i;
        }
    }
    return minVertex;
}
void prim(vector<vector<int> >&graph,int n)
{
    vector<bool>visited(n,false);
    vector<int>parent(n,0);
    vector<int>weight(n,INT_MAX);
    parent[0]=-1;
    weight[0]=0;

    for(int i=0;i<n-1;i++)
    {
        //get min vertex
        int minVertex=getMinVertex(visited,weight,n);
        visited[minVertex] = true;
        //Explore all neighbours of minVertex and update parent and weight array accordingly
        for(int j=0;j<n;j++)
        {
            if(graph[minVertex][j]!=0&& !visited[j])
            {
                if(weight[j]>graph[minVertex][j])
                {
                    weight[j]=weight[minVertex]+graph[minVertex][j];
                    parent[j]=minVertex;
                }
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(parent[i]<i){
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        else
        {
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
        
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e;
    cin>>n>>e;
    vector<vector<int> >graph(n,vector<int>(n,0));
    FOR(i,0,e)
    {
        int f,s,w;
        cin>>f>>s>>w;
        graph[f][s]=w;
        graph[s][f]=w;
    }
    prim(graph,n);
    return 0;
}