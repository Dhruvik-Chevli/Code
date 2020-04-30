#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long int
#define FOR(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
int main()
{
    ll t;
    cin>>t;
    ll g=0;
    while(t--)
    {
        g++;
        ll n,b;
        cin>>n>>b;
        vector<ll>h(n);
        FOR(i,0,n)
        {
            cin>>h[i];
        }
        ll count=0;
        ll sum=0;
        ll i=0;
        sort(h.begin(),h.end());
        while(sum<b and i<n)
        {
            sum+=h[i];
            if(sum<=b)
                count+=1;
            i++;
        }
        cout<<"Case #"<<g<<": "<<count<<endl;
        
    }
    return 0;
}