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
        ll n,k;
        cin>>n>>k;
        vector<ll>a(n);
        FOR(i,0,n)
        {
            cin>>a[i];
        }
        make_heap(a.begin(),a.end());
        ll profit=0;
        FOR(i,0,k)
        {
            if(a.size()==0)
                break;
            ll g=a.front();
            pop_heap(a.begin(),a.end());
            a.pop_back();
            profit+=g;
            if(g-1>0)
            { 
                a.push_back(g-1);
                push_heap(a.begin(),a.end());
            }        
        }
        cout<<profit<<endl;

    }
    return 0;
}