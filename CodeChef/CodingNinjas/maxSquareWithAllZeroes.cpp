#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
int findMaxSquareWithAllZeros(int** arr,int n,int m)
{
    int** dp=new int*[n];
    FOR(i,0,n)
        dp[i]=new int[m];
    FOR(i,0,n)
    {
        if(arr[i][0]==0)
            dp[i][0]=1;
    }
    FOR(i,0,m)
    {
        if(arr[0][i]==0)
            dp[0][i]=1;
    }
    FOR(i,1,n)
    {
        FOR(j,1,m)
        {
            if(arr[i][j]==0)
            {
                int dis=dp[i-1][j-1];
                int flagv=1;
                int flagh=1;
                int vcount=0;
                FOR(k,0,dis)
                {
                    if(arr[i-k-1][j]==1)
                    {
                        //cout<<"&";
                        flagv=0;
                        break;
                    }
                    vcount+=1;
                }
                int hcount=0;
                if(1)
                {
                    FOR(k,0,dis)
                    {
                        //cout<<"*";
                        if(arr[i][j-k-1]==1)
                        {
                          //  cout<<"(";
                            flagh=0;
                            break;
                        }
                        hcount+=1;
                    }
                }
                if(flagv && flagh)
                {
                    dp[i][j]=dis+1;
                }
                else if(flagv!=0 && flagh!=0)
                {
                    dp[i][j]=(hcount>vcount)?hcount:vcount+1;
                }
                else
                {
                    dp[i][j]=1;
                }
            }
            else
                dp[i][j]=0;
        }
    }
    FOR(i,0,n)
    {
        FOR(j,0,m)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }
    int max=0;
    FOR(i,0,n)
        FOR(j,0,m)
            if(dp[i][j]>max)
                max=dp[i][j];
    return max;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int** mat=new int*[n];
    FOR(i,0,n)
        mat[i]=new int[m];
    FOR(i,0,n)
        FOR(j,0,m)
            cin>>mat[i][j];
    cout<<findMaxSquareWithAllZeros(mat,n,m)<<endl;
    return 0;
}