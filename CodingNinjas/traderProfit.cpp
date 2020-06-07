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
int traderProfit(int n,vector<int>price,int k)
{
    vector<vector<int> >dp(k+1,vector<int>(n,0));
    FOR(i,1,k+1)
    {
        FOR(j,0,n)
        {
            FOR(k,0,j)
            {
                dp[i][j]=max(dp[i][j],max((price[j]-price[k])+dp[i-1][k],dp[i][j-1]));
            }
        }
    }
    // FOR(i,0,k+1)
    // {
    //     FOR(j,0,n)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return dp[k][n-1];
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int k,n;
        cin>>k>>n;
        vector<int>price(n,0);
        FOR(i,0,n)
        {
            cin>>price[i];
        }
        cout<<traderProfit(n,price,k)<<endl;;
    }
    return 0;
}