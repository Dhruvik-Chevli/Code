#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cstring>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
ll spf[1000001];
#define MAXN 1000001
#include<unordered_map>
void sieve() 
{ 
    spf[1] = 1; 
    for (ll i=2; i<MAXN; i++) 
        spf[i] = i; 
    for (ll i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
    for (ll i=3; i*i<MAXN; i++) 
    {
        if (spf[i] == i) 
        {
            for (ll j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
void printPath(vector<ll> stack,vector<ll>prices) 
{ 
    unordered_map<ll,ll>primes;
    FOR(i,0,stack.size())
    {
        ll g=prices[stack[i]];
        while(g!=1)
        {
            if(primes.count(spf[g]))
            {
                primes[spf[g]]+=1;
            }
            else
            {
                primes[spf[g]]=1;
            }
            
            g/=spf[g];
        }
    }
    ll finalAns=1;
    for(auto x:primes)
    {
        finalAns=((finalAns*(x.second+1))%MOD);
    }
    cout << finalAns<<endl; 
} 
int DFS(vector<ll> v[], bool vis[], ll x, vector<ll> stack,vector<ll>prices) 
{ 
    stack.push_back(x); 
    if (x == y) { 
        printPath(stack,prices); 
        return 1; 
    } 
    vis[x] = true; 
    ll flag = 0; 
    if (!v[x].empty()) { 
        for (ll j = 0; j < v[x].size(); j++) { 
            if (vis[v[x][j]] == false) { 
                ll k=DFS(v, vis, v[x][j], y, stack,prices); 
                flag = 1;
                if(k)
                {
                    return 1;
                } 
            } 
        } 
    } 
    if (flag == 0) {
        stack.pop_back(); 
    } 
    return 0;
} 
void DFSCall(ll x, ll y, vector<ll> v[],ll n,vector<ll> stack,vector<ll>prices) 
{ 
    bool vis[n + 1]; 
  
    memset(vis, false, sizeof(vis)); 
  
    DFS(v, vis, x, y, stack,prices); 
} 
  
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>graph[n+1];
        FOR(i,0,n-1)
        {
            ll x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        vector<ll>prices(n+1);
        FOR(i,1,n+1)
        {
             cin>>prices[i];
        }
        // vector<pair<ll,ll> >primes;
        // FOR(i,0,1000001)
        // {
        //     primes.pb(make_pair(i,0));
        // }
        ll q;
        cin>>q;
        while(q--)
        {
            ll l,r;
            cin>>l>>r;
            vector<ll>stack;
            DFSCall(l,r,graph,n,stack,prices);
        }
    }
    return 0;
}