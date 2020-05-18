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
void dfs(vector<vector<ll> >&graph,vector<bool>&visited,ll start)
{
    visited[start]=true;
    FOR(i,0,graph[start].size())
    {
        if(!(visited[graph[start][i]]))
        {
            dfs(graph,visited,graph[start][i]);
        }
    }
    return;
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
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>x(n);
        vector<ll>y(n);
        vector<bool>cut(n,false);
        unordered_map<ll,ll>xm;
        unordered_map<ll,ll>ym;
        FOR(i,0,n)
        {
			ll cur=1;
            cin>>x[i]>>y[i];
			if(x[i]==y[i]) cur=2;
            if(xm.count(x[i])>0)
            {
                xm[x[i]]+=cur;
            }
            else
            {
                xm[x[i]]=cur;
                //xs.insert(x[i]);
            }
            if(ym.count(y[i])>0)
            {
                ym[y[i]]+=cur;
            }
            else
            {
                ym[y[i]]=cur;
                //ys.insert(y[i]);
            }
        }
        ll count=0;
        //unordered_map<ll,ll>::iterator it1=tot.begin();
        while(xm.size()|| ym.size())
        {
            unordered_map<ll,ll>::iterator it1;//=tot.begin();
            it1=xm.begin();
            ll ma=-1; ll k; ll f=0;
            for(;it1!=xm.end();it1++)
            {
                if((*it1).second>ma)
                {
                    ma=(*it1).second;
                    k=(*it1).first;
                }
            }
            it1=ym.begin();
            for(;it1!=ym.end();it1++)
            {
                if((*it1).second>ma)
                {
                    ma=(*it1).second;
                    f=1;
                    k=(*it1).first;
                }
            }
            // cout<<k;
            // cout<<"*";
            if(f==0){
                FOR(i,0,n)
                {
                    if(cut[i]==false)
                    {
						ll cur=1;
                        if(x[i]==k)
                        {
							if(y[i]==k) cur=2;
                            xm[x[i]]-=cur;
                            ym[y[i]]-=cur;
                            if(xm[x[i]]==0)
                            {
                                xm.erase(x[i]);
                            }
                            if(ym[y[i]]==0)
                            {
                                ym.erase(y[i]);
                            }
                            cut[i]=true;
                        }
                    }
                }
            }
            else{
                FOR(i,0,n)
                {
                    if(cut[i]==false)
                    {
						ll cur=1;
                        if(y[i]==k)
                        {
							if(x[i]==k) cur=2;
                            xm[x[i]]-=cur;
                            ym[y[i]]-=cur;
                            if(xm[x[i]]==0)
                            {
                                xm.erase(x[i]);
                            }
                            if(ym[y[i]]==0)
                            {
                                ym.erase(y[i]);
                            }
                            cut[i]=true;
                        }
                    }
                }

            }
            count+=1;
            //i++;
        }
        cout<<count<<"\n";

    }
    return 0;
}