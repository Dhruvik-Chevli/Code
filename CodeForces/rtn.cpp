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
    ll n,m;
    cin>>n>>m;
    ll count=0;
    if(m%n!=0)
    {
        cout<<-1<<endl;
        return 0;
    }
    ll k=m/n;
    while(k%6==0)
    {
        count+=2;
        k/=6;
    }
    while(k%3==0)
    {
        count+=1;
        k/=3;
    }
    while(k%2==0)
    {
        count+=1;
        k/=2;
    }
    if(k==1)
    {
        cout<<count<<"\n";
    }
    else
    {
        cout<<-1<<"\n";
    }   
    return 0;
}