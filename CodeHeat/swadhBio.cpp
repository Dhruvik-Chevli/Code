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
void DSUinit(vector<ll>&a,vector<ll>&size,ll n)
{
    FOR(i,0,n)
    {
        a[i]=i;
        size[i]=1;
    }
    return;
}
ll root(vector<ll>&a,ll i)
{
    return (i==a[i])?i:a[i]=root(a,a[i]);
}
bool DSUfind(vector<ll>a,ll x,ll y)
{
    if(root(a,x)==root(a,y))
    {
        return true;
    }
    return false;
}
void DSUunion(vector<ll>&a,vector<ll>&size, ll x,ll y)
{
    x=root(a,x);
    y=root(a,y);
    if(x==y)
    {
        return;
    }
    if(size[x]<size[y]) swap(x,y);
    a[y]=x;
    size[x]+=size[y];
}
void dfs(vector<vector<ll> >&graph,vector<bool>&visited,ll start)
{
    visited[start]=true;
    FOR(i,0,graph[start].size())
    {
        if(!(visited[graph[start][i]]))
        {
            dfs(graph,visited,graph[start][i]);
        }
    }
    return;
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
long long subarrayXor(int arr[], int n, int m) 
{ 
    long long ans = 0; // Initialize answer to be returned 
  
    // Create a prefix xor-sum array such that 
    // xorArr[i] has value equal to XOR 
    // of all elements in arr[0 ..... i] 
    int* xorArr = new int[n]; 
  
    // Create map that stores number of prefix array 
    // elements corresponding to a XOR value 
    unordered_map<int, int> mp; 
  
    // Initialize first element of prefix array 
    xorArr[0] = arr[0]; 
  
    // Computing the prefix array. 
    for (int i = 1; i < n; i++) 
        xorArr[i] = xorArr[i - 1] ^ arr[i]; 
  
    // Calculate the answer 
    for (int i = 0; i < n; i++) { 
        // Find XOR of current prefix with m. 
        int tmp = m ^ xorArr[i]; 
  
        // If above XOR exists in map, then there 
        // is another previous prefix with same 
        // XOR, i.e., there is a subarray ending 
        // at i with XOR equal to m. 
        ans = ans + ((long long)mp[tmp]); 
  
        // If this subarray has XOR equal to m itself. 
        if (xorArr[i] == m) 
            ans++; 
  
        // Add the XOR of this subarray to the map 
        mp[xorArr[i]]++; 
    } 
  
    // Return total count of subarrays having XOR of 
    // elements as given value m 
    return ans; 
} 
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        // ll n;
        // cin>>n;
        string s;
        cin>>s;
        int n=s.size();
        int arr[s.size()];
        FOR(i,0,n)
        {
            arr[i]=(1<<(s[i]-'a'));
        }
        cout<<subarrayXor(arr,n,0)<<"\n";
    }
    return 0;
}