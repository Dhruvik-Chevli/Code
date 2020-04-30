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
const ll dx[8]={2,2,-2,-2,1,1,-1,-1};
const ll dy[8]={1,-1,1,-1,2,-2,2,-2};
ll bfs(ll sc,ll sr,ll fc,ll fr)
{
    vector<vector<ll> >dist(8,vector<ll>(8,-1));
    dist[sr][sc]=0;
    queue<pair<ll,ll> >q;
    q.push(make_pair(sr,sc));
    while(!q.empty())
    {
        pair<ll,ll> k=q.front();
        q.pop();
        if(k.first==fr and k.second==fc)
        {
            return dist[fr][fc];
        }
        FOR(i,0,8)
        {
            ll x=k.first+dx[i];
            ll y=k.second+dy[i];
            if(x>=0 and x<8 and y>=0 and y<8 and dist[x][y]==-1)
            {
                dist[x][y]=dist[k.first][k.second]+1;
                q.push(make_pair(x,y));
            }
            if(x==fr and y==fc)
            {
                return dist[fr][fc];
            }
        }
    }
    return -1;

}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        ll sc=a[0]-'a';
        ll sr=a[1]-'1';
        ll fc=b[0]-'a';
        ll fr=b[1]-'1';
        cout<<bfs(sc,sr,fc,fr)<<endl;
    }
    return 0;
}