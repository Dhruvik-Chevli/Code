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
    ll n,d;
    cin>>n>>d;
    vector<pair<pair<int,float>,pair<int,int> > >worker;
    FOR(i,0,n)
    {
        float ans=0;
        ll t,x,y;
        cin>>t>>x>>y;
        worker.push_back(make_pair(make_pair(t,(float)y/x),make_pair(x,y)));
    }
    sort(worker.begin(),worker.end());
    float curratecost=0;
    int currate=0;
    int i=0;
    int ind=0;
    while(d-currate>=0)
    {
        //cout<<d<<" "<<currate<<" "<<i<<" "<<ind<<endl;
        d-=currate;
        while(i>=worker[ind].first.first and i<n)
        {
            if(worker[ind].first.second>curratecost or (worker[ind].first.second==curratecost and worker[ind].second.second>currate))
            {
                curratecost=worker[ind].first.second;
                currate=worker[ind].second.second;
            }
            ind+=1;
        }
        i+=1;
    }
    if(d>0)
    {
        i++;
    }
    cout<<--i<<endl;
    return 0;
}