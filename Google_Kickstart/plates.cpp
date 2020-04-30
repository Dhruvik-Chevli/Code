// 1
// 2 4 5
// 10 10 100 30
// 80 50 10 50


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long int
#define FOR(i,a,b) for(ll i=a;i<b;i++)
ll plates(ll n,ll k,ll p,vector<vector<ll> >&stacks)
{
    vector<vector<ll> >dp(n+1,vector<ll>(p+1,0));
    /*FOR(i,0,n+1)
    {
        FOR(j,0,p+1)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    FOR(i,1,k+1)
    {
        dp[0][i]=stacks[0][i];
    }
    FOR(i,1,n)
    {
        FOR(j,0,p+1)
        {
            //cout<<")";
            FOR(x,0,min(j,k)+1)
            {
                //cout<<"i :"<<i<<" "<<"j :"<<j<<" "<<"x :"<<x<<" "<<"j-x: "<<j-x<<endl;
                dp[i][j]=max(dp[i][j],stacks[i-1][x]+dp[i-1][j-x]);
            }
        }
    }
    //cout<<"________________"<<endl;
    // FOR(i,0,n)
    // {
    //     FOR(j,0,p+1)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    // FOR(i,1,n)
    // {
    //     FOR(j,0,p+1)
    //     {
    //         dp[i][j]=0;
    //         FOR(x,0,min(j,k)+1)
    //         {
    //             dp[i][j]=max(dp[i][j],stacks[i][x]+dp[i-1][j+x]);
    //             //cout<<"*";
    //         }
    //     }
    // }
    // FOR(i,0,n)
    // {
    //     FOR(j,0,p+1)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    // return dp[n-1][p];
    return dp[n][p];
}
int main()
{
    ll t;
    cin>>t;
    ll g=0;
    while(t--)
    {
        g++;
        ll n,k,p;
        cin>>n>>k>>p;
        vector<vector<ll> >stacks(n,vector<ll>(k+1,0));
        FOR(i,0,n)
        {
            ll sum=0;
            FOR(j,1,k+1)
            {
                ll u;
                cin>>u;
                sum+=u;
                stacks[i][j]=sum;
            }
        }
        /*FOR(i,0,n)
        {
            FOR(j,0,k+1)
            {
                cout<<stacks[i][j]<<" ";
            }
            cout<<endl;
        }*/
        cout<<"Case #"<<g<<": "<<plates(n,k,p,stacks)<<endl;
        
    }
    return 0;
}