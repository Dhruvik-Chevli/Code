#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
void buildTree(vector<ll>&tree,vector<ll>&v,ll low, ll high,ll treeNode)
{
    if(low==high)
    {
        tree[treeNode]=(v[low]%2);
        return;
    }
    ll mid=(low+high)/2;
    buildTree(tree,v,low,mid,2*treeNode);
    buildTree(tree,v,mid+1,high,2*treeNode+1);
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
    return;
}
void update(vector<ll>&tree,vector<ll>&v,ll low, ll high,ll treeNode,ll val,ll idx)
{
    if(high==low)
    {
        v[idx]=val;
        tree[treeNode]=(val%2);
        return;
    }
    ll mid=(high+low)/2;
    if(idx>mid)
    {
        update(tree,v,mid+1,high,2*treeNode+1,val,idx);
    }
    else
    {
        update(tree,v,low,mid,2*treeNode,val,idx);
    }
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
    return;
}
int query(vector<ll>&tree,ll low,ll high,ll treeNode,ll l,ll r)
{
    if(r<low || l>high)
    {
        return 0;
    }
    else if(low>=l and high<=r)
    {
        return tree[treeNode];
    }
    ll mid=(high+low)/2;
    ll ans1=query(tree,low,mid,2*treeNode,l,r);
    ll ans2=query(tree,mid+1,high,2*treeNode+1,l,r);
    return ans1+ans2;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll>v(n,0);
    FOR(i,0,n)
    {
        cin>>v[i];
    }
    vector<ll>tree(4*n,0);
    buildTree(tree,v,0,n-1,1);
    ll q;
    cin>>q;
    FOR(i,0,q)
    {
        ll a,x,y;
        cin>>a>>x>>y;
        if(a==0)
        {
            update(tree,v,0,n-1,1,y,x-1);
        }
        else if(a==1)
        {
            ll ans=query(tree,0,n-1,1,x-1,y-1);
            //cout<<ans<<endl;
            cout<<(y-x+1)-ans<<endl;
        }
        else
        {
            ll ans=query(tree,0,n-1,1,x-1,y-1);
            cout<<ans<<endl;
        }
    }
    return 0;
}