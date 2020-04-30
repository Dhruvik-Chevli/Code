#include<iostream>
#include<string>
#include<cstring>
#include<vector>
typedef long long int ll;
using namespace std;
int  main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string s,u;
        cin>>s;
        ll ans=0;
        ll count=0;
        ll len=s.length();
        for(ll i=0;i<len-1;i++)
        {
            if(s[i]==s[i-1])
                count+=1;
        }
        vector<ll>le(len,0);
        vector<ll>ri(len,0);
        for(ll i=0;i<len;i++)
        {
            if(i!=0 && i!=len-1)
            {
                if(s[i]!=s[i-1])
                    le[i]++;
                else
                {
                    le[i]--;
                }
                if(s[i]!=s[i+1])
                    ri[i]++;
                else
                {
                    ri[i]--;
                }
            }
            else if(i==0)
            {
                if(s[i]!=s[i+1])
                    ri[i]++;
                else
                {
                    ri[i]--;
                }
            }
            else if(i==len-1)
            {
                if(s[i]!=s[i-1])
                    le[i]++;
                else
                {
                    le[i]--;
                }
                    
            }
        }
        ll temp=0;
        for(ll i=0;i<len;i++)
        {
            ll left=len-i;
            ll right=i+1;
            temp=temp+left*le[i]+right*ri[i];
        }
        ll sum=(len*(len+1))/2;
        cout<<sum*count+temp<<endl;
    }
    return 0;
} 