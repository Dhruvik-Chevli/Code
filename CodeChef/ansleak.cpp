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
#define INT_MAX 10000000
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
        vector<vector<ll> >ans(n+1,vector<ll>(k+1,0));
        FOR(i,1,n+1)
        {
            FOR(j,1,k+1)
            {
                cin>>ans[i][j];
            }
        }
        // FOR(i,0,n+1)
        // {
        //     FOR(j,0,k+1)
        //     {
        //         cout<<ans[i]
        //     }
        // }
        vector<ll>scores(k+1,n);
        FOR(i,1,n+1)
        {
            // cout<<"SCORES________\n";
            // FOR(j,0,k+1)
            // {
            //     cout<<scores[j]<<" ";
            // }
            // cout<<endl;
            ll mini=INT_MAX;
            FOR(j,1,k+1)
            {
                if(scores[j]<mini)
                {
                    mini=scores[j];
                }
            }
            // cout<<"Mini: "<<mini<<endl;
            vector<pair<ll,ll> >minScore;
            FOR(j,1,k+1)
            {
                if(scores[j]==mini)
                {
                    minScore.push_back(make_pair(j,ans[i][j]));
                }
            }
            // FOR(j,0,k+1)
            // {
            //     cout<<ans[i][j]<<" ";
            // }
            // cout<<endl;
            // cout<<"minScore: "<<endl;
            // FOR(j,0,minScore.size())
            // {
            //     cout<<minScore[j].first<<" "<<minScore[j].second<<endl;
            // }
            vector<ll>maxAns(m+1,0);
            FOR(j,0,minScore.size())
            {
                maxAns[minScore[j].second]+=1;
            }
            ll maxans=0;
            FOR(j,1,m+1)
            {
                if(maxAns[j]>maxans)
                {
                    maxans=maxAns[j];
                }
            }
            ll fans;
            vector<ll>possAns;
            FOR(j,1,m+1)
            {
                if(maxAns[j]==maxans)
                {
                    fans=j;
                }
            }
            // ll max=0;
            // ll fans=0;
            // FOR(x,0,possAns.size())
            // {
            //     ll count=0;
            //     FOR(j,1,k+1)
            //     {
            //         if(ans[i][j]==possAns[x])
            //         {
            //             count+=1;
            //         }
            //     }
            //     if(count>max)
            //     {
            //         max=count;
            //         fans=possAns[x];
            //     }
            // }
            cout<<fans<<" ";
            FOR(j,1,k+1)
            {
                if(ans[i][j]==fans)
                {
                    continue;
                }
                else
                {
                    scores[j]-=1;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}