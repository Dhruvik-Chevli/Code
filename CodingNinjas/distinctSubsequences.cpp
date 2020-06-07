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
int distSS(string a)
{
    int n=a.length();
    vector<ll>dp(n+1,0);
    vector<int>last(26,-1);
    dp[0]=1;
    FOR(i,1,n+1)
    {
        dp[i]=2*dp[i-1];
        if(last[a[i-1]-65]!=-1)
        {
            dp[i]-=dp[last[a[i-1]-65]];
        }
        last[a[i-1]-65]=i-1;
    }
    // FOR(i,0,n+1)
    // {
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    int ans=(int)(dp[n]%MOD)
    return ans;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        cin>>a;
        cout<<distSS(a)<<endl;
    }
    return 0;
}