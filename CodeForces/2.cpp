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
        vector<int>v(3,0);
        ll x;
        cin>>x;
        v[x-1]=1;
        // FOR(i,0,3)
        // {
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        FOR(i,0,3)
        {
            ll a,b;
            cin>>a>>b;
            swap(v[a-1],v[b-1]);
            // FOR(i,0,3)
            // {
            //     cout<<v[i]<<" ";
            // }
            // cout<<endl;
        }
        FOR(i,0,3)
        {
            if(v[i]==1)
            {
                x=i+1;
            }
        }
        cout<<x<<"\n";
    }
    return 0;
}