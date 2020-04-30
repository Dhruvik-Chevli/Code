#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll l,r;
    cin>>l>>r;
    string a="",ma="";
    for(ll i=0;i<l;i++)
    {
        a+="0";
    }
    ma=a;
    ll li,ri;
    for(ll i=0;i<r;i++)
    {   
        cin>>li>>ri;
        for(ll j=li-1;j<ri;j++)
        {
            if((a[j]-'0')==0)
                a[j]='1';
            else if((a[j]-'0')==1)
            {
                a[j]='0';
            }
                 
        }
        ma=max(ma,a);
        //cout<<a<<" "<<max<<endl;
    }
    cout<<ma<<endl;
    return 0;
}
/*
9 5
2 2
5 5
4 4
3 3
1 9
*/
