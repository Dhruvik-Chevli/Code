#include <iostream>
#include<string>
#include<algorithm>
#define ll long long int
#define FOR(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
int alphaCode(string a,int size)
{
    int* arr=new int[size+1]();
    arr[0]=1;
    arr[1]=1;
    FOR(i,2,size+1)
    {
        if(a[i]=='0')
        {
            arr[i]=arr[i-1];
            continue;
        }
        arr[i]=arr[i-1];
        if((a[i-2]-'0')*10+(a[i-1]-'0')<=26 and (a[i-2]-'0')*10+(a[i-1]-'0')>=10)
            {
                arr[i]=(arr[i]+arr[i-2])%1000000007;
            }
        cout<<a[i]<<" "<<arr[i]<<endl;
    }
    FOR(i,0,size+1)
    {
        cout<<a[i]<<" "<<arr[i]<<" "<<endl;
    }
    cout<<endl;
    return arr[size];
}
int main()
{
    int k=1;
    while(k)
    {
        string a;
        cin>>a;
        if(a.length()==1 and a[0]=='0')
            break;
        cout<<alphaCode(a,a.length())<<endl;
    }
    return 0;
}
