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
        string st;
        cin>>st;
        ll j=n-1;
        ll i=0;
        ll f=1;
        ll count=0;
        bool check[n+1];
        FOR(i,0,n+1)
            check[i]=true;
        while(i<j)
        {
            //cout<<st[i]<<" "<<st[j]<<endl;
            if(st[i]==st[j])
            {
                i+=1;
                j-=1;
                continue;
            }
            else
            {
                if(st[i+1]==st[j] and st[i]==st[j-1])
                {
                    if(check[i] && check[i+1])
                    {
                        swap(st[i],st[i+1]);
                        check[i]=check[i+1]=false;
                    }
                    else if(check[j] and check[j-1])
                    {
                        swap(st[j],st[j-1]);
                        check[j]=check[j-1]=false;
                    }
                    else
                    {
                        f=0;
                        break;
                    }
                    
                    i+=2;
                    j-=2;
                    count+=1;
                }
                /*
                else if(st[i+1]==st[j] and i==n/2-1 and n&1)
                {
                    count+=1;
                    i+=1;
                    j-=1;
                }
                else if(st[j-1]==st[i] and j==n/2+1 and n&1)
                {
                    count+=1;
                    i+=1;
                    j-=1;
                }*/
                else if(st[i+1]==st[j])
                {
                    if(check[i] and check[i+1])
                    {
                        char u=st[i];
                        st[i]=st[i+1];
                        st[i+1]=u;
                        check[i]=check[i+1]=false;
                    }
                    else{
                        f=0;
                        break;
                    }
                    i+=1;
                    j-=1;
                    count+=1;
                }
                else if(st[j-1]==st[i])
                {
                    if(check[j] and check[j-1])
                    {
                        char u=st[j-1];
                        st[j-1]=st[j];
                        st[j]=u;
                        check[j]=check[j-1]=false;
                    }
                    else
                    {
                        f=0;
                        break;
                    }
                    
                    i+=1;
                    j-=1;
                    count+=1;
                }
                else
                {
                    f=0;
                    break;
                }
                
            }
        }
        if(n&1)
        {
            if(st[n/2-1]!=st[n/2+1])
                f=0;
        }
        else
        {
            if(st[n/2-1]!=st[n/2])
                f=0;
        }
        
        if(f){
            cout<<"YES"<<endl;
            cout<<count<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}