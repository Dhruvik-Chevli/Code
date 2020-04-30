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
        ll maxi=0;
        string s;
        cin>>s;
        ll lpos=-1;
        FOR(i,0,s.length())
        {
            if(s[i]=='R')
            {
                maxi=max(maxi,i-lpos);
                lpos=i;
            }
        }
        ll n=s.length();
        maxi=max(maxi,n-lpos);
        cout<<maxi<<endl;
    }
    return 0;
}