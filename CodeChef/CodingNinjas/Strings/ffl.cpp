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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll>def;
        vector<ll>gk;
        vector<ll>p(n);
        vector<ll>c(n);
        FOR(i,0,n)
        {
            cin>>p[i];
        }
        FOR(i,0,n)
        {
            cin>>c[i];
        }
        FOR(i,0,n)
        {
            if(c[i]==1)
            {
                gk.pb(p[i]);
            }
            else
            {
                def.pb(p[i]);
            }
        }
        if(def.size()==0||gk.size()==0)
        {
            cout<<"no\n";
            continue;
        }
        sort(gk.begin(),gk.end());
        sort(def.begin(),def.end());
        if(gk[0]+def[0]<=100-k)
        {
            cout<<"yes\n";
        }
        else
        {
            cout<<"no\n";
        }
        
    }    
    return 0;
}