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
bool check(ll cows,ll pos[],ll n,ll dist)
{
    ll count=1;
    ll last_pos = pos[0];
    FOR(i,1,n)
    {
        if(pos[i]-last_pos>=dist)
        {
            last_pos=pos[i];
            count+=1;
        }
        if(count==cows)
            return true;
    }
    return false;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,c;
        cin>>n>>c;
        ll pos[n];
        FOR(i,0,n)
        {
            cin>>pos[i];
        }
        sort(pos,pos+n);
        ll sta=0;
        ll end=pos[n-1]-pos[0];
        ll ans=-1;
        while(sta<=end)
        {
            ll mid = sta+(end-sta)/2;
            if(check(c,pos,n,mid))
            {
                ans=mid;
                sta=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}