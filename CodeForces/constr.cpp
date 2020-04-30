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
        ll n,a,b;
        cin>>n>>a>>b;
        string ans="";
        string sa="";
        char c='a';
        FOR(i,0,a-b+1)
        {
            sa+=c;
        }
        FOR(i,0,b-1)
        {
            c+=1;
            sa+=c;
        }
        //cout<<sa<<endl;
        for(ll i=0;i<n;i+=a)
        {
            ans+=sa;
        }
        ans=ans.substr(0,n);
        cout<<ans<<endl;
    }
    return 0;
}