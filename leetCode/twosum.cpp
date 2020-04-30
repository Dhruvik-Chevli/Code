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
vector<int> twoSum(vector<int>& num, int target) {
        int i=0;
        int j=num.size()-1;
        vector<int>ans(2,0);
        vector<pair<int,int> >nums;
        FOR(k,0,num.size())
        {
            nums.push_back(make_pair(num[k],k));
        }
        sort(nums.begin(),nums.end());
        FOR(i,0,nums.size())
        {
            cout<<nums[i].first<<" "<<nums[i].second<<endl;
        }
        while(i<j)
        {
            if(nums[i].first+nums[j].first<target)
            {
                i+=1;
            }
            else if(nums[i].first+nums[j].first>target)
            {
                j-=1;
            }
            else
            {
                ans[0]=nums[i].second;
                ans[1]=nums[j].second;
                break;
            } 
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>nums(n,0);
    FOR(i,0,n)
    {
        cin>>nums[i];
    }
    int k;
    cin>>k;
    vector<int>ans=twoSum(nums,k);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}