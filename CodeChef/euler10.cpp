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
#define MAXN 1000001
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll>sieve(MAXN);
    FOR(i,0,MAXN)
    {
        sieve[i]=i;
    }
    for(ll i=4;i<MAXN;i+=2)
    {
        sieve[i]=2;
    }
    for(int i=3;i<MAXN;i+=1)
    {
        if(sieve[i]==i)
        {
            FOR(ll j=i*i;j<MAXN;j+=i)
            {
                sieve[j]=i;
            }
        }
    }
    vector<ll>primes;
    vector<ll>sum;
    ll su=0;
    FOR(i,2,MAXN)
    {
        if(sieve[i]==i)
        {
            primes.pb(i);
            su+=i;
            sum.pb(su);
        }
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll k=upper_bound(primes.begin(),primes.end());
        cout<<sum[k-1]<<"\n";
    }
    return 0;
}