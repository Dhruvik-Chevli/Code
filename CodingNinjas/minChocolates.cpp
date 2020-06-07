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
ll minChocolates(ll n,vector<ll>&stud)
{
    //int count=0;
    //sort(stud.begin(),stud.end());
    vector<ll>dp(n,1);
    dp[0]=1;
    FOR(i,1,n)
    {
        if(stud[i]>stud[i-1])
        {
            dp[i]=dp[i-1]+1;
            //count+=dp[i];
        }
        // else if(stud[i]==stud[i-1])
        // {
        //     dp[i]=dp[i-1];
        //     count+=dp[i];
        // }
        else
        {
            dp[i]=1;
            //count+=1;
        }    
    }
    for(int i=n-2;i>=0;i--)
    {
        if(stud[i]>stud[i+1] && dp[i]<=dp[i+1])
        {
            dp[i]=dp[i+1]+1;
        }
    }
    int count=0;
    FOR(i,0,n)
    {
        count+=dp[i];
    }
    return count;
    //return count+1;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll>stud(n);
    FOR(i,0,n)
        cin>>stud[i];
    cout<<minChocolates(n,stud)<<endl;
    return 0;
}