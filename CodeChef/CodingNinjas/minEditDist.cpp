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
ll minEditDist(string a,string b)
{
    ll n=a.length();
    ll m=b.length();
    vector<vector<ll> >dp(n+1,vector<ll>(m+1,0));
    FOR(i,0,n+1)
    {
        dp[i][0]=i;
    }
    FOR(i,0,m+1)
    {
        dp[0][i]=i;
    }
    FOR(i,1,n+1)
    {
        FOR(j,1,m+1)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
            }
        }
    }
    return dp[n][m];
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    string b;
    cin>>a>>b;
    cout<<minEditDist(a,b)<<endl;
    return 0;
}