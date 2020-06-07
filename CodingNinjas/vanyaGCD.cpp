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
ll gcd(ll n,ll m)
{
    if(n==0)
        return m;
    return gcd(m%n,n);
}
ll vanyaGCD(ll n, vector<ll>&arr)
{
    vector<vector<ll> >dp(n,vector<ll>(101,0));
    dp[0][arr[0]]=1;
    FOR(i,1,n)
    {
        //cout<<"i is "<<i<<" "<<arr[i]<<endl;
        dp[i][arr[i]]=1;
        FOR(j,0,i)
        {
            //cout<<j<<" "<<arr[j]<<endl;
            if(arr[j]<arr[i])
            {
                FOR(k,1,101)
                {
                    //ll g= __gcd
                    dp[i][ gcd(k,arr[i]) ]+=dp[j][k];
                }
            }
        }
    }
    // FOR(i,0,n)
    // {
    //     FOR(j,0,101)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    ll count=0;
    FOR(i,0,n)
    {
        count+=dp[i][1];
    }
    return count;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll>arr(n);
    FOR(i,0,n)
    {
        cin>>arr[i];
    }
    cout<<vanyaGCD(n,arr)<<endl;
    return 0;
}