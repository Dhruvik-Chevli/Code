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
    ll n,w;
    cin>>n>>w;
    vector<ll>val(n,0);
    vector<ll>wt(n,0);
    FOR(i,0,n)
    {
        cin>>wt[i]>>val[i];
    }
    cout<<knapsack(n,w,val,wt)<<endl;
    return 0;
}