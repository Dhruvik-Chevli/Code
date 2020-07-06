#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the roadsAndLibraries function below.
int root(int a,vector<int>&parent)
{
    return (a==parent[a])?a:parent[a]=root(parent[a],parent); 
}

bool DSUFind(vector<int>parent,int a, int b)
{
    return root(a,parent)==root(b,parent);
}

void DSUUnion(vector<int>&parent,vector<int>&size, int a,int b)
{
    a=root(a,parent);
    b=root(b,parent);
    if(a==b)
    {
        return;
    }
    if(size[a]<size[b]) swap(a,b);
    parent[b]=a;
    size[a]+=size[b];
    return;
}

void dfs(vector<vector<int> >&graph, int start,unordered_set<int>&comp,vector<bool>&visited)
{   
    visited[start]=true;
    comp.insert(start);
    for(int i=0;i<graph[start].size();i++)
    {
        if(!visited[graph[start][i]])
        {
            dfs(graph,graph[start][i],comp,visited);
        }
    }
    return;
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int> > cities) {
    vector<int>par(n+1,0);
    vector<int>size(n+1,1);
    vector<vector<int> >graph(n+1,vector<int>());
    if(c_lib<c_road)
    {
        return n*c_lib;
    }
    for(int i=0;i<cities.size();i++)
    {
        // if(DSUFind(par,cities[i][0],cities[i][1]))
        // {
        //     continue;
        // }
        // else
        // {
        //     DSUUnion(par,size,cities[i][0],cities[i][1]);
            graph[cities[i][0]].push_back(cities[i][1]);
            graph[cities[i][1]].push_back(cities[i][0]);
    }
    vector<bool>visited(n+1,false);
    long int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            unordered_set<int> component;
            dfs(graph,i,component,visited);
            long int k=component.size();
            ans+=((k-1)*c_road+c_lib);
        }
    }
    return ans;



}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
