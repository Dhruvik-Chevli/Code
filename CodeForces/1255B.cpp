#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_set>
#include<stack>
#include<queue>
#include<numeric>
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
        ll n,m;
        cin>>n>>m;
        vector<ll>v(n+1);
        FOR(i,1,n+1)
        {
            cin>>v[i];
        }
        int sum=0;
        FOR(i,1,n+1)
        {
            sum+=v[i];
        }
        if(m<n)
        {
            cout<<"-1\n";
        }
        else if(n==m and n==2)
        {
            cout<<"-1"<<"\n";
        }
        else
        {
            cout<<2*sum<<"\n";
            FOR(i,1,n)
            {
                cout<<i<<" "<<i+1<<"\n";
            }
            cout<<n<<" 1\n";
        }
    }
    return 0;
}