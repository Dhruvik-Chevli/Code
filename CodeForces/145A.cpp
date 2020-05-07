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
    string a;
    string b;
    cin>>a>>b;
    ll c47=0;
    ll c74=0;
    FOR(i,0,a.length())
    {
        if(a[i]=='4' and b[i]=='7')
        {
            c47+=1;
        }
        else if(a[i]=='7' and b[i]=='4')
        {
            c74+=1;
        }
    }
    cout<<max(c74,c47)<<endl;
    return 0;
}