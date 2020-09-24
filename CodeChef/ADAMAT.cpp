#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> >v(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>v[i][j];
            }
        }
        int count=0;
        int i=1;
        while(i<n and v[0][i]!=i+1)
        {
            i++;
        }
        if(i>1)
        {
            count=1;
        }
        while(i<n)
        {
            int cur=0;
            if(v[0][i]==i+1)
            {
                i++;
                continue;
            }
            while(i<n and v[0][i]!=i+1)
            {
                cur+=1;
                i+=1;
            }
            if(cur>0)
            {
                count+=2;
            }
        }
        cout<<count<<"\n";
    }
}