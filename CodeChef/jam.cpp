#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define ll long long int
#define FOR(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
int main()
{
    ll t;
    cin>>t;
    FOR(r,1,t+1)
    {
        ll n;
        cin>>n;
        string ans;
        ans="";
        int fj,fc;
        vector<ll>jamie(24*60,0);
        vector<ll>cameron(24*60,0);
        int fi=0;
        FOR(i,0,n)
        {
            ll s,e;
            cin>>s>>e;
            fc=0;
            if(fi==1)
                continue;
            FOR(j,s,e)
            {
                if(cameron[j]!=0)
                {
                    fc=1;
                    break;
                }
            }
            if(fc==0)
            {
                FOR(j,s,e)
                {
                    cameron[j]=1;
                }
                ans+='C';
                continue;
            }
            else
            {
                fj=0;
                FOR(j,s,e)
                {
                    if(jamie[j]!=0)
                    {
                        fj=1;
                        break;
                    }
                }
                if(fj==0)
                {
                    FOR(j,s,e)
                    {
                        jamie[j]=1;
                    }
                    ans+='J';
                    continue;
                }
                else
                {
                    fi=1;
                    continue;
                }
            }    
            
        }
        if(fi==0)
        {
            cout<<"Case #"<<r<<": "<<ans<<endl;
        }
        else
        {
            cout<<"Case #"<<r<<": "<<"IMPOSSIBLE"<<endl;
        }
        
    }
    return 0;
    
}