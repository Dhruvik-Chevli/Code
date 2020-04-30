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
void maxFun(int n,vector<int>&entry,vector<int>&fun,int bud)
{
    vector<int>dp(bud+1,0);
    FOR(i,0,n)
    {
        for(int j=bud;j>=0;j--)
        {
            if(j-entry[i]>=0)
            {
                dp[j]=max(dp[j],fun[i]+dp[j-entry[i]]);
            }
        }
    }
    int i;
    for(i=bud-1;i>=0;i--)
    {
        if(dp[i]!=dp[i+1])
            break;
    }
    cout<<i+1<<" "<<dp[bud]<<endl;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1)
    {
        int n;
        int bud;
        cin>>bud>>n;
        if(bud==0 && n==0)
            break;
        vector<int>entry(n,0);
        vector<int>fun(n,0);
        FOR(i,0,n)
        {
            cin>>entry[i]>>fun[i];
        }
        maxFun(n,entry,fun,bud);
    }
    return 0;
}