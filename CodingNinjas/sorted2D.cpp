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
    ll n,m;
    cin>>n>>m;
    int** arr=new int*[n];
    FOR(i,0,n)
        arr[i]=new int[m];
    FOR(i,0,n)
    {
        FOR(j,0,m)
        {
            cin>>arr[i][j];
        }
    }
    vector<vector<ll> >dp(n,vector<ll>(m,1));
    FOR(i,1,n)
    {
        FOR(j,0,m)
        {
            if(arr[i][j]>=arr[i-1][j])
                dp[i][j]=dp[i-1][j];
            else
            {
                dp[i][j]=i+1;
            }
        }
    }
    FOR(i,0,n)
    {
        FOR(j,0,m)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"**************"<<endl;
    FOR(i,0,n)
    {
        FOR(j,0,m)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    ll k;
    cin>>k;
    FOR(i,0,k)
    {
        ll l,r;
        int f=0;
        cin>>l>>r;
        FOR(j,0,m)
        {
            if(dp[r-1][j]<=(l))
            {
                f=1;
                break;
            }
        }
        if(f)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}