#include<iostream>
#include<queue>
typedef long long int ll;
#include<algorithm>
#include <vector>
#define pb push_back;
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        queue<ll>q;
        vector<ll>v;
        ll n,k,p,su,min,sta;
        ll i=0;
        su=0;
        cin>>n>>p;
        for(i=0;i<n;i++)
        {   
            cin>>k;
            v.push_back(k);
        }
        i=-1;
        sta=0;
        min=9223372036854775807;
        bool set=false;
        while(i<n){
            if(su<=p)
            {
                if(!set)
                {
                    i++;
                    su+=v[i];
                }
                else
                {
                    su-=v[sta];
                    sta+=1;
                    i++;
                    su+=v[i];
                }
            }
            else
            {
                if(!set)
                {
                    //cout<<"$"<<endl;
                    if(i-sta+1<min)
                    {
                        min=i-sta+1;
                    }
                    while(su>p)
                    {
                        su-=v[sta];
                        sta+=1;
                    }
                    if(i-sta+2<min)
                    {
                        min=i-sta+2;
                    }
                    set=true;
                }
                else
                {
                while(su>p)
                    {
                        su-=v[sta];
                        sta+=1;
                    }
                    if(i-sta+2<min)
                    {
                        min=i-sta+2;
                    }

                }
                
            }
        //cout<<"#"<<su<<" "<<i<<" "<<sta<<" "<<set<<" "<<min<<endl;   
        }
        if(min==9223372036854775807)
            cout<<n+1<<endl;
        else    
            cout<<min<<endl;
        
    }
    return 0;    
}