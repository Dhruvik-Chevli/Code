//<!-- prettier-ignore -->
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
        if(n==1)
        {
            cout<<1<<"\n";
            cout<<1<<" "<<1<<"\n";
            continue;    
        }
        else if(n==2)
        {
            cout<<1<<"\n";
            cout<<"2 1 2\n";
            continue;
        }
        else if(n==3)
        {
            cout<<"1 \n3 1 2 3\n";
            continue;
        }
        cout<<n/2<<"\n";
        if(n%2==0)
        {
            ll i=1;
            while(i<n)
            {
                cout<<"2 "<<i<<" "<<i+1<<"\n";
                i+=2;
            }
        }
        else
        {
            cout<<3<<" "<<1<<" "<<2<<" "<<3<<"\n";
            ll i=4;
            while(i<n)
            {
                cout<<2<<" "<<i<<" "<<i+1<<"\n";
                i+=2;
            }
        }
    }
    return 0;
}