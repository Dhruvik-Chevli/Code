#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<stack>
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
        vector<ll>v(n,0);
        vector<ll>heap;
        ll k;
        FOR(i,0,n)
        {
            cin>>k;
            v[i]=k;
            heap.pb(k);
        }
        //cout<<heap.size()<<endl;
        make_heap(heap.begin(),heap.end());
        //cout<<heap.size()<<endl;
        //cout<<heap.front()<<endl;
        //pop_heap(heap.begin(),heap.end());
        //heap.pop_back();
        //cout<<heap.front()<<" "<<heap.size();
        vector<ll>map(1000001,0);
        FOR(i,0,n)
        {
            map[v[i]]=1;
            int flag=0;
            if(map[heap.front()]==1)
            {
                flag=1;
                while(map[heap.front()]==1 and heap.size()>0)
                {
                    cout<<heap.front()<<" ";
                    pop_heap(heap.begin(),heap.end());
                    heap.pop_back();
                }
                cout<<"\n";
            }
            if(flag==0)
            {
                cout<<"Not possible\n";
            }
        }
    }
    return 0;
}