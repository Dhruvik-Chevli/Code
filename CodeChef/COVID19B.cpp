#include<iostream>
#include<vector>
#include<utility>
#include<set>
#include<limits>
#include<algorithm>
#include<climits>
#define ll long long int
#define FOR(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>sp(n,0);
        FOR(i,0,n)
            cin>>sp[i];
        vector<ll>br(n,1);
        FOR(i,0,n)
        {
            FOR(j,i+1,n)
            {
                if(sp[i]>sp[j])
                {
                    br[i]+=1;
                }
            }
        }
        vector<ll>bl(n,1);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(sp[j]>sp[i])
                {
                    br[i]+=1;
                }
            }
        }
        ll mi=INT_MAX;
        ll ma=INT_MIN;
        FOR(i,0,n)
        {
            if(mi>br[i])
            {
                mi=br[i];
            }
            if(ma<br[i])
            {
                ma=br[i];
            }
        }
        cout<<mi<<" "<<ma<<"\n";
    }
}