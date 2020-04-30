#include<algorithm>
#include<vector>
#include<iostream>
#define ll long long int
#define FOR(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
ll longestBitonicSubsequence(vector<ll>&v)
{
    vector<ll>lis(v.size());
    vector<ll>lds(v.size());
    lis[0]=1;
    lds[0]=1;
    FOR(i,1,v.size())
    {
        lis[i]=1;
        lds[i]=1;
        FOR(j,0,i)
        {
            if(v[j]>=v[i])
            {
                ll curmax=lds[j]+1;
                if(curmax>lds[i])
                {
                    lds[i]=curmax;
                }
            }
            else if(v[j]<v[i])
            {
                ll curmax=lis[j]+1;
                if(curmax>lis[i])
                    lis[i]=curmax;
            }
        }
    }
    ll max=lis[0]+lds[0]-1;
    /*FOR(i,0,v.size())
    {
        cout<<lis[i]<<" ";
    }
    cout<<endl;
    FOR(i,0,v.size())
    {
        cout<<lds[i]<<" ";
    }
    cout<<endl;*/
    FOR(i,0,v.size())
    {
        if(max<(lis[i]+lds[i]-1))
            max=lis[i]+lds[i]-1;
    }
    return max;
}
int main()
{
    ll n;
    cin>>n;
    vector<ll>v(n,0);
    FOR(i,0,n)
    {
        cin>>v[i];
    }
    cout<<longestBitonicSubsequence(v)<<endl;
    return 0;
}