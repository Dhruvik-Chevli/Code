#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_map>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
vector<ll> dfs(vector<vector<ll> > graph,ll sta, ll end,vector<ll>&path,vector<ll>vis)
{
    // cout<<"*";
    path.push_back(sta);
    if(sta==end)
    {
        return path;
    }
    vis[sta]=1;
    int flag=0;
    FOR(i,0,graph[sta].size())
    {
        if(vis[graph[sta][i]]!=1)
        {
            vector<ll>ans=dfs(graph,graph[sta][i],end,path,vis);
            flag=1;
            if(ans[ans.size()-1]==end)
            {
                return ans;
            }
            // else
            // {
            //     vis[graph[sta][i]]=0;
            // }
            
        }
    }
    // FOR(i,0,path.size())
    // {
    //     cout<<path[i]<<" ";
    // }
    // cout<<endl;
    if(flag==0)
    {
        path.pop_back();
    }
    return path;
    
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll>sieve(1000001,0);
    FOR(i,0,1000001)
    {
        sieve[i]=i;
    }
    for(int i=4;i<1000001;i+=2)
    {
        sieve[i]=2;
    }
    for(ll i=3;i<1000001;i++)
    {
        if(sieve[i]==i)
        {
            for(ll j=i*i;j<1000001;j+=i)
            {
                if(sieve[j]==j)
                {
                    sieve[j]=i;
                }
            }
        }
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<vector<ll> >graph(n+1,vector<ll>());
        FOR(i,0,n-1)
        {
            ll x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        vector<ll>prices(n+1);
        //vector<unordered_map<ll,ll> >primePrices(n+1,unordered_map<ll,ll>());
        FOR(i,1,n+1)
        {
             cin>>prices[i];
        }
        //     ll g=prices[i];
        //     while(sieve[g]!=1)
        //     {
        //         if(primePrices[i].count(sieve[g]))
        //         {
        //             primePrices[i][sieve[g]]+=1;
        //         }
        //         else
        //         {
        //             primePrices[i][sieve[g]]=1;
        //         }
        //         g/=sieve[g];
        //     }
        // }
        // FOR(i,1,n+1)
        // {
        //     cout<<i<<"-> ";
        //     FOR(j,0,graph[i].size())
        //     {
        //         cout<<graph[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        ll q;
        cin>>q;
        while(q--)
        {
            ll l,r;
            cin>>l>>r;
            vector<ll>path;
            vector<ll>vis(n+1,0);
            vector<ll>ans=dfs(graph,l,r,path,vis);
            unordered_map<ll,ll>counts;
            FOR(i,0,ans.size())
            {
                ll g=prices[ans[i]];
                FOR(i,1,n+1)
                {
                    while(g!=1)
                    {
                        if(counts.count(sieve[g]))
                        {
                            counts[sieve[g]]+=1;
                        }
                        else
                        {
                            counts[sieve[g]]=1;
                        }
                        g/=sieve[g];
                    }
                }
                
            }
            ll finalans=1;
            for(auto x:counts)
            {
                finalans=(finalans*(x.second+1))%MOD;
            }
            cout<<finalans<<"\n";
        }
    }
    return 0;
}