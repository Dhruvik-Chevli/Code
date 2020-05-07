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
ll bfs(ll n, ll m)
{
    ll k=max(n,m);
    vector<ll>dist(2*k+1,-1);
    //cout<<k<<endl;
    dist[n]=0;
    queue<ll>q;
    q.push(n);
    vector<bool>visited(2*k+1,false);
    visited[n]=true;
    while(!(q.empty()))
    {
        ll k=q.front();
        q.pop();
        //cout<<k<<endl;
        if(k==m)
        {
            break;
        }
        if(k*2<2*m and visited[2*k]==false)
        {
            dist[k*2]=dist[k]+1;
            visited[2*k]=true;
            q.push(2*k);
        }
        if(k-1>0 and visited[k-1]==false)
        {
            dist[k-1]=dist[k]+1;
            visited[k-1]=true;
            q.push(k-1);
        }
    }
    return dist[m];
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    // ll k=max(n,m);
    // vector<ll>dist(k+1,-1);
    // dist[n]=0;
    cout<<bfs(n,m)<<endl;
    return 0;
}