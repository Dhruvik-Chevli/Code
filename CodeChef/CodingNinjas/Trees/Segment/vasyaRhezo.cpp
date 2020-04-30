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
struct warrior {
    int a;
    int b;
    int ind;
};
void buildTree(vector<warrior>&v,vector<warrior>&tree,ll start,ll end,ll treeNode)
{
    if(start==end)
    {
        tree[treeNode].a=v[start].a;
        tree[treeNode].b=v[start].b;
        tree[treeNode].ind=v[start].ind;
        return;
    }
    ll mid=(start+end)/2;
    buildTree(v,tree,start,mid,2*treeNode);
    buildTree(v,tree,mid+1,end,2*treeNode+1);
    if(tree[2*treeNode].a>tree[2*treeNode+1].a)
    {
            tree[treeNode].a=tree[2*treeNode].a;
            tree[treeNode].b=tree[2*treeNode].b;
            tree[treeNode].ind=tree[2*treeNode].ind;
    }
    else if(tree[2*treeNode].a==tree[2*treeNode+1].a)
    {
        if(tree[2*treeNode].b<=tree[2*treeNode+1].b)
        {
            tree[treeNode].a=tree[2*treeNode].a;
            tree[treeNode].b=tree[2*treeNode].b;
            tree[treeNode].ind=tree[2*treeNode].ind;
        }
        else
        {
            tree[treeNode].a=tree[2*treeNode+1].a;
            tree[treeNode].b=tree[2*treeNode+1].b;
            tree[treeNode].ind=tree[2*treeNode+1].ind;
        }
        
    }
    else
    {
        tree[treeNode].a=tree[2*treeNode+1].a;
        tree[treeNode].b=tree[2*treeNode+1].b;
        tree[treeNode].ind=tree[2*treeNode+1].ind;
    }
    return;
}

warrior query(vector<warrior>tree,ll start, ll end, ll treeNode, ll l,ll r)
{
    //cout<<start<<" "<<end<<" "<<l<<" "<<r<<endl;
    if(start>r||end<l)
    {
        warrior w;
        w.a=-1;
        w.b=1000;
        w.ind=-1;
        return w;
    }
    if(start>=l and end<=r)
    {
        warrior w=tree[treeNode];
        return w;
    }
    ll mid=(start+end)/2;
    warrior w1=query(tree,start,mid,2*treeNode,l,r);
    warrior w2=query(tree,mid+1,end,2*treeNode+1,l,r);
    if(w1.a>w2.a)
    {
            return w1;
    }
    else if(w1.a==w2.a)
    {
        if(w1.b<=w2.b)
            return w1;
        
        else
        {
            return w2;
        }
    }
    else
    {
        return w2;
    }
    
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<warrior>v(n);
    FOR(i,0,n)
    {
        ll a;
        cin>>a;
        v[i].a=a;
        v[i].ind=i+1;
    }
    FOR(i,0,n)
    {
        ll b;
        cin>>b;
        v[i].b=b;
    }
    vector<warrior>tree(4*n);
    buildTree(v,tree,0,n-1,1);
    // FOR(i,0,4*n)
    // {
    //     cout<<tree[i].a<<" "<<tree[i].b<<" "<<tree[i].ind<<" "<<i<<endl;
    // }
    // cout<<endl;
    ll m;
    cin>>m;
    FOR(i,0,m)
    {
        ll l,r;
        cin>>l>>r;
        warrior ans=query(tree,0,n-1,1,l-1,r-1);
        cout<<ans.ind<<endl;
    }
    return 0;
}