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
        vector<ll>v(n,0);
        FOR(i,0,n)
        {
            cin>>v[i];
        }
        ll i=0;
        ll count=0;
        while(i<n-1)
        {
            if(v[i+1]-v[i]==1 and i<n-1)
            {
                while(v[i+1]-v[i]==1)
                {
                    i+=1;
                }
                count+=1;
            }
            else
            {
                i+=1;
            }
            
        }
        cout<<count<<endl;
    }
    return 0;
}