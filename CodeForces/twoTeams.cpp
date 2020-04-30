#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_map>
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
        vector<ll>map(n+1,0);
        ll countDist=0;
        ll countMax=1;
        ll k;
        FOR(i,0,n)
        {
            cin>>k;
            if(map[k]==0)
            {
                countDist+=1;
            }
            map[k]+=1;
            if(map[k]>countMax)
            {
                countMax=map[k];
            }
        }
        if(countMax==1 and countDist!=1)
        {
            cout<<1<<"\n";
            continue;
        }
        else if(countDist==1 and countMax==1)
        {
            cout<<0<<"\n";
            continue;
        }
        if(countDist>countMax)
        {
            cout<<countMax<<"\n";
        }
        else if(countDist==countMax)
        {
            cout<<countMax-1<<"\n";
        }
        else
        {
            cout<<countDist<<"\n";
        }
        
        
    }
    return 0;
}