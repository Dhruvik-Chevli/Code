#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
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
        ll n;
        cin>>n;
        vector<ll>b(n);
        FOR(i,0,n)
        {
            cin>>b[i];
        }
        unordered_map<ll,ll>umap;
        ll sum=0;
        vector<int>a(n+1);
        a[0]=0;
        FOR(i,1,n+1)
        {
            a[i]=b[i-1]+a[i-1];
        }
        FOR(i,0,n+1)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        umap[0]=1;
        FOR(i,1,n)
        {
            sum+=a[i];
            if(umap.count(sum))
            {
                sum+=(i-umap[a[i]]-1);
                umap[a[i]]=i;
            }
            else
            {
                sum+=(n-i);
                umap[a[i]]=i;
            }
        }
        unordered_map<ll, ll>:: iterator p;
        ll ans=0;
        for(p=umap.begin();p!=umap.end();p++)
        {
            if(p->second>1)
            {
                ans+=(p->second*(p->second-1)/2);
            }
        }
        cout<<(n*(n+1)/2)-ans<<endl; 
    }
    return 0;
}