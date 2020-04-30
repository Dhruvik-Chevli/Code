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
    ll t;cin>>t;
    while(t--)
    {
        vector<ll>v(4);
        FOR(i,0,4)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        if(v[0]+v[3]==v[1]+v[2])
        {
            cout<<"YES\n";
        }
        else if(v[0]+v[2]==v[1]+v[3])
        {
            cout<<"YES\n";
        }
        else if(v[0]+v[1]==v[2]+v[3])
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
        
    }
    return 0;
}