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
int minCostPath(int n,int** arr)
{
    int dp[n][n];
    dp[0][0]=arr[0][0];
    FOR(i,1,n)
    {
        dp[0][i]=dp[0][i-1]+arr[0][i];
        dp[i][0]=dp[i-1][0]+arr[i][0];
    }
    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            dp[i][j]=arr[i][j]+min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j-1]));
        }
    }
    return dp[n-1][n-1];
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int** arr=new int*[n];
    FOR(i,0,n)
    {
        arr[i]=new int[n];
    }
    /*FOR(i,0,n)
        FOR(j,0,n)
            cin>>arr[i][j];
    */
   FOR(i,0,n)
   FOR(j,0,n)
   {
       cin>>arr[i][j];
   }
    cout<<minCostPath(n,arr)<<endl;
    return 0;
}