#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;
void solve() {
	long long n,a,b,c;
	cin>>n>>a>>b>>c;
	long long dp[n+1];
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	for(long long i=0;i<=n;i++)
	{
		if(dp[i]!=-1){
		if(i+a<=n)
		{
			dp[i+a]=max(dp[i]+1,dp[i+a]);
		}
		if(i+b<=n)
		{
			dp[i+b]=max(dp[i]+1,dp[i+b]);
		}
		if(i+c<=n)
		{
			dp[i+c]=max(dp[i]+1,dp[i+c]);
		}
		}
	}
	cout<<dp[n]<<"\n";
	return;
}

int main() {
	long long t;
	t=1;
	while(t--)
	{
		solve();
	}
}