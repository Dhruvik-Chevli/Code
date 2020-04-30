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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll k=n/2;
        if(k%2)
        {
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            ll seven=0;
            ll cur=2;
            FOR(i,0,k)
            {
                cout<<cur<<" ";
                seven+=cur;
                cur+=2;
            }
            cur=1;
            ll sodd=0;
            FOR(i,0,k-1)
            {
                cout<<cur<<" ";
                sodd+=cur;
                cur+=2;
            }
            ll final=seven-sodd;
            cout<<final<<"\n";
        }
    }
    return 0;
}