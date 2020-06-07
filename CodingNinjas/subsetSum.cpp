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
bool subsetSum(int n,vector<int>&set,int s)
{
    vector<bool>dp(s+1,false);
    dp[0]=true;
    FOR(i,0,n)
    {
        for(int j=s;j>=0;j--)
        {
            if(j>=set[i])
            {
                if(dp[j-set[i]]==true)
                {
                    dp[j]=true;
                }
            }
        }
    }
    return dp[s];
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>set(n,0);
    FOR(i,0,n)
    {
        cin>>set[i];
    }
    int s;
    cin>>s;
    if(subsetSum(n,set,s))
    {
        cout<<"Yes"<<endl;
    }
    else 
        cout<<"No"<<endl;

    return 0;
}