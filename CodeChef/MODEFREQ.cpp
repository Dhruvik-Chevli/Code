#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        vector<int> freq(11);
        for(int i = 0; i < n; i++)
        {
            cin>>v[i];
            freq[v[i]]++;
        }
        map<int, int> m;
        for (int i = 1; i <= 10; i++)
        {
            m[freq[i]]++;
        }
        int max = 0;
        int ans = 0;
        for(auto i : m)
        {
            
            if (i.first != 0)
            {
                if (i.second > max)
                {
                    max = i.second;
                    ans = i.first;
                }
                else if (i.second == max && i.first < ans)
                {
                    ans = i.first;
                }
            }
            
            
        }
        cout<<ans<<"\n";
    }
}