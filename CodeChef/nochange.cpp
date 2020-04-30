#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
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
        ll n,p;
        cin>>n>>p;
        vector<ll>v(n);
        FOR(i,0,n)
        {
            cin>>v[i];
        }
        ll f=1;
        ll div=1;
        ll j=0;
        for(;j<n;j++)
        {
            if(j==0)
            {
                if(p%v[j]!=0)
                {
                    div=0;
                    break;
                }
                continue;
            }
            if(p%v[j]!=0)
            {
                div=0;
                break;
            }
            if(v[j]%v[j-1]!=0)
            {    
                f=0;
                break;
            }
        }
        if(div==1 and f==1)
        {
            cout<<"NO"<<endl;
        }
        else if(f==0 and div==1)
        {
            cout<<"YES ";
            ll y=p-v[j];
            ll prev=y/v[j];
            FOR(i,0,n)
            {
                if(i==j-1)
                {
                    ll u=p-y;
                    ll r=u/v[j-1]+1;
                    cout<<r<<" ";
                }
                else if(i==j)
                {
                    cout<<prev<<" ";
                }
                else
                {
                    cout<<0<<" ";
                }
                
            }
            cout<<endl;
        }
        else if(f==1 and div==0)
        {
            cout<<"YES"<<" ";
            FOR(i,0,n)
            {
                if(i==j)
                {
                    ll y=p/v[j]+1;
                    cout<<y<<" ";
                }
                else
                {
                    cout<<0<<" ";
                }
                
            }
            cout<<endl;
        }
    }
    return 0;
}