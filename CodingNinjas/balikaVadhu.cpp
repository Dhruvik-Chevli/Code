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
int balikaVadhu(string a, string b, int x)
{
    int dp[a.length()+1][b.length()+1][x+1];
    FOR(i,0,a.length()+1)
    {
        FOR(j,0,b.length()+1)
        {
            FOR(k,0,x+1)
            {
                if(k==0)
                    dp[i][j][k]=0;
                else
                {
                    dp[i][j][k]=-INT_MAX;
                }
                
            }
        }
    }
    FOR(i,1,a.length()+1)
    {
        FOR(j,1,b.length()+1)
        {
            FOR(k,1,x+1)
            {
                if(a[i]!=b[j])
                {
                    dp[i][j][k]=max(dp[i-1][j][k],dp[i][j-1][k]);
                }
                else
                {
                    int ans=(dp[i-1][j-1][k-1]<0)?-1:(dp[i-1][j-1][k-1]+a[i-1]);
                    dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],ans));
                }
            }
        }
    }
    // FOR(i,0,a.length()+1)
    // {
    //     FOR(j,0,b.length()+1)
    //     {
    //         FOR(k,0,x+1)
    //         {
    //             cout<<dp[i][j][k]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }
    if(dp[a.size()][b.size()][x]<0)
        return 0;
    return dp[a.size()][b.size()][x];
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        int k;
        cin>>k;
        cout<<balikaVadhu(a,b,k)<<endl;
    }
    return 0;
}