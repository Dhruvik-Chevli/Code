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
        ll x,y,a,b;
        cin>>x>>y>>a>>b;
        if(a==b)
        {
            cout<<min(x,y)*b+(max(x,y)-min(x,y))*a<<"\n";
            continue;
        }
        ll k=(y+x)*a-(min(x,y)*b+(max(x,y)-min(x,y))*a);
        if(k>0)
        {
            cout<<min(x,y)*b+(max(x,y)-min(x,y))*a<<"\n";
        }
        else
        {
            cout<<(y+x)*a<<"\n";
        }
    }
    return 0;
}