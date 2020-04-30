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
int dp[10001][10001/2];
int n;
int arr[2][10001];
int pilots(int a,int c,int cur)
{
    if(dp[cur][a]!=0)
        return dp[cur][a];
    if(a==n/2)
    {
        int ans=0,x=cur;
        while(x<=n)
        {
            ans+=arr[0][x];
            x++;
        }
        dp[cur][a]=ans;
        return ans;
    }
    if(a==c)
    {
        return dp[cur][a]=arr[1][cur]+pilots(a+1,c,cur+1);
    }
    else if(a>c)
    {
        return dp[cur][a]=min(arr[1][cur]+pilots(a+1,c,cur+1),arr[0][cur]+pilots(a,c+1,cur+1));
    }
    else return 0;

}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int n;
    cin>>n;
    //int arr[2][10001];
    FOR(i,0,n)
    {
        cin>>arr[0][i]>>arr[1][i];
    }
    //int dp[10001][10001/2];
    cout<<pilots(0,0,0)<<endl;
    return 0;
}