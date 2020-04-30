#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    while(t--){
        vector<long long int>v;
        long long int n;
        cin>>n;
        long long int k;
        for(int i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        //sort(v.begin(),v.end());
        long long int nt=count(v.begin(),v.end(),2);
        long long int nz=count(v.begin(),v.end(),0);
        long long int ans=((nt)*(nt-1))/2+((nz)*(nz-1))/2;
        cout<<ans<<endl;
    }    
}