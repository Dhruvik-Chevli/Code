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
    ll n;cin>>n;
    ll qr,qc;
    cin>>qr>>qc;
    ll ksr,ksc;
    ll ker,kec;
    cin>>ksr>>ksc>>ker>>kec;
    ll k1=(ksr-qr)*(ker-qr);
    ll k2=(ksc-qc)*(kec-qc);
    if(k1<0 or k2<0)
    {
        cout<<"NO\n";
    } 
    else
    {
        cout<<"YES\n";
    }
    
    return 0;
}