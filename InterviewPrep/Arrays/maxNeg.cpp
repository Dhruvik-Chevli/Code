#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<climits>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
vector<int>maxset(vector<int> &A) {
    long long int max=-INT_MAX+1;
    int i=0;
    int cursum=0;
    vector<vector<int> >sub;
    int n=A.size();
    while(i<n)
    {
        int j=i;
        vector<int>cur;
        while(A[j]>=0 and j<n)
        {
            cur.push_back(A[j]);
            j+=1;
        }
        sub.push_back(cur);
        i=j+1;
    }
    vector<int>ansf;
    // for(int i=0;i<sub.size();i++)
    // {
    //     for(int j=0;j<sub[i].size();j++)
    //     {
    //         cout<<sub[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<sub.size();i++)
    {
        long long int sum=0;
        for(int j=0;j<sub[i].size();j++)
        {
            sum+=sub[i][j];
            //cout<<"****";
        }
        if(sum>max)
        {
            //cout<<sum<<" "<<i<<endl;
            ansf=sub[i];
            max=sum;
        }
    }
    return ansf;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr(n);
    FOR(i,0,n)
    {
        cin>>arr[i];
    }
    maxset(arr);
    
    return 0;
}