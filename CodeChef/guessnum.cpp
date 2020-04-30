#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define pb push_back
typedef long long int ll;
int main()
{
    ll t;
    cin>>t;
    //cout<<t;
    while(t--)
    {
        ll a,m;
        cin>>a>>m;
        //cout<<a<<m;
        vector<ll>div;
        for(ll i=1;i*i<=m;i++)
        {
          //  cout<<i;
            if(m%i==0)
            {
                div.pb(i);
                div.pb(m/i);
            }
        }
        ll count=0;
        vector<ll>n;
        /*cout<<endl;
        for(ll i=0;i<div.size();i++)
            cout<<div[i]<<"^";
        cout<<endl<<endl;*/
        for(ll i=0;i<div.size();i++)
        {
            //cout<<i<<"%";
            if((m-div[i])%a==0)
            {
                //cout<<m-div[i]<<"$\n";
                if(m-div[i]!=0)
                {   
                    if((((m-div[i])/a)%div[i])==0)
                    { 
                    count+=1;
                    n.pb((m-div[i])/a);
                    }
                }
            }
        }
        cout<<count<<endl;
        sort(n.begin(),n.end());
        for(ll i=0;i<n.size();i++)
        {
            cout<<n[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}