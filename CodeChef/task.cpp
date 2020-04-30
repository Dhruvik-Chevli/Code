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
    FOR(r,1,t+1)
    {
        ll n;
        cin>>n;
        vector<pair<pair<int,int>,int> >tasks;
        FOR(i,0,n)
        {
            ll sta,end;
            cin>>sta>>end;
            tasks.pb(make_pair(make_pair(sta,end),i));
        }
        sort(tasks.begin(),tasks.end());
        char ans[n+1];
        ans[n]='\0';
        int jl=-1;
        int cl=-1;
        int fi=0;
        FOR(i,0,n)
        {
            if(tasks[i].first.first>=jl)
            {
                ans[tasks[i].second]='J';
                jl=tasks[i].first.second;
            }
            else if(tasks[i].first.first>=cl)
            {
                ans[tasks[i].second]='C';
                cl=tasks[i].first.second;
            }
            else
            {
                fi=1;
                break;
            }
        }
        if(fi)
        {
            cout<<"Case #"<<r<<": "<<"IMPOSSIBLE"<<endl;
        }
        else
        {
            cout<<"Case #"<<r<<": "<<ans<<endl;
        }
    }
    return 0;
}