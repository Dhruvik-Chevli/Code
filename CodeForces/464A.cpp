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
    ll n;
    cin>>n;
    vector<int>v(n,0);
    FOR(i,0,n)
    {
        cin>>v[i];
    }
    int flag=false;
    FOR(i,0,n)
    {
        if(f[f[f[i]]]==i)
        {
            flag=true;
            break;
        }
    }
    if(flag)
        cout<<"YES\n";
    else
    {
        cout<<"NO\n";
    }
    
    return 0;
}