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
void DSUinit(vector<ll>&size,vector<ll>&v, ll n)
{
    FOR(i,0,n)
    {
        size[i]=1;
        v[i]=i;
    }
    return;
}
ll DSUroot(vector<ll>&v,ll i)
{
    return (v[i]==i)?i:v[i]=DSUroot(v,v[i]);
}
ll DSUfind(vector<ll>&v,ll x,ll y)
{
    if(DSUroot(v,x)==DSUroot(v,y))
    {
        return true;
    }
    return false;
}
ll DSUunion(vector<ll>&v, vector<ll>&size,ll x,ll y)
{
    x=DSUroot(v,x);
    y=DSUroot(v,y);
    if(x==y)
    {
        return;
    }
    
}
bool isPrime(int n) 
{
    if (n <= 1)  return false; 
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
          return false;
    return true; 
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}