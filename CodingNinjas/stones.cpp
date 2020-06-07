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
void stones(ll n,ll k,vector<ll>&arr)
{
    vector<ll>dp(k+1,0);
    FOR(i,0,k+1)
    {
        FOR(j,0,n)
        {
            if(i-arr[j]>=0)
            dp[i]=dp[i]|!dp[i-arr[j]];
        }
    }
    /*FOR(i,0,n)
    {
        FOR(j,0,k+1)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    if(dp[k])
    {
        cout<<"First"<<endl;
    }
    else
    {
        cout<<"Second"<<endl;
    }
    return;

}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n,0);
    FOR(i,0,n)
    {
        cin>>a[i];
    }
    stones(n,k,a);
    return 0;
}