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
ll minCoins(ll n,ll m,vector<ll>&coins)
{
    vector<vector<ll> >dp(n,vector<ll>(m+1,1e9));
    FOR(i,0,n)
    {
        dp[i][0]=0;
    }
    FOR(i,0,n)
    {
        FOR(j,1,m+1)
        {
            if(i==0)
            {
                if(j-coins[i]>=0)
                {
                    dp[i][j]=dp[i][j-coins[i]]+1;
                }
                
            }
            else
            {
                if(j-coins[i]>=0)
                {
                    dp[i][j]=min(dp[i][j-coins[i]]+1,dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
                
            }   
        }
    }
    return dp[n-1][m];
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<ll>denom(n);
    FOR(i,0,n)
    {
        cin>>denom[i];
    }
    cout<<minCoins(n,m,denom)<<endl;
    return 0;
}