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
        vector<int>arr(n,0);
        FOR(i,0,n)
        {
            cin>>arr[i];
        }
        int lp=0;
        while(lp<n)
        {
            if(arr[lp]==1)
            {
                break;
            }
            lp+=1;
        }
        int f=1;
        FOR(i,lp+1,n)
        {
            if(arr[i]==1)
            {
                if(i-lp<6)
                {
                    f=0;
                    break;
                }
                lp=i;
            }
        }
        if(f)
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