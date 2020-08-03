#include<iostream>
#include<string>
using namespace std;
string licenseKeyFormatting(string S, int K) {
        int cur=0;
        string s="";
        for(int i=S.size()-1;i>=0;i--)
        {
            if(S[i]=='-')
            {
                continue;
            }
            s=S[i]+s;
            cur+=1;
            // cout<<s;
            if(cur==K and i!=0)
            {
                s='-'+s;
                cur=0;
            }
        }
        return s;
    }
int main()
{
    string s;
    int k;
    cin>>s>>k;
    cout<<licenseKeyFormatting(s,k);
}