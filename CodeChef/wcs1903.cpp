#include<iostream>
#include<algorithm>
#include<vector>
#define pb push_back;
typedef long long int ll;
using namespace std;
ll sumPairs(vector<ll> arr,ll n) 
{  
    ll sum = 0; 
    for (ll i=n-1; i>=0; i--) 
        sum += ((((i%1000000007*arr[i]%1000000007)%1000000007) - ((n-1-i)%1000000007*arr[i]%1000000007)%1000000007)%1000000007); 
    return sum; 
} 
int main()
{
    vector<ll>lt,rt,l,r;
    ll n;
    ll le,ri;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>le>>ri;
        l.push_back(le);
        r.push_back(ri);
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    vector<ll>::iterator it;
    //it=unique(l.begin(),l.end());
    //l.resize(distance(l.begin(),it));
    //it=unique(r.begin(),r.end());
    //r.resize(distance(r.begin(),it));
    ll sl=sumPairs(l,n)%1000000007;
    ll sr=sumPairs(r,n)%1000000007;
    ll ans=(sl+sr)%1000000007;
    cout<<ans<<endl;
    return 0;

}