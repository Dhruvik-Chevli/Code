//<!-- prettier-ignore -->
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;
typedef long long ll int;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for (ll i = a; i < b; i++)
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
        ll n,m,k;
        cin>>n>>m>>k;
        vector<vector<ll> >arr(n,vector<ll>(k,0));
        FOR(i,0,n)
        {
            FOR(j,0,k)
            {
                cin>>arr[i][j];
            }
        }
        vector<ll>options(m+1,0);
        vector<ll>ans;
        vector<ll>scores(k+1,n);
        FOR(i,0,n)
        {
            vector<pair<ll,ll> >minScore;
            ll mini=100000000;
            FOR(j,1,k+1)
            {
                if(scores[j]<mini)
                    mini=scores;
            }
            FOR(j,1,k+1)
            {
                if(scores[j]==mini)
                {
                    minScore.pb(make_pair(j,arr[i][j]));
                }
            }
            vector<ll>eachOption(m+1,0);
            FOR(j,0,minScore.size())
            {
                FOR(x,0,k+1)
            }

            
            vector<ll>map(m+1,0);
            FOR(j,0,k)
            {
                //cout<<arr[i][j]<<" ";
                map[arr[i][j]]+=1;
            }
            ll ma=0;
            ll ans1=0;
            vector<ll>max;
            FOR(j,0,m+1)
            {
                if(map[j]>ma)
                {
                    ma=map[j];
                }
            }
            FOR(j,0,m+1)
            {
                if(map[j]==ma)
                {
                    max.pb(j);
                }
            }
            ll finalans;
            ll minans=100000000;
            FOR(j,0,max.size())
            {
                if(options[max[j]]<minans)
                {
                    minans=options[max[j]];
                    finalans=max[j];
                }
            }
            ans.pb(finalans);
            options[finalans]+=1;
        }
        FOR(i,0,n)
        {
            cout<<5%m+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}