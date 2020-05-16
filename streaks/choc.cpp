#include<iostream>
#include<cstring>
using namespace std;

int mid[1000100];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b;
        long long ban=0;
        scanf("%lld %lld",&a,&b);
        memset(mid,0,sizeof(mid));
        for(int i=0;i<a;i++)
            mid[(i)^(a-i-1)]++;
        for(int j=0;j<b;j++)
            ban+=mid[(j)^(b-j-1)];
        printf("%lld\n",a*b-ban);
    }
}