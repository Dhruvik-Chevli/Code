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
    ll n,k,x;
    cin>>n>>k>>x;
    ll no;
    vector<ll>arr(1001,0);
    FOR(i,0,n)
    {
        cin>>no;
        arr[no]+=1;
    }
    /*FOR(i,0,1001)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;*/
    FOR(i,0,k)
    {
        ll count=0;
        vector<ll>arr2(1001,0);
        FOR(j,0,1001)
        {
            if((count&1)==0)
            {
                if(arr[j]&1)
                {
                    arr2[x^j]+=(arr[j]/2+1);
                }
                else
                {
                    arr2[x^j]+=(arr[j]/2);
                }
                arr2[j]+=(arr[j]/2);
                count+=arr[j];
            }
            else
            {
                if(arr[j]&1)
                {
                    arr2[x^j]+=(arr[j]/2);
                    arr2[j]+=(arr[j]/2+1);
                }
                else
                {
                    arr2[x^j]+=(arr[j]/2);
                    arr2[j]+=(arr[j]/2);
                }
                count+=arr[j];
            }
            
        }
        arr=arr2;
    }
    ll min=-1;
    ll max=-1;
    FOR(i,0,1001)
    {
        if(arr[i]!=0)
        {
            min=i;
            break;
        }
    }
    for(int i=1000;i>=0;i--)
    {
        if(arr[i]!=0)
        {
            max=i;
            break;
        }
    }
    cout<<max<<" "<<min<<endl;
    return 0;
}