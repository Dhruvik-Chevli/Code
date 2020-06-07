#include<algorithm>
#include<iostream>
#include<vector>
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define ll long long int;
using namespace std;
ll lis(vector<ll>&v)
{
    if(v.size()==0)
        return 0;
    vector<ll>ans(v.size(),0);
    ans[0]=1;
    FOR(i,1,v.size())
    {
        ans[i]=1;
        ll curmax=0;
        for(ll j=0;j<i;j++)
        {
            if(v[j]>=v[i])
            {
                continue;
            }
            ll curans=ans[j]+1;
            if(ans[i]<curans)
            {
                ans[i]=curans;
            }
        }
    }
    ll max=0;
    FOR(i,0,ans.size())
    {
        if(max<ans[i])
            max=ans[i];
    }
    return max;
    }
}
int main()
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    FOR(i,0,n)
    {
        cin>>v[i];
    }
    cout<<lis(v)<<endl;
    
}