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
        vector<pair<int,int> >v(n,make_pair(0,0));
        int f=1;
        FOR(i,0,n)
        {
            cin>>v[i].first>>v[i].second;
            if(v[i].first<v[i].second)
                f=0;
        }
        if(f)
        {
            FOR(i,1,n)
            {
                if(v[i].first<v[i-1].first)
                {
                    f=0;
                    break;
                }
                if(v[i].second<v[i-1].second)
                {
                    f=0;
                    break;
                }
                if(v[i].first-v[i-1].first<v[i].second-v[i-1].second)
                {
                    f=0;
                    break;
                }
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