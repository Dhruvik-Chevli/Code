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
        vector<int>a(n,0);
        vector<int>b(n,0);
        FOR(i,0,n)
        {
            cin>>a[i];
        }
        FOR(i,0,n)
        {
            cin>>b[i];
        }
        ll fp1=0;
        ll fn1=0;
        ll f=1;
        FOR(i,0,n)
        {
            if(b[i]>a[i] and fp1!=1)
            {
                //cout<<"#"<<b[i];
                f=0;
                break;
            }
            else if(b[i]<a[i] and fn1!=1)
            {
                //cout<<"&"<<b[i];
                f=0;
                break;
            }
            if(a[i]==1)
            {
                //cout<<"*"<<b[i];
                fp1=1;
            }
            else if( a[i]==(-1))
            {
                //cout<<"("<<b[i];
                fn1=1;
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