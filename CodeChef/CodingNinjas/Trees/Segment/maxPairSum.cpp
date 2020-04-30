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
void buildTree(vector<int>&v,vector<pair<int,int> >&tree,int start,int end,int treeNode)
{
    if(start==end)
    {
        tree[treeNode].first=v[start];
        return;
    }
    int mid=(start+end)/2;
    buildTree(v,tree,start,mid,2*treeNode);
    buildTree(v,tree,mid+1,end,2*treeNode+1);
    if(tree[2*treeNode].first>=tree[2*treeNode+1].first)
    {
        tree[treeNode].first=tree[2*treeNode].first;
        if(tree[2*treeNode].second>=tree[2*treeNode+1].first)
        {
            tree[treeNode].second=tree[2*treeNode].second;
        }
        else
        {
            tree[treeNode].second=tree[2*treeNode+1].first;
        }
    }
    else
    {
        tree[treeNode].first=tree[2*treeNode+1].first;
        if(tree[2*treeNode+1].second>tree[2*treeNode].first)
        {
            tree[treeNode].second=tree[2*treeNode+1].second;
        }
        else
        {
            tree[treeNode].second=tree[2*treeNode].first;
        }
    }
}
void update(vector<int>&v,vector<pair<int,int> >&tree,int start,int end,int treeNode,int idx,int val)
{
    if(start==end)
    {
        v[idx]=val;
        tree[treeNode].first=val;
        return;
    }
    int mid=(start+end)/2;
    if(idx>mid)
    {
        update(v,tree,mid+1,end,2*treeNode+1,idx,val);
    }
    else
    {
        update(v,tree,start,mid,2*treeNode,idx,val);
    }
    if(tree[2*treeNode].first>=tree[2*treeNode+1].first)
    {
        tree[treeNode].first=tree[2*treeNode].first;
        if(tree[2*treeNode].second>=tree[2*treeNode+1].first)
        {
            tree[treeNode].second=tree[2*treeNode].second;
        }
        else
        {
            tree[treeNode].second=tree[2*treeNode+1].first;
        }
    }
    else
    {
        tree[treeNode].first=tree[2*treeNode+1].first;
        if(tree[2*treeNode+1].second>tree[2*treeNode].first)
        {
            tree[treeNode].second=tree[2*treeNode+1].second;
        }
        else
        {
            tree[treeNode].second=tree[2*treeNode].first;
        }
    }    
}
pair<int,int> query(vector<pair<int,int> >&tree,int start,int end,int treeNode,int l,int r)
{
    //cout<<start<<" "<<end<<" "<<treeNode<<" "<<l<<" "<<r<<endl;
    if(start>r||end<l)
    {
        return make_pair(0,0);
    }
    if(start>=l&&end<=r)
    {
        return make_pair(tree[treeNode].first,tree[treeNode].second);
        cout<<"*";
    }
    int mid=(start+end)/2;
    pair<int,int> ans1= query(tree,start,mid,2*treeNode,l,r);
    pair<int,int> ans2=query(tree,mid+1,end,2*treeNode+1,l,r);
    if(ans1.first>=ans2.first)
    {
        if(ans1.second>=ans2.first)
        {
            return ans1;
        }
        else
        {
            return make_pair(ans1.first,ans2.first);
        }
    }
    else
    {
        if(ans2.second>=ans1.first)
        {
            return ans2;
        }
        else
        {
            return make_pair(ans2.first,ans1.first);
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<int>v(n,0);
    FOR(i,0,n)
    {
        cin>>v[i];
    }
    vector<pair<int,int> >tree(4*n,make_pair(0,0));
    buildTree(v,tree,0,n-1,1);
    // FOR(i,0,4*n)
    // {
    //     cout<<tree[i].first<<" "<<tree[i].second<<endl;
    // }
    int q;
    cin>>q;
    FOR(i,0,q)
    {
        char k;int l,r;
        cin>>k>>l>>r;
        if(k=='U')
        {
            update(v,tree,0,n-1,1,l-1,r);
        }
        else
        {
            pair<int,int>ans=query(tree,0,n-1,1,l-1,r-1);
            cout<<ans.first+ans.second<<endl;
        }
    }
    return 0;
}