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
void buildTree(vector<int>&v,vector<int>&tree,int start,int end ,int treeNode)
{
    int mid=(start+end)/2;
    if(start==end)
    {
        tree[treeNode]=v[start];
        return;
    }
    buildTree(v,tree,start,mid,2*treeNode);
    buildTree(v,tree,mid+1,end,2*treeNode+1);
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}
void update(vector<int>&v,vector<int>&tree,int start,int end,int treeNode,int index,int value)
{
    int mid=(start+end)/2;
    if(start==end)
    {
        v[index]=value;
        tree[treeNode]=value;
        return;
    }
    if(index>mid)
    {
        update(v,tree,mid+1,end,2*treeNode+1,index,value);
    }
    else
    {
        update(v,tree,start,mid,2*treeNode,index,value);
    }
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}
int query(vector<int>&tree,int start,int end,int treeNode,int l,int r)
{

    //Completerly outside given range
    if(start>r||l>end)
    {
        return 0;
    }
    //Completely inside given range
    if(start>=l && end<=r)
    {
        return tree[treeNode];
    }
    //partially inside and partially outside
    int mid=(start+end)/2;
    int ans1=query(tree,start,mid,2*treeNode,l,r);
    int ans2=query(tree,mid+1,end,2*treeNode+1,l,r);
    return ans1+ans2;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>v(n);
    FOR(i,0,n)
    {
        cin>>v[i];
    }
    vector<int>tree(2*n,0);
    buildTree(v,tree,0,n-1,1);
    update(v,tree,0,n-1,1,2,10);
    FOR(i,0,2*n)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    cout<<query(tree,0,n-1,1,2,4)<<endl;
    return 0;
}