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
        vector<ll>v(n);
        FOR(i,0,n)
        {
            cin>>v[i];
        }
        ll ans=0;
        if(v[0]<0)
        {
            ll i=0;
            while(i<n)
            {
                ll j=i;
                ll mi=v[j];
                j++;
                while(v[j]<0 and j<n)
                {
                    if(v[j]>mi)
                    {
                        mi=v[j];
                    }
                    j+=1;
                }
                //cout<<mi<<" ";
                ans+=mi;
                if(j>=n)
                {
                    break;
                }
                ll max=v[j];
                j++;
                while(v[j]>0 and j<n)
                {
                    if(v[j]>max and j<n)
                    {
                        max=v[j];
                    }
                    j+=1;
                }
                //cout<<max<<endl;
                ans+=max;
                i=j;
            }
        }
        else
        {
            ll i=0;
            while(i<n)
            {
                ll j=i;
                ll ma=v[j];
                j++;
                while(v[j]>0 and j<n)
                {
                    if(v[j]>ma)
                    {
                        ma=v[j];
                    }
                    j+=1;
                }
                ans+=ma;
                if(j>=n)
                {
                    break;
                }
                ll mi=v[j];
                j++;
                while(v[j]<0 and j<n)
                {
                    if(v[j]>mi and j<n)
                    {
                        mi=v[j];
                    }
                    j+=1;
                }
                ans+=mi;
                i=j;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}