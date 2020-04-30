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
ll vacation(vector<ll>&a,vector<ll>&b,vector<ll>&c,ll n)
{
    vector<vector<ll> >dp(3,vector<ll>(n+1,0));
    FOR(i,1,n+1)
    {
        dp[0][i]=max(dp[1][i-1],dp[2][i-1])+a[i];
        dp[1][i]=max(dp[0][i-1],dp[2][i-1])+b[i];
        dp[2][i]=max(dp[1][i-1],dp[0][i-1])+c[i];
    }
    return max(dp[0][n],max(dp[1][n],dp[2][n]));
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll>a(n+1,0);
    vector<ll>b(n+1,0);
    vector<ll>c(n+1,0);
    FOR(i,1,n+1)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    cout<<vacation(a,b,c,n)<<endl;
    return 0;
}