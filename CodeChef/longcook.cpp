#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
#define FOR(i,a,b) for (ll i=a;i<b;i++)
using namespace std;
bool isleap(ll y)
{
    if (y%400==0)
    {
        return true;
    }
    if (y%100==0)
    {
        return false;
    }
    if (y%4==0)
    {
        return true;
    }
    return false;
}
ll countSatSun(ll m1,ll m2,ll y1,ll y2,ll year[])
{
    ll count = 0;
    FOR(i,y1,y2+1)
    {
        if (m1>2 and i==y1)
            continue;
        if (m2<2 and i==y2)
            continue;
        if(isleap(i))
        {
            if(year[i%400]==6)
                count+=1;
        }
        else
        {
            if (year[i%400]==6||year[i%400]==0)
                count+=1;
        }  
    }
    return count;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    ll year400[]={2,4,5,6,0,2,3,4,5,0,1,2,3,5,6,0,1,3,4,5,6,1,2,3,4,6,0,1,2,4,5,6,0,2,3,4,5,0,1,2,3,5,6,0,1,3,4,5,6,1,2,3,4,6,0,1,2,4,5,6,0,2,3,4,5,0,1,2,3,5,6,0,1,3,4,5,6,1,2,3,4,6,0,1,2,4,5,6,0,2,3,4,5,0,1,2,3,5,6,0,1,2,3,4,5,0,1,2,3,5,6,0,1,3,4,5,6,1,2,3,4,6,0,1,2,4,5,6,0,2,3,4,5,0,1,2,3,5,6,0,1,3,4,5,6,1,2,3,4,6,0,1,2,4,5,6,0,2,3,4,5,0,1,2,3,5,6,0,1,3,4,5,6,1,2,3,4,6,0,1,2,4,5,6,0,2,3,4,5,0,1,2,3,5,6,0,1,3,4,5,6,0,1,2,3,5,6,0,1,3,4,5,6,1,2,3,4,6,0,1,2,4,5,6,0,2,3,4,5,0,1,2,3,5,6,0,1,3,4,5,6,1,2,3,4,6,0,1,2,4,5,6,0,2,3,4,5,0,1,2,3,5,6,0,1,3,4,5,6,1,2,3,4,6,0,1,2,4,5,6,0,2,3,4,5,0,1,2,3,5,6,0,1,3,4,5,6,1,2,3,4,5,6,0,1,3,4,5,6,1,2,3,4,6,0,1,2,4,5,6,0,2,3,4,5,0,1,2,3,5,6,0,1,3,4,5,6,1,2,3,4,6,0,1,2,4,5,6,0,2,3,4,5,0,1,2,3,5,6,0,1,3,4,5,6,1,2,3,4,6,0,1,2,4,5,6,0,2,3,4,5,0,1,2,3,5,6,0,1,3,4,5,6,1,2,3,4,6,0,1};
    ll countD=101;
    while (t--)
    {
        ll m1,m2,y1,y2;
        cin>>m1>>y1>>m2>>y2;
        ll count=0;
        if (y2-y1<400)
        {
            count=countSatSun(m1,m2,y1,y2,year400);
        }
        else
        {
            ll y11=y1-(y1%400)+400;
            ll y22=y2-(y2%400);
            count=((y22-y11)/400)*countD;
            count+=countSatSun(m1,1,y1,y11,year400);
            count+=countSatSun(12,m2,y22,y2,year400);
        }
        cout<<count<<"\n";
    }
    return 0;
}