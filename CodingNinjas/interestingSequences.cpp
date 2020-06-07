#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {

	int n,k,l;
    cin>>n>>k>>l;
    vector<int>a;
    cin>>a[0];
    int ma=a[0];
    int mi=a[0];
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        ma=max(ma,a[i]);
        mi=min(ma,a[i]);
    }
    int ans=1e9;
    for(int j=mi;j<=ma;j++)
    {
        int inc=0,dec=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<j) inc+=j-a[i];
            else
                dec+=a[i]-j;
        }
        if(dec>inc) continue;
        ans=min(ans,inc*l+(inc-dec)*k);
    }
    cout<<ans<<endl;
    return 0;
}