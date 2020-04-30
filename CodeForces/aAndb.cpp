#include<iostream>
#include<algorithm>
#include<vector>
#define pb push_back
typedef long long int ll;
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll mi=min(a,b);
        ll ma=max(a,b);
        if(ma%2==0)
        {
            cout<<(ma-mi)/2<<endl;
        }
        else
        {
            cout<<(ma-mi-1)/2<<endl;
        }        
    }
    return 0;
}