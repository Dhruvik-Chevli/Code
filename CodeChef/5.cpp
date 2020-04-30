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
bool ifPossible(int k,vector<vector<int> >&grid,int r,int c,int n)
{
    FOR(i,0,n)
    {
        if(k==grid[i][c])
        {
            return false;
        }
        if(k==grid[r][i])
        {
            return false;
        }
    }
    return true;
}
bool solve(int n,vector<vector<int> >&grid,int k,int r,int c)
{
    if(r==n-1 and c==n-1)
    {
        int sum=0;
        FOR(i,0,n-1)
        {
            sum+=grid[i][i];
        }
        if(k-sum<=n && k-sum>0)
        {
            if(ifPossible(k-sum,grid,n-1,n-1,n))
            {
                grid[n-1][n-1]=k-sum;
                return true;
            }
        }
        return false;
    }
    if(c>n-1)
    {
        return solve(n,grid,k,r+1,0);
    }
    if(grid[r][c]!=0)
    {
        return solve(n,grid,k,r,c+1);
    }
    FOR(i,1,n+1)
    {
        if(ifPossible(i,grid,r,c,n))
        {
            grid[r][c]=i;
            if(solve(n,grid,k,r,c+1))
                return true;
            grid[r][c]=0;
        }
    }
    return false;

}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    FOR(r,1,t+1)
    {
        ll n,k;
        cin>>n>>k;
        vector<vector<int> >mat(n,vector<int>(n,0));
        if(solve(n,mat,k,0,0))
        {
            cout<<"Case #"<<r<<": "<<"POSSIBLE\n";
            FOR(i,0,n)
            {
                FOR(j,0,n)
                {
                    cout<<mat[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        else
        {
            cout<<"Case #"<<r<<": "<<"IMPOSSIBLE\n";
        }
    }
    return 0;
}