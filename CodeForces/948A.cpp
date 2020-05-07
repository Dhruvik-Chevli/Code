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
    ll n,m;
    cin>>n>>m;
    string s[n];
    FOR(i,0,n)
    {
        cin>>s[i];
    }
    int flag=1;
    FOR(i,0,n)
    {
        FOR(j,0,m)
        {
            if(s[i][j]=='W')
            {
                if(j>0 and s[i][j-1]=='S')
                {
                    flag=0;
                    break;
                }
                if(j<m-1 and s[i][j+1]=='S')
                {
                    flag=0;
                    break;
                }
                if(i>0 and s[i-1][j]=='S')
                {
                    flag=0;
                    break;
                }
                if(i<n-1 and s[i+1][j]=='S')
                {
                    flag=0;
                    break;
                }
            }
            if(s[i][j]=='.')
            {
                s[i][j]='D';
            }
        }
        if(flag==0)
            break;
    }
    if(flag)
    {
        cout<<"Yes\n";
        FOR(i,0,n)
        {
            cout<<s[i]<<"\n";
        }
    }
    else
    {
        cout<<"No\n";
    }
    return 0;
}