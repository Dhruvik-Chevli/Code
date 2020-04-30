#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int ll;
#define pb push_back;
int main()
{
    ll t;
    cin>>t;
    ll x,y,k,n;
    ll pi,ci;
    while(t--)
    {
        cin>>x>>y>>k>>n;
        vector<ll>p;
        vector<ll>c;
        while(n--)
        {
            cin>>pi>>ci;
            p.push_back(pi);
            c.push_back(ci);
        }
        n=p.size();
        bool f=false;
        for(int i=0;i<n;i++)
        {
            if(p[i]>=x-y && c[i]<=k)
            {
                cout<<"LuckyChef"<<endl;
                f=true;
                break;
            }
        }
        if(!f)
        {
            cout<<"UnluckyChef"<<endl;
        }
    }
}