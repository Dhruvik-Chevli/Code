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
    while(1)
    {
        ll n;
        cin>>n;
        if(n==0)
            break;
        unordered_map<string,ll>map;
        ll max=0;
        FOR(i,0,n)
        {
            vector<ll>v(5);
            FOR(i,0,5)
            {
                cin>>v[i];
            }
            sort(v.begin(),v.end());
            string a;
            a=to_string(v[0])+to_string(v[1])+to_string(v[2])+to_string(v[3])+to_string(v[4]);
            if(map[a].count>0)
            {
                map[a]+=1;
                if(map[a]>max)
                {
                    max=map[a];
                }
            }
            else
            {
                map[a]=1;
                if(max<1)
                {
                    max=1;
                }
            }
        }
        ll count=0;
        unordered_map<string,ll>::iterator it1=map.begin();
        while(it1!=map.end())
        {
            if(it1->second==max)
            {
                count+=max;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}