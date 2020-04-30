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
struct Node
{
    ll maxPrefixSum;
    ll maxSuffixSum;
    ll totalSum;
    ll maxSum;
    Node()
    {
        maxPrefixSum=maxSuffixSum=totalSum=maxSum=-1000000000;
    }
};
Node merge(Node leftChild, Node rightChild) 
{ 
    Node parentNode; 
    parentNode.maxPrefixSum = max(leftChild.maxPrefixSum, 
                                  leftChild.totalSum +  
                                  rightChild.maxPrefixSum); 
   
    parentNode.maxSuffixSum = max(rightChild.maxSuffixSum, 
                                  rightChild.totalSum + 
                                  leftChild.maxSuffixSum); 
   
    parentNode.totalSum = leftChild.totalSum + 
                          rightChild.totalSum; 
   
    parentNode.maxSum = max(leftChild.maxSum,max( 
                                     rightChild.maxSum, 
                                     leftChild.maxSuffixSum +  
                                     rightChild.maxPrefixSum)); 
   
    return parentNode; 
} 
void buildTree(vector<Node>&tree,vector<ll>v,ll sta,ll end,ll treeNode)
{
    if(sta==end)
    {
        tree[treeNode].totalSum=v[sta];
        tree[treeNode].maxPrefixSum=v[sta];
        tree[treeNode].maxSuffixSum=v[sta];
        tree[treeNode].maxSum=v[sta];
        return;
    }
    ll mid=(sta+end)/2;
    buildTree(tree,v,sta,mid,2*treeNode);
    buildTree(tree,v,mid+1,end,2*treeNode+1);
    tree[treeNode]=merge(tree[2*treeNode],tree[2*treeNode+1]);
}
Node query(vector<Node>&tree,ll sta,ll end,ll treeNode,ll l,ll r)
{
    if(sta>r or end<l)
    {
        Node nullNode;
        return nullNode;
    }
    else if(sta>=l and end<=r)
    {
        return tree[treeNode];
    }
    ll mid=(sta+end)/2;
    Node left=query(tree,sta,mid,2*treeNode,l,r);
    Node right=query(tree,mid+1,end,2*treeNode+1,l,r);
    Node res=merge(left,right);
    return res;
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
    vector<Node>tree(4*n);
    buildTree(tree,v,0,n-1,1);
    ll m;
    cin>>m;
    FOR(i,0,m)
    {
        ll l,r;
        cin>>l>>r;
        Node ans=query(tree,0,n-1,1,l-1,r-1);
        cout<<ans.maxSum<<"\n";
    }
    return 0;
}