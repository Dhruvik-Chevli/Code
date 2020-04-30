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
void combine(ll tree[],ll tn)
{
    ll tree[tn]=tree[2*tn]+tree[2*tn+1];
    return;
}
void buildTree(string s,ll tree[],ll tl,ll tr,ll tn)
{
    if(tl==tr)
    {
        if(s[tl]=='1')
        {
            tree[tn]=1;
        }
        return;
    }
    ll tm=(tl+tr)/2;
    buildTree(s,tree,tl,tm,2*tn);
    buildTree(s,tree,tm+1,tr,2*tn+1);
    combine(tree,tn);
    return;
}
void update(ll tree[],char lazy[],ll tl,ll tr,ll l,ll r,ll tn,char c)
{
    if(l>r)
    {
        return;
    }
    if(l==tl and r==tr)
    {
        if(c=='F')
        {
            tree[tn]=tr-tl+1;
            lazy[tn]='F';
        }
        else if(c=='E')
        {
            tree[tn]=0;
            lazy[tn]='E';
        }
        else
        {
            tree[tn]=tr-tl+1-tree[tn];
            lazy[tn]=
        }
        
    }
}
void update()
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll m;
        cin>>m;
        string pir="";
        FOR(i,0,m)
        {
            ll u;
            cin>>u;
            string b;
            cin>>b;
            FOR(j,0,u)
            {
                pir+=b;
            }
        }
        ll n=pir.size();
        ll q;
        cin>>q;
        char tree[4*n];
        buildTree(pir,tree,0,n-1,1);
        ll lazy[4*n];
        FOR(i,0,q)
        {

        }
    }
    return 0;
}