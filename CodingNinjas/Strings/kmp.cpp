#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<unordered_set>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
int* getLPS(string pattern)
{
    int* lps=new int[pattern.length()];
    int len=pattern.length();
    lps[0]=0;
    int i=1;
    int j=0;
    while(i<len)
    {
        if(pattern[i]==pattern[j])
        {
            lps[i]=j+1;
            i++;
            j++;
        }
        else{
            if(j!=0)
            {
                j=lps[j-1];
            }else {
                lps[i]=0;
                i++;
            }
        }    
    }
    return lps;
}

int kmpSearch(string text,string pattern)
{
    int lenText=text.length();
    int lenPat=pattern.length();

    int i=0;
    int j=0;
    int* lps= getLPS(pattern);
    while(i<lenText and j<lenPat)
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }
        else{
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
            
        }
    }
    if(j==lenPat)
        return i-j;
    else
    {
        return -1;
    }
    
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    string b;
    cin>>a;
    cin>>b;
    cout<<kmpSearch(a,b)<<endl;
    return 0;
}