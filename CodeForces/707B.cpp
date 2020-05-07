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
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll> >graph(n,vector<ll>(n,INT_MAX));
    FOR(i,0,m)
    {
        ll u,v,l;
        cin>>u>>v>>l;
        if(graph[u-1][v-1]>l)
        {
            graph[u-1][v-1]=l;
            graph[v-1][u-1]=l;
        }
    }
    vector<ll>set;
    vector<bool>isStorage(n+1,false);
    FOR(i,0,k)
    {
        ll u;
        cin>>u;
        set.pb(u-1);
        isStorage[u-1]=true;
    }
    ll min=INT_MAX;
    int flag=0;
    FOR(j,0,set.size())
    {
        ll u=set[j];
        FOR(i,0,n)
        {
            if(!(isStorage[i]))
            {
                if(graph[u][i]<min)
                {
                    flag=1;
                    min=graph[u][i];
                }
            }
        }
    }  
    if(flag)
    {
        cout<<min<<endl;
    }
    else
    {
        cout<<"-1\n";
    }
    return 0;
}