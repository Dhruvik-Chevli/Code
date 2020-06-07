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
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll m;
    cin>>n>>m;
    vector<ll>sta(n+1,0);
    vector<ll>end(n+1,0);
    FOR(i,0,m)
    {
        ll l,r;
        cin>>l>>r;
        sta[l]+=1;
        end[r]+=1;
    }
    vector<ll>cnt(n+1,0);
    cnt[0]=0;
    cnt[1]=sta[1];
    FOR(i,2,n+1)
    {
        cnt[i]=sta[i]+cnt[i-1]-end[i-1];
    }
    vector<ll>ans(n+1,0);
    FOR(i,0,n+1)
    {
        ans[cnt[i]]+=1;
    }
    vector<ll>final(n+1,0);
    final[n]=ans[n];
    for(ll i=n-1;i>=0;i--)
    {
        final[i]=final[i+1]+ans[i];
    }
    cin>>m;
    FOR(i,0,m)
    {
        ll F;
        cin>>F;
        cout<<final[F]<<"\n";
    }
    return 0;
}