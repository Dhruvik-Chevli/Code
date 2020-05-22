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
        ll n,sum;
        cin>>n>>sum;
        vector<ll>v(n);
        FOR(i,0,n)
        {
            cin>>v[i];
        }
        ll start=0,end=0;
        ll csum=v[0];
        if(v[0]==sum)
        {
            cout<<"1 1\n";
            continue;
        }
        ll i=1;
        int flag=0;
        while(i<n)
        {
            csum+=v[i];
            end=i;
            while(csum>sum)
            {
                csum-=v[start];
                start+=1;

            }
            if(csum==sum)
            {
                flag=1;
                break;
            }
            i++;
        }
        if(flag)
            cout<<start+1<<" "<<end+1<<"\n";
        else
        {
            cout<<"-1\n";
        }
        
    }
    return 0;
}