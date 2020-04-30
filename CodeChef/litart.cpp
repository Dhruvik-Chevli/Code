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
        ll n,m;
        cin>>n>>m;
        int f=0;
        int pb=0;
        if(n%2==0||m%2==0)
            f=1;
        FOR(i,0,n)
        {
            FOR(j,0,m)
            {
                if(i==n-1&&j==m-1 && f==1)
                {    
                    cout<<'B';
                    break;
                }
                if(i==n-1 && j==m-2 && f==1)
                {
                    cout<<'B';
                    continue;
                }
                if(i%2==0){
                    if(j%2==0)
                    {
                        cout<<'B';
                    }
                    else
                    {
                        cout<<'W';
                    }
                }
                else
                {
                    if(j%2==0)
                    {
                        cout<<'W';
                    }
                    else
                    {
                        cout<<'B';
                    }
                }
                
            }
            cout<<endl;
        }
    }
    return 0;
}