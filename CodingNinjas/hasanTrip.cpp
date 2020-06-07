#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<math.h>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll>x(n);
    vector<ll>y(n);
    vector<ll>f(n);
    FOR(i,0,n)
    {
        cin>>x[i]>>y[i]>>f[i];
    }
    vector<long double>dp(n);
    dp[0]=f[0];
    FOR(i,1,n)
    {
        dp[i]=-1e9;
        FOR(j,0,i)
        {
            dp[i]=max(dp[i],dp[j]-(long double)sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
        }
        dp[i]+=f[i];
    }
    /*FOR(i,0,n)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;*/
    cout<<fixed;
    cout.precision(6);
    cout<<dp[n-1]<<endl;
    return 0;
}