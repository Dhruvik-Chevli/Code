
#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_set>
#include<stack>
#include<queue>
#include<unordered_map>
#include<cstring>
#include<climits>

using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

  
// Function to find minimum swaps 
int findMinimumAdjacentSwaps(int arr[], int N) 
{ 
    // visited array to check if value is seen already 
    bool visited[N + 1]; 
  
    int minimumSwaps = 0; 
    //memset(visited, false, sizeof(visited)); 
    for(int i=0;i<N+1;i++)
    {
        visited[i]=false;
    }
  
    for (int i = 0; i < 2 * N; i++) { 
  
        // If the arr[i] is seen first time 
        if (visited[arr[i]] == false) { 
            visited[arr[i]] = true; 
  
            // stores the number of swaps required to 
            // find the correct position of current 
            // element's partner 
            int count = 0; 
  
            for (int j = i + 1; j < 2 * N; j++) { 
  
                // Increment count only if the current 
                // element has not been visited yet (if is 
                // visited, means it has already been placed 
                // at its correct position) 
                if (visited[arr[j]] == false) 
                    count++; 
  
                // If current element's partner is found 
                else if (arr[i] == arr[j]) 
                    minimumSwaps += count; 
            } 
        } 
    } 
    return minimumSwaps; 
} 
  
// Driver Code 
int main() 
{ 
    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--)
    {
        int p;
        cin>>p;
        //p<<=1;
        int v[2*p];
        FOR(i,0,2*p)
        {
            cin>>v[i];
        }
        //p>>=1;
        int o=findMinimumAdjacentSwaps(v,p);
        
        unordered_map<int,int>f;
        unordered_map<int,int>s;
        int num;
        
        int mi=INT_MAX;
        p<<=1;
        FOR(i,0,p)
        {
            if(f.count(v[i])>0)
            {
                s[v[i]]=i;
                int k=f[v[i]]+(p-i-1);
                if(k<mi)
                {
                    mi=k;
                    num=v[i];
                }
            }
            else
            {
                f[v[i]]=i;
            }
        }
        int ans=mi;
        //cout<<num<<"\n";
        for(int j=f[num];j>0;j--)
        {
            //cout<<v[j]<<" "<<v[j-1];
            swap(v[j],v[j-1]);
        }
        for(int i=s[num];i<p-1;i++)
        {
            //cout<<i<<"\n";
            swap(v[i],v[i+1]);
        }
        // FOR(i,0,p)
        // {
        //     cout<<v[i]<<" ";
        // }
        // cout<<"\n";
        int l[p-2];
        for(int i=1;i<p-1;i++)
        {
            l[i]=v[i];
        }
        //p>>=1;
        p=p-2;
        p>>=1;
        int u=findMinimumAdjacentSwaps(l,p);
        //cout<<u<<"\n";
        u+=ans;
        cout<<min(o,u)<<"\n";

    }
    
    //cout << findMinimumAdjacentSwaps(arr, N) << endl; 
    return 0; 
} 