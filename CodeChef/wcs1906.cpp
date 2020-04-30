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
    if(1)
    {
    ll counter=0;
    ll min=10e15;
    ll t;
    for(ll i=0;i<n;i++)
    {
        t=(v[i]-i);
        if (t<=0)
        {
            counter=i;
            break;
        }
        if(t%n==0)
        {
            if(t/n<min)
            {
                min=t/n;
                counter=i;
            }
            else
            {
                continue;
            }
        }    
            
        else
        {
            if(t/n+1<min)
            {
                min=t/n+1;
                counter=i;
            }
            else
            {
                continue;
            }
                
        }
    }
    cout<<counter+1<<endl;
    }
    else{
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
    }
    return 0;
}