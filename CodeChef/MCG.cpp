#include <bits/stdc++.h>
using namespace std;
void printCost(int n,int* parent,vector<vector<int> >graph)
{
    int cost = 0;
    for (int i = 1; i < n; i++)
        cost += graph[parent[i]][i];
    cout<<cost<<"\n";
    return;
}
int minimumNode(int n, int keyval[], bool mst[])
{
    int mini = numeric_limits<int>::max();
    int mini_index;
    for (int i = 0; i < n; i++)
    {
        if (mst[i] == false && keyval[i] < mini)
        {
            mini = keyval[i], mini_index = i;
        }
    }
    return mini_index;
}

void Cost(int n, vector<vector<int>> graph)
{
    int parent[n];
    int key[n];
    bool mst[n];
    for (int i = 0; i < n; i++)
    {
        key[i] = numeric_limits<int>::max();
        mst[i] = false;
    }
    parent[0] = -1;
    key[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u = minimumNode(n, key, mst);
        mst[u] = true;
        for (int v = 0; v < n; v++)
        {

            if (graph[u][v] && mst[v] == false &&
                graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    printCost(n,parent,graph);
}

int main()
{
    int t;
    cin >> t;
    vector<long long> maxdis(t);
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> graph(n, vector<int>(n));
        int i, j, e1, e2;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                int x;
                cin>>x;
                if(x == -1)
                {
                    graph[i][j] = 0;
                    continue;
                }
                graph[i][j] = x;
            }
        }
        Cost(n, graph);
    }
    
}
