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
        string s1,s2;
        cin>>s1;
        string fs1="",fs2="";
        cin>>s2;
        ll i=0;
        ll j;
        while(i<s1.length())
        {
            if(s1[i]!='#')
            {
                char c=s1[i];
                j=i+1;
                int count=0;
                while(s1[j]=='#')
                {
                    count+=1;
                    j+=1;
                }
                count=count%26;
                if(c+count>90)
                {
                    c=c+count-26;
                }
                else
                {
                    c=c+count;
                }
                
                fs1+=c;
                i=j;
            }
        }
        i=0;
        while(i<s2.length())
        {
            if(s2[i]!='#')
            {
                char c=s2[i];
                j=i+1;
                int count=0;
                while(s2[j]=='#')
                {
                    count+=1;
                    j+=1;
                }
                count=count%26;
                if(c+count>90)
                {
                    c=c+count-26;
                }
                else
                {
                    c=c+count;
                }
                
                fs2+=c;
                i=j;
            }
        }
        //cout<<fs1<<" "<<fs2<<endl;
        if(fs1.length()==fs2.length())
        {
            int f=1;
            FOR(i,0,fs1.length())
            {
                if(fs1[i]!=fs2[i])
                {
                    f=0;
                    break;
                }
            }
            if(f)
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
            
        }
        else
        {
            cout<<"No\n";
        }
    }
    return 0;
}