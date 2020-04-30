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
bool comp(string a, string b)
{
    int n=a.size();
    int m=b.size();
    int si=(n<m)?n:m;
    string a1=a.substr(0,si);
    string b1=b.substr(0,si);
    if(a1==b1)
    {
        return (a.size()>b.size())?0:1;
    }
    return (a1>b1);
}
string largestNumber(const vector<int> &A) {
    vector<string> ans(A.size());
    for(int i=0;i<A.size();i++)
    {
        string s=std::to_string(A[i]);
        ans[i]=s;
    }
    sort(ans.begin(),ans.end(),comp);
    string s="";
    for(i,0,ans.size())
    {
        s+=ans[i];
    }
    return s;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>arr(5);
    arr[0]=3;
    arr[1]=30;
    arr[2]=34;
    arr[3]=5;
    arr[4]=9;
    largestNumber(arr);
    return 0;
}