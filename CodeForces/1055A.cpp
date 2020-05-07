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
    ll n,s;
    cin>>n>>s;
    vector<ll>forward(n+1);
    vector<ll>backward(n+1);
    FOR(i,1,n+1)
    {
        cin>>forward[i];
    }
    FOR(i,1,n+1)
    {
        cin>>backward[i];
    }
    if(forward[1]==0)
    {
        cout<<"NO\n";
        return 0;
    }
    if(forward[s]==1)
    {
        cout<<"YES\n";
        return 0;
    }
    int flag=0;
    if(backward[s]==0)
    {
        cout<<"NO\n";
        return 0;
    }
    FOR(i,s+1,n+1)
    {
        if(forward[i]==1 and backward[i]==1)
        {
            flag=i;
            break;
        }   
    }
    if(flag!=0)
    {
        cout<<"YES\n";
        return 0;
    }
    cout<<"NO\n";
    return 0;
}