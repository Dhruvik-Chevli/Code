#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<unordered_map>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
ll coinChange(ll m,vector<ll>&coins,ll n)
{
    /*FOR(i,0,m)
    {
        cout<<coins[i]<<" ";
    }
    cout<<endl;*/
    ll dp[n+1][m];
    FOR(i,0,m)
    {
        dp[0][i]=1;
    }
    FOR(i,1,n+1)
    {
        FOR(j,0,m)
        {
            if(i-coins[j]>=0)
                dp[i][j]=dp[i-coins[j]][j];
            else
            {
                dp[i][j]=0;
            }
            if(j-1>=0)
                dp[i][j]+=dp[i][j-1];
            else
            {
                dp[i][j]+=0;
            }
        }
    }
    /*FOR(i,0,n+1)
    {
        FOR(j,0,m)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return dp[n][m-1];
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m;
    cin>>m;
    vector<ll>coins(m);
    FOR(i,0,m)
    {
        cin>>coins[i];
    }
    ll n;
    cin>>n;
    cout<<coinChange(m,coins,n)<<endl;
    return 0;
}