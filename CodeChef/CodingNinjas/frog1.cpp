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
ll frog1(ll n,ll k,vector<ll> &h)
{
    vector<ll>dp(n+1,1e9);
    dp[1]=0;
    dp[2]=abs(h[2]-h[1]);
    //dp[3]=
    FOR(i,3,n+1)
    {
        //dp[i]=1e9;
        FOR(j,1,k+1)
        {
            if(i-j<1)
            {
                break;
            }
            ll ans=dp[i-j]+abs(h[i]-h[i-j]);
            if(ans<dp[i])
                dp[i]=ans;
        }
        //cout<<i;
    }
    /*FOR(i,1,n+1)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;*/
    return dp[n];
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;//k;
    cin>>n;//>>k;
    vector<ll>h(n+1,0);
    FOR(i,1,n+1)
        cin>>h[i];
    cout<<frog1(n,2,h)<<endl;
    return 0;
}