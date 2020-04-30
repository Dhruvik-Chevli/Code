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
int mincostTickets(vector<int>&days,vector<int>&costs)
{
    vector<int>day(366,0);
    FOR(i,0,days.size())
    {
        day[days[i]]=1;
    }
    vector<int>dp(366,0);
    FOR(i,1,366)
    {
        if(day[i]!=1)
        {
            dp[i]=dp[i-1];
        }
        else
        {
            int ans1=(i-1>=0)?dp[i-1]+costs[0]:0;
            int ans2=(i-7>=0)?dp[i-7]+costs[1]:costs[1];
            int ans3=(i-30>=0)?dp[i-30]+costs[2]:costs[2];
            dp[i]=min(ans1,min(ans2,ans3));
        }
        
    }
    return dp[365];
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<int>days(n);
    FOR(i,0,n)
    {
        cin>>days[i];
    }
    // ll m;
    // cin>>m;
    vector<int>costs(3);
    FOR(i,0,3)
    {
        cin>>costs[i];
    }
    cout<<mincostTickets(days,costs)<<endl;
    return 0;
}