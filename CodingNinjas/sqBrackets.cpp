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
int solve(int o,int c,int tot,vector<bool>pos,vector<vector<int> >&dp)
{
    if(o>tot || c>tot)
        return 0;
    if(dp[o][c]!=0)
    {
        return dp[o][c];
    }
    if(o==tot && c==tot)
    {
        return dp[o][c]=1;
    }
    if(o==c || pos[o+c])
    {
        return dp[o][c]=solve(o+1,c,tot,pos,dp);
    }
    else if(o==tot)
    {
        return dp[o][c]=solve(o,c+1,tot,pos,dp);
    }
    else
    {
        return dp[o][c]=solve(o+1,c,tot,pos,dp)+solve(o,c+1,tot,pos,dp);
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    vector<vector<int> >dp(20,vector<int>(20,0));
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int g;
        vector<bool>pos(38,false);
        FOR(i,0,k)
        {
            cin>>g;
            pos[g-1]=true;
        }
        //vector<vector<int> >dp(n+1,vector<int>(n+1,0));
        cout<<solve(0,0,n,pos,dp)<<endl;
    }
    return 0;
}