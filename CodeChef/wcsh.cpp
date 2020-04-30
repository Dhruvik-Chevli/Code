#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long int ll;
using namespace std;
int main()
{
    ll n;
    vector<ll>v;
    cin>>n;
    ll k;
    for(ll i=0;i<n;i++)
    {
        cin>>k;
        v.push_back(k);
    }
    ll ind=0;
        while(1)
        {
            if(v[ind]<=0)
            {
                cout<<ind+1<<endl;
                break;
            } 
            for(ll i=0;i<n;i++)
                v[i]=v[i]-1;    
            ind++;
            if(ind==n)
                ind=0;
        }

    return 0;
}