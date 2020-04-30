#include<iostream>
#include<vector>
#include<algorithm>
#define pb push_back
typedef long long int ll;
using namespace std;
int main()
{
    ll n,q;
    cin>>n>>q;
    vector<ll>v(n+1);
    v[0]=0;
    ll cur=0;
    ll k;
    vector<ll>inc(n+1);
    inc[0]=0;
    vector<ll>dec(n+1);
    dec[0]=0;
    for(ll i=1;i<=n;i++)
    {
        cin>>k;
        v[i]=k;
        if(i==1)
        {
            inc[i]=0;
            dec[i]=0;
            continue;
        }
        if(v[i]<v[i-1])
        {
            if(cur==0)
            {
                cur=-1;
                dec[i]=dec[i-1]+1;
                inc[i]=inc[i-1];
            }
            else if(cur==-1)
            {
                dec[i]=dec[i-1];
                inc[i]=inc[i-1];
            }
            else if(cur==1)
            {
                dec[i]=dec[i-1]+1;
                inc[i]=inc[i-1];
                cur=-1;
            }
        }
        else if(v[i]>v[i-1])
        {
            if(cur==0)
            {
                cur=1;
                dec[i]=dec[i-1];
                inc[i]=inc[i-1]+1;                
            }
            else if(cur==1)
            {
                dec[i]=dec[i-1];
                inc[i]=inc[i-1];
            }
            else if(cur==-1)
            {
                dec[i]=dec[i-1];
                inc[i]=inc[i-1]+1;
                cur=1;
            }
        }
    }
    ll l,r;
    ll incr; ll decr;
    /*for(ll i=0;i<=n;i++)
    {
        cout<<inc[i]<<" ";
    }
    cout<<endl;
    for(ll i=0;i<=n;i++)
    {
        cout<<dec[i]<<" ";
    }
    cout<<endl;*/
    for(ll i=0;i<q;i++)
    {
        cin>>l>>r;
        if(inc[l]==inc[l+1])
        {
            if(dec[l]==dec[l+1])
            {
                if(v[l]>v[l+1])
                {
                    incr=inc[r]-inc[l];
                    decr=dec[r]-dec[l]+1;
                }
                else{
                    incr=inc[r]-inc[l]+1;
                    decr=dec[r]-dec[l];
                }
            }
            else if(dec[l]!=dec[l+1])
            {
                incr=inc[r]-inc[l];
                decr=dec[r]-dec[l];
            }
        }
        else if(inc[l]!=inc[l+1])
        {
            if(dec[l]==dec[l+1])
            {
                decr=dec[r]-dec[l];
                incr=inc[r]-inc[l];
            } 
        }
        if(incr==decr)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;    
}