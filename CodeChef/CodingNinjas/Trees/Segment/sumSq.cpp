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
struct tn
{
    ll ss;
    ll s;
};
struct ln
{
    ll val;
    ll type;
};
void buildTree(vector<tn>&tree,vector<ll>&v,ll sta,ll end,ll treeNode)
{
    if(sta==end)
    {
        tree[treeNode].ss=v[sta]*v[sta];
        tree[treeNode].s=v[sta];
        return;
    }
    ll mid=(sta+end)/2;
    buildTree(tree,v,sta,mid,2*treeNode);
    buildTree(tree,v,mid+1,end,2*treeNode+1);
    tree[treeNode].s=tree[2*treeNode].s+tree[2*treeNode+1].s;
    tree[treeNode].ss=tree[2*treeNode].ss+tree[treeNode*2+1].ss;
}
void updateLazy(vector<tn>&tree,vector<ln>&lazy,ll low,ll high,ll startR,ll endR,ll treeNode,ll type,ll no)
{
    cout<<low<<"&"<<high<<"&"<<startR<<"&"<<endR<<endl;
    if(low>high)
    {
        return;
    }
    if(lazy[treeNode].type!=0)
    {
        if(lazy[treeNode].type==1)
        {
            tree[treeNode].ss+=lazy[treeNode].val*lazy[treeNode].val*(high-low+1)+2*lazy[treeNode].val*tree[treeNode].s;
            tree[treeNode].s+=lazy[treeNode].val*(high-low+1);
            if(low!=high)
            {
                lazy[2*treeNode].val+=lazy[treeNode].val;
                lazy[2*treeNode].type=lazy[treeNode].type;
                lazy[2*treeNode+1].val+=lazy[treeNode].val;
                lazy[2*treeNode+1].type=lazy[treeNode].type;
            }
            lazy[treeNode].val=0;
            lazy[treeNode].type=0;
        }
        else
        {
            tree[treeNode].ss=(high-low+1)*lazy[treeNode].val*lazy[treeNode].val;
            tree[treeNode].s=(high-low+1)*lazy[treeNode].val;
            if(low!=high)
            {
                lazy[2*treeNode].val=lazy[treeNode].val;
                lazy[2*treeNode].type=lazy[treeNode].val;
                lazy[2*treeNode+1].val=lazy[treeNode].val;
                lazy[2*treeNode+1].type=lazy[treeNode].val;
            }
            lazy[treeNode].val=0;
            lazy[treeNode].type=0;
        }
    }
    if(startR>high||endR<low)
    {
        cout<<"*****"<<endl;
        return;
    }
    if(low>=startR && high<=endR)
    {
        if(type==1)
        {
            tree[treeNode].ss+=no*no*(high-low+1)+2*no*tree[treeNode].s;
            tree[treeNode].s+=no*(high-low+1);
            if(high!=low)
            {
                lazy[2*treeNode].val+=no;
                lazy[2*treeNode+1].val+=no;
                lazy[2*treeNode].type=1;
                lazy[2*treeNode+1].type=1;
            }
            return;
        }
        else
        {
            tree[treeNode].ss=no*no*(high-low+1);
            tree[treeNode].s=no*(high-low+1);
            if(high!=low)
            {
                lazy[2*treeNode].val=no;
                lazy[2*treeNode].type=2;
                lazy[2*treeNode+1].val=no;
                lazy[2*treeNode+1].type=2;
            }
            return;
        }
    }
    ll mid=(low+high)/2;
    cout<<"mid: "<<mid<<"\n";
    updateLazy(tree,lazy,low,mid,startR,endR,2*treeNode,type,no);
    updateLazy(tree,lazy,mid+1,high,startR,endR,2*treeNode+1,type,no);
    tree[treeNode].ss=tree[2*treeNode].ss+tree[2*treeNode+1].ss;
    tree[treeNode].s=tree[2*treeNode].s+tree[2*treeNode+1].s;
}

ll query(vector<tn>&tree,vector<ln>&lazy,ll low,ll high,ll startR,ll endR,ll treeNode)
{
    cout<<low<<"&"<<high<<"&"<<startR<<"&"<<endR<<" "<<treeNode<<endl;
    cout<<"Tree------"<<endl;
    FOR(j,0,tree.size())
    {
        cout<<tree[j].ss<<" "<<tree[j].s<<endl;
    }
    cout<<"Lazy---"<<endl;
    FOR(j,0,lazy.size())
    {
        cout<<lazy[j].val<<" "<<lazy[j].type<<endl;
    }
    if(lazy[treeNode].type!=0)
    {
        cout<<"Not Zero\n";
        if(lazy[treeNode].type==1)
        {
            cout<<"adding"<<endl;
            tree[treeNode].ss+=lazy[treeNode].val*lazy[treeNode].val*(high-low+1)+2*lazy[treeNode].val*tree[treeNode].s;
            tree[treeNode].s+=lazy[treeNode].val*(high-low+1);
            if(low!=high)
            {
                lazy[2*treeNode].val=lazy[treeNode].val;
                lazy[2*treeNode].type=lazy[treeNode].type;
                lazy[2*treeNode+1].val=lazy[treeNode].val;
                lazy[2*treeNode+1].type=lazy[treeNode].type;
            }
            lazy[treeNode].val=0;
            lazy[treeNode].type=0;
        }
        else
        {
            cout<<"set"<<endl;
            cout<<high<<"&"<<low<<endl;
            tree[treeNode].ss=(high-low+1)*lazy[treeNode].val*lazy[treeNode].val;
            tree[treeNode].s=(high-low+1)*lazy[treeNode].val;
            if(low!=high)
            {
                lazy[2*treeNode].val=lazy[treeNode].val;
                lazy[2*treeNode].type=lazy[treeNode].type;
                lazy[2*treeNode+1].val=lazy[treeNode].val;
                lazy[2*treeNode+1].type=lazy[treeNode].type;
            }
            lazy[treeNode].val=0;
            lazy[treeNode].type=0;
        }
    }
    if(low>endR|| high<startR)
    {
        cout<<"******"<<endl;
        return 0;
    }
    if(low>=startR && high<=endR)
    {
        return tree[treeNode].ss;
    }
    ll mid=(high+low)/2;
    ll ans1=query(tree,lazy,low,mid,startR,endR,2*treeNode);
    ll ans2=query(tree,lazy,mid+1,high,startR,endR,2*treeNode+1);
    tree[treeNode].ss=tree[2*treeNode].ss+tree[2*treeNode+1].ss;
    tree[treeNode].s=tree[2*treeNode].s+tree[2*treeNode+1].s;
    return ans1+ans2;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    int k=0;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        vector<ll>v(n);
        FOR(i,0,n)
        {
            cin>>v[i];
        }
        vector<tn>tree(4*n);
        buildTree(tree,v,0,n-1,1);
        cout<<"Tree------"<<endl;
        FOR(j,0,tree.size())
        {
            cout<<tree[j].ss<<" "<<tree[j].s<<endl;
        }

        vector<ln>lazy(4*n,ln());
        FOR(j,0,lazy.size())
        {
            cout<<lazy[j].val<<" "<<lazy[j].type<<endl;
        }
        cout<<"Case "<<(++k)<<":"<<endl;
        FOR(i,0,q)
        {
            ll a,start,end,x;
            cin>>a;
            if(a==2)
            {
                cin>>start>>end;
                ll ans=query(tree,lazy,0,n-1,start-1,end-1,1);
                cout<<"Tree------"<<endl;
                FOR(j,0,tree.size())
                {
                    cout<<tree[j].ss<<" "<<tree[j].s<<endl;
                }
                cout<<"Lazy-------"<<endl;
                FOR(j,0,lazy.size())
                {
                    cout<<lazy[j].val<<" "<<lazy[j].type<<endl;
                }
                cout<<ans<<endl;
            }
            else if(a==1)
            {
                cin>>start>>end>>x;
                updateLazy(tree,lazy,0,n-1,start-1,end-1,1,1,x);
                cout<<"Tree------"<<endl;
                FOR(j,0,tree.size())
                {
                    cout<<tree[j].ss<<" "<<tree[j].s<<endl;
                }
                cout<<"Lazy---"<<endl;
                FOR(j,0,lazy.size())
                {
                    cout<<lazy[j].val<<" "<<lazy[j].type<<endl;
                }
            }
            else
            {
                cin>>start>>end>>x;
                updateLazy(tree,lazy,0,n-1,start-1,end-1,1,2,x);
                cout<<"Tree------"<<endl;
                FOR(j,0,tree.size())
                {
                    cout<<tree[j].ss<<" "<<tree[j].s<<endl;
                }
                cout<<"Lazy---"<<endl;
                FOR(j,0,lazy.size())
                {
                    cout<<lazy[j].val<<" "<<lazy[j].type<<endl;
                }
            }
        }
    }
    return 0;
}