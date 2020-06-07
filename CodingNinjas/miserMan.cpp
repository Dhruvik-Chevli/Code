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
#define INTMAX 99999
int miserMan(int n,int m,vector<vector<int> >&bus)
{
    vector<vector<int> >dp(n,vector<int>(m,0));
    FOR(i,0,m)
    {
        dp[0][i]=bus[0][i];
    }
    // cout<<"____________"<<endl;
    // FOR(i,0,n)
    // {
    //     FOR(j,0,m)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"%%%%%%%%%%%%%%%%%%"<<endl;
    FOR(i,1,n)
    {
        FOR(j,0,m)
        {
            int ans1=(j-1>=0)?dp[i-1][j-1]:INTMAX;
            int ans2=dp[i-1][j];
            int ans3=(j+1<m)?dp[i-1][j+1]:INTMAX;
            // cout<<"Printing " <<i<<" "<<j<<" "<<bus[i][j]<<" "<<ans1<<" "<<ans2<<" "<<ans3<<" ";
            dp[i][j]=min(ans1,min(ans2,ans3))+bus[i][j];
            // cout<<dp[i][j]<<endl;
        }
    }
    // FOR(i,0,n)
    // {
    //     FOR(j,0,m)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int mi=INT_MAX;
    FOR(i,0,m)
    {
        if(dp[n-1][i]<mi)
            mi=dp[n-1][i];
    }
    return mi;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int> >bus(n,vector<int>(m,0));
    FOR(i,0,n)
    {
        FOR(j,0,m)
        {
            cin>>bus[i][j];
        }
    }
    cout<<miserMan(n,m,bus)<<endl;
    return 0;
}