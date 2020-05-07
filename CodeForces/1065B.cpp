#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_set>
#include<stack>
#include<queue>
#include<unordered_map>
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
    ll n,m;
    cin>>n>>m;
    ll mn=(0>n-m*2)?0:n-m*2;
    ll sum=m;
    ll cnt=1;
    while(sum>0)
    {
        ll k=min(cnt,sum);
        sum-=k;
        cnt++;
    }
    ll ans=n;
    if(cnt>1) ans=n-cnt;
    cout<<mn<<" "<<ans<<endl;
    return 0;
}