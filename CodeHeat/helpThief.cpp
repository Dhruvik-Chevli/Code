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
void DSUinit(vector<ll>&a,vector<ll>&size,ll n)
{
    FOR(i,0,n)
    {
        a[i]=i;
        size[i]=1;
    }
    return;
}
ll root(vector<ll>&a,ll i)
{
    return (i==a[i])?i:a[i]=root(a,a[i]);
}
bool DSUfind(vector<ll>a,ll x,ll y)
{
    if(root(a,x)==root(a,y))
    {
        return true;
    }
    return false;
}
void DSUunion(vector<ll>&a,vector<ll>&size, ll x,ll y)
{
    x=root(a,x);
    y=root(a,y);
    if(x==y)
    {
        return;
    }
    if(size[x]<size[y]) swap(x,y);
    a[y]=x;
    size[x]+=size[y];
}
bool isPrime(int n) 
{
    if (n <= 1)  return false; 
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
          return false;
    return true; 
}
void dfs(vector<vector<ll> >&graph,vector<bool>&visited,ll start,stack<ll>&st)
{
    visited[start]=true;
    FOR(i,0,graph[start].size())
    {
        if(!(visited[graph[start][i]]))
        {
            dfs(graph,visited,graph[start][i],st);
        }
    }
    st.push(start);
    return;
}
void dfs2(vector<vector<ll> >&graphT,vector<bool>&visited,ll start, unordered_set<ll>* comp)
{
    visited[start]=true;
    comp->insert(start);
    FOR(i,0,graphT[start].size())
    {
        if(!visited[graphT[start][i]])
        {
            dfs2(graphT,visited,graphT[start][i],comp);
        }
    }
    return;
}
unordered_set<unordered_set<ll>* >* getSCC(vector<vector<ll> >&graph,vector<vector<ll> >&graphT,ll n)
{
    vector<bool>visited(n,false);
    stack<ll>st;
    FOR(i,0,n)
    {
        if(!visited[i])
        {
            dfs(graph,visited,i,st);
        }
    }
    unordered_set<unordered_set<ll>* >* scc=new unordered_set<unordered_set<ll>*>();
    visited=vector<bool>(n,false);
    while(!st.empty())
    {
        ll k=st.top();
        st.pop();
        if(!visited[k])
        {
            unordered_set<ll>* comp=new unordered_set<ll>();
            dfs2(graphT,visited,k,comp);
            scc->insert(comp);
        }
    }
    return scc;

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
        vector<vector<ll> >graph(n,vector<ll>());
        vector<vector<ll> >graphT(n,vector<ll>());
        vector<ll>prices(n,0);
        FOR(i,0,n)
        {
            cin>>prices[i];
        }
        FOR(i,0,m)
        {
            ll u,v;
            cin>>u>>v;
            graph[u].pb(v);
            graphT[v].pb(u);
        }
        unordered_set<unordered_set<ll>* >*scc=getSCC(graph,graphT,n);
        unordered_set<unordered_set<ll>* >::iterator it1=scc->begin();
        ll ma=-INT_MAX;
        while(it1!=scc->end())
        {
            unordered_set<ll>::iterator it2=(*it1)->begin();
            ll cur=0;
            while((it2)!=(*it1)->end())
            {
                cur+=(prices[(*it2)]);
                it2++;
            }
            if(cur>ma)
            {
                ma=cur;
            }
            it1++;
        }
        cout<<ma<<"\n";
    }
    return 0;
}