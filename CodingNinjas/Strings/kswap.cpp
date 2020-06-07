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
        ll n,k;
        cin>>n>>k;
        vector<pair<ll,ll> >v(n);
        FOR(i,0,n)
        {
            ll u;
            cin>>u;
            v[i]=make_pair(u,i);
        }
        sort(v.begin(),v.end());
        int flag=1;
        FOR(i,0,n)
        {
            if(abs(i-v[i].second)%k!=0)
            {
                //cout<<v[i].first<<endl;
                ll res=abs(i-v[i].second)%k;
                int f=0;
                FOR(j,1,res+1)
                {
                    if(i+j>=n)
                    {
                        break;
                    }    //cout<<v[i+res].first<<" "<<v[i].first<<"\n";
                    if(v[i+j].first==v[i].first)
                    {
                        f=1;
                        break;
                    }
                }
                FOR(j,1,res+1)
                {
                        //cout<<v[i-res].first<<" "<<v[i].first<<"\n";
                    if(i-j<0)
                        break;
                    if(v[i-j].first==v[i].first)
                    {
                        f=1;
                        break;
                    }
                }
                if(f==0)
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag)
        {
            cout<<"yes\n";
        }
        else
        {
            cout<<"no\n";
        }

    }
    return 0;
}