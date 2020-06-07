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
int smallestSuperSequence(string s, int n,string t,int m)
{
    vector<vector<int> >dp(n+1,vector<int>(m+1,0));
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
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    FOR(i,0,n+1)
    {
        FOR(j,0,m+1)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][m];
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    cout<<smallestSuperSequence(s,s.length(),t,t.length())<<endl; 
    return 0;
}