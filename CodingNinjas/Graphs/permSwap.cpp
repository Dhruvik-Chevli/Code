#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_set>
#include<set>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
void dfs(vector<vector<int> >graph,ll start,vector<bool>&visited,unordered_set<int>*component)
{
    visited[start]=true;
    component->insert(start);
    FOR(i,0,graph[start].size())
    {
        if(!visited[graph[start][i]])
        {
            dfs(graph,graph[start][i],visited,component);
        }
    }
}
unordered_set<unordered_set<int>*>* getComponents(vector<vector<int> >&graph, ll n)
{
    vector<bool>visited(n,false);
    unordered_set<unordered_set<int>*>*output=new unordered_set<unordered_set<int>*>();
    FOR(i,0,n)
    {
        if(!visited[i])
        {
            unordered_set<int>* component=new unordered_set<int>();
            dfs(graph,i,visited,component);
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
        ll n,m;
        cin>>n>>m;
        vector<ll>p(n);
        vector<ll>q(n);
        FOR(i,0,n)
        {
            cin>>p[i];
        }
        FOR(i,0,n)
        {
            cin>>q[i];
        }
        vector<vector<int> >graph(n);
        FOR(i,0,m)
        {
            ll u,v;
            cin>>u>>v;
            graph[u-1].pb(v-1);
            graph[v-1].pb(u-1);
        }
        unordered_set<unordered_set<int>*>*components=getComponents(graph,n);
        unordered_set<unordered_set<int>*>::iterator it1=components->begin();
        int flag=1;
        while(it1!=components->end())
        {
            set<int>p1;
            set<int>q1;
            unordered_set<int>* component=*it1;
            unordered_set<int>::iterator it2=component->begin();
            while(it2!=component->end())
            {
                //cout<<*it2;
                p1.insert(p[(*it2)]);
                q1.insert(q[(*it2)]);
                it2++;
            }
            //cout<<endl;
            
            set<int>:: iterator ip1=p1.begin();
            set<int>:: iterator iq1=q1.begin();
            while(ip1!=p1.end())
            {
                if(*ip1!=*iq1)
                {
                    flag=0;
                    break;
                }
                ip1++;
                iq1++;
            }
            if(flag==0)
                break;
            it1++;
        }
        if(flag)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        } 
    }
    return 0;
}