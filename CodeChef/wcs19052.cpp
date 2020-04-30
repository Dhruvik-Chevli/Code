#include<algorithm>
#include<iostream>
#include<vector>
typedef long long int ll;
using namespace std;
#define max 1e18;
ll findCost(ll n,ll m,ll k)
{
    ll ans=max;
    if (k==n*m)
        return 0;
    if (k>n*m)
        return max;
    for(ll r=0;r<=m;r++)     
    for(ll i=1;i<=n;i++)
        for(ll j=0;j<=k;j++)
        {
            ans=min(ans,findCost(i,r,j)+findCost(n-i,r,k-j)+r*r);
            cout<<i<<" "<<j<<" "<<n<<" "<<m<<" "<<ans<<endl;
        }
    for(ll r=0;r<=n;r++)    
    for(ll i=1;i<=m;i++)
        for(ll j=0;j<=k;j++)
        {
            cout<<ans<<endl;
            ans=min(ans,findCost(r,i,j)+findCost(r,m-i,k-j)+r*r);
        }
    return ans;                  
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        cout<<findCost(n,m,k)<<endl;
    }
}