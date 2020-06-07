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
void updateLazy(vector<int>&lazy,vector<int>&tree,int low,int high,int startR,int endR,int treeNode,int inc)
{
    if(low>high)
    {
        return;
    }
    if(lazy[treeNode]!=0)
    {
        tree[treeNode]+=lazy[treeNode];
        if(low!=high)
        {
            lazy[2*treeNode]=lazy[treeNode];
            lazy[2*treeNode+1]=lazy[treeNode];
        }
        lazy[treeNode]=0;
    }
    //No overlap
    if(startR>high || endR>low)
    {
        return;
    }
    //Complete Overlap
    if(low>=startR && high<=endR)
    {
        tree[treeNode]+=inc;
        if(low!=high)
        {
            lazy[2*treeNode]+=inc;
            lazy[2*treeNode+1]+=inc;
        }
        return;
    }
    int mid=(low+high)/2;
    updateLazy(lazy,tree,low,mid,startR,endR,2*treeNode,inc);
    updateLazy(lazy,tree,mid+1,end,startR,endR,2*treeNode+1,inc);
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);

}
void buildTree(vector<int>&v,vector<int>&tree,int start,int end,int treeNode)
{
    if(start==end)
    {
        tree[treeNode]=v[start];
        return;
    }
    int mid=(start+end)/2;
    buildTree(v,tree,start,mid,2*treeNode);
    buildTree(v,tree,mid+1,end,2*treeNode+1);
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
}
void update(vector<int>&v,vector<int>&tree,int start,int end,int treeNode,int index,int value)
{
    if(start==end)
    {
        v[index]=value;
        tree[treeNode]=value;
        return;
    }
    int mid=(start+end)/2;
    if(index>mid)
    {
        update(v,tree,mid+1,end,2*treeNode+1,index,value);
    }
    else
    {
        update(v,tree,start,mid,2*treeNode,index,value);
    }
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
}
int query(vector<int>&tree,int start,int end,int treeNode,int l,int r)
{
    if(start>r||end<l)
    {
        return 1000000000;
    }
    if(start>=l&&end<=r)
    {
        return tree[treeNode];
    }
    int mid=(start+end)/2;
    return min(query(tree,start,mid,2*treeNode,l,r),query(tree,mid+1,end,2*treeNode+1,l,r));
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int>v(n);
    vector<int>tree(4*n,0);
    FOR(i,0,n)
    {
        cin>>v[i];
    }
    buildTree(v,tree,0,n-1,1);
    // FOR(i,0,4*n)
    // {
    //     cout<<tree[i]<<" ";
    // }
    // cout<<endl;
    FOR(i,0,q)
    {
        char k;int l,r;
        cin>>k>>l>>r;
        if(k=='q')
        {
            cout<<query(tree,0,n-1,1,l-1,r-1)<<endl;
        }
        if(k=='u')
        {
            update(v,tree,0,n-1,1,l-1,r);
        }
    }
    return 0;
}