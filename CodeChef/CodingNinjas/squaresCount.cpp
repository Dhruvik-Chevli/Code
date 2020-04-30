#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_map>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
//#define FOR(i,a,b,'-1') for(ll i=a;i>b;i--)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
int minCount(int n)
{
    vector<int>dp(n+1);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    FOR(i,4,n+1)
    {
        dp[i]=i;
        FOR(j,1,ceil(sqrt(i))+1)
        {
            if(j*j>i)
                break;
            else
            {
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
            
        }
    }
    return dp[n];
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<minCount(n)<<"\n";
    return 0;
}