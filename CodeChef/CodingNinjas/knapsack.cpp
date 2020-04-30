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
ll knapsack(ll n, vector<ll>&val,vector<ll>&wt,ll mw)
{
    vector<vector<ll> > dp(n,vector<ll>(mw+1,0));
    FOR(j,1,mw+1)
    {
        dp[0][j]=(j-wt[0]-1>=0)?val[0]:0;
    }
    FOR(i,1,n)
    {
        FOR(j,1,mw+1)
        {
            dp[i][j]=(j-wt[i]>=0)?max(val[i]+dp[i-1][j-wt[i]],dp[i-1][j]):dp[i-1][j];
        }
    }
    return dp[n-1][mw];
    
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,mw;
    cin>>n>>mw;
    vector<ll>val(n);
    vector<ll>weight(n);
    FOR(i,0,n)
    {
        cin>>val[i]>>weight[i];
    }
    cout<<knapsack(n,val,weight,mw)<<endl;
    return 0;
}