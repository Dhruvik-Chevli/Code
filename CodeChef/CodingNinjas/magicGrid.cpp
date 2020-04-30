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
int magicGrid(int r,int c,int** s)
{
    if(r==2&&c==2)
    {
        if(s[0][0]>=0)
        {
            return 1;
        }
        else
        {
            return -(s[0][0]);
        }
        
    }
    int dp[r][c];
    FOR(i,0,r)
    FOR(j,0,c)
    dp[i][j]=0;
    dp[r-1][c-1]=1;
    dp[r-2][c-1]=1;
    dp[r-1][c-2]=1;
    for(int i=r-2;i>=0;i--)
    {
        dp[i][c-1]=dp[i+1][c-1]-s[i][c-1];
        if(dp[i][c-1]<0)
        {
            dp[i][c-1]=1;
        }
    }
    for(int j=c-2;j>=0;j--)
    {
        dp[r-1][j]=dp[r-1][j+1]-s[r-1][j];
        if(dp[r-1][j]<0)
            dp[r-1][j]=1;
    }
    for(int i=r-2;i>=0;i--)
    {
        for(int j=c-2;j>=0;j--)
        {
            dp[i][j]=min(dp[i][j+1]-s[i][j],dp[i+1][j]-s[i][j]);
            if(dp[i][j]<0)
                dp[i][j]=1;
        }
    }
    /*FOR(i,0,r)
    {
        FOR(j,0,c)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return dp[0][0];
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        int c,r;
        cin>>r>>c;
        int** s=new int*[r];
        FOR(i,0,r)
        {
            s[i]=new int[c];
        }
        FOR(i,0,r)
            FOR(j,0,c)
                cin>>s[i][j];
        cout<<magicGrid(r,c,s)<<endl;
    }
    return 0;
}