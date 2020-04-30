#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_set>
#include<stack>
#include<queue>
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
        string s;
        cin>>s;
        ll n=s.length();
        ll c=0;
        FOR(i,0,n)
        {
            if(s[i]!='1')
            {
                c=1;
                break;
            }
        }
        ll d=0;
        FOR(i,0,n)
        {
            if(s[i]!='0')
            {
                d=1;
                break;
            }
        }
        if(c==0||d==0)
        {
            cout<<s<<"\n";
        }
        else
        {
            FOR(i,0,2*n)
            {
                if(i%2==0)
                {
                    cout<<"0";
                }
                else
                {
                    cout<<"1";
                }
            }
            cout<<endl;
        }
        
    }
    return 0;
}