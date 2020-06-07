#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
ll kadanesAlgorithm(vector<ll>&dp)
{
    ll n=dp.size();
    ll max=0;
    ll curmax=0;
    FOR(i,0,n)
    {
        curmax+=dp[i];
        if(max<curmax)
        {
            max=curmax;
        }
        if(curmax<0)
        {
            curmax=0;
        }
    }
    return max;
}
ll maxSumRectangle(ll n,ll m,ll** arr)
{
    ll max=0;
    //cout<<"*";
    FOR(l,0,m)
    {
        vector<ll>dp(n,0);
        FOR(r,l,m)
        {
            FOR(ind,0,n)
            {
                dp[ind]=dp[ind]+arr[ind][r];
            }
            ll maxHere=kadanesAlgorithm(dp);
            if(maxHere>max)
            {
                max=maxHere;
            }
        }
    }
    return max;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll** arr=new ll*[n];
    FOR(i,0,n)
    {
        arr[i]=new ll[m];
    }
    FOR(i,0,n)
        FOR(j,0,m)
            cin>>arr[i][j];
    // FOR(i,0,n)
    //     FOR(j,0,m)
    //         cout<<arr[i][j];
    cout<<maxSumRectangle(n,m,arr)<<"\n";
    return 0;
}