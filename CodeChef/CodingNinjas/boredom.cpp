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
ll solve(ll n,vector<ll>&v)
{
    vector<ll>freq(1001,0);
    FOR(i,0,n)
    {
        freq[v[i]]+=1;
    }
    vector<ll>dp(10001);
    dp[0]=0;
    dp[1]=1*freq[1];
    FOR(i,2,10001)
    {
        dp[i]=max(dp[i-2]+i*freq[i],dp[i-1]);
    }
    return dp[1000];
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll>v(n);
    FOR(i,0,n)
        cin>>v[i];
    cout<<solve(n,v)<<endl;
    return 0;
}