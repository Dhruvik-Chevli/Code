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
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    FOR(i,0,n)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<ll>dp(n,0);
    dp[1]=arr[1]-arr[0];
    ll sum=arr[1]+arr[0];
    FOR(i,2,k)
    {
        dp[i]=dp[i-1]+(i)*arr[i]-sum;
        sum+=arr[i];
    }
    FOR(i,k,n)
    {
        dp[i]=dp[i-1]-2*(sum-arr[i-k])+(k-1)*arr[i-k]+(k-1)*arr[i];
        sum=sum-arr[i-k]+arr[i];
    }
    ll ans=1e9;
    FOR(i,k-1,n)
    {
        if(dp[i]<ans)
            ans=dp[i];
    }
    cout<<ans<<endl;
    return 0;
}