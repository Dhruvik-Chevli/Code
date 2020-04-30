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
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        string a;
        vector<vector<int> >sud(9,vector<int>(9,0));
        FOR(i,0,9)
        {
            cin>>a;
            FOR(j,0,a.length())
            {
                sud[i][j]=a[j]-'0';
            }
        }
        sud[0][0]=((sud[0][0]+1)%10);
        {
            if(sud[0][0]==0)
            {
                sud[0][0]=1;
            }
        }
        sud[1][3]=((sud[1][3]+1)%10);
        {
            if(sud[1][3]==0)
            {
                sud[1][3]=1;
            }
        }
        sud[2][6]=((sud[2][6]+1)%10);
        {
            if(sud[2][6]==0)
            {
                sud[2][6]=1;
            }
        }
        sud[3][1]=((sud[3][1]+1)%10);
        {
            if(sud[3][1]==0)
            {
                sud[3][1]=1;
            }
        }
        sud[4][4]=((sud[4][4]+1)%10);
        {
            if(sud[4][4]==0)
            {
                sud[4][4]=1;
            }
        }
        sud[5][7]=((sud[5][7]+1)%10);
        {
            if(sud[5][7]==0)
            {
                sud[5][7]=1;
            }
        }
        sud[6][2]=((sud[6][2]+1)%10);
        {
            if(sud[6][2]==0)
            {
                sud[6][2]=1;
            }
        }
        sud[7][5]=((sud[7][5]+1)%10);
        {
            if(sud[7][5]==0)
            {
                sud[7][5]=1;
            }
        }
        sud[8][8]=((sud[8][8]+1)%10);
        {
            if(sud[8][8]==0)
            {
                sud[8][8]=1;
            }
        }
        FOR(i,0,9)
        {
            FOR(j,0,9)
            {
                cout<<sud[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}