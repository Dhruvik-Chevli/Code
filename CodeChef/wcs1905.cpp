#include<algorithm>
#include<iostream>
#include<vector>
typedef long long int ll;
using namespace std;
int main()
{
    ll dp[35][35][55];
    ll max=1e9;
    for(ll i=1;i<35;i++)
    {
        for(ll j=1;j<35;j++)
        {
            for(ll k=1;k<55;k++)
            {
                dp[i][j][k]=max;
                if(k==i*j)
                {
                    dp[i][j][k]=0;
                    continue;
                }
                if(k>i*j)
                    continue;
                for(ll l=1;l<i;l++)
                {
                    for(ll r=0; r<=k;r++)
                    {
                        dp[i][j][k]=min(dp[i][j][k],dp[l][j][r]+dp[i-l][j][k-r]+j*j);
                    }
                }
                for(ll l=1;l<j;l++)
                {
                    for(ll r=0; r<=k;r++)
                    {
                        dp[i][j][k]=min(dp[i][j][k],dp[i][l][r]+dp[i][j-l][k-r]+i*i);
                    }
                }
            }
        }
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        cout<<dp[n][m][k]<<endl;
    }
    return 0;
}