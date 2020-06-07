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
int countBST(int n)
{
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    //dp[2]=2;
    FOR(i,1,n+1)
    {
        dp[i]=0;
        FOR(j,1,(i+1))
        {
            dp[i]=(dp[i]+(dp[j-1]*dp[i-j])%MOD)%MOD;
        }
    }
    /*FOR(i,0,n+1)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;*/
    return dp[n];
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<countBST(n)<<endl;
    return 0;
}