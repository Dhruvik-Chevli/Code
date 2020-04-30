#include <string>
#include<cstring>
#include<iostream>
using namespace std; 
  
#define ll long long int 
const ll MOD = 1e9 + 7; 
  
// Returns modulo exponentiation for two numbers 
// represented as long long int. It is used by 
// powerStrings(). Its complexity is log(n) 
ll powerLL(ll x, ll n) 
{ 
    ll result = 1; 
    while (n) { 
        if (n & 1) 
            result = result * x % MOD; 
        n = n / 2; 
        x = x * x % MOD; 
    } 
    return result; 
} 
  
// Returns modulo exponentiation for two numbers 
// represented as strings. It is used by 
// powerStrings() 
ll powerStrings(string sa, string sb) 
{ 
    // We convert strings to number  
  
    ll a = 0, b = 0; 
  
    // calculating  a % MOD 
    for (int i = 0; i < sa.length(); i++) 
        a = (a * 10 + (sa[i] - '0')) % MOD; 
  
    // calculating  b % (MOD - 1) 
    for (int i = 0; i < sb.length(); i++) 
        if(i==sb.length()-1)
        {
            b = (b * 10 + (sb[i] - '0'-1)) % (MOD - 1);
        }
        else
            b = (b * 10 + (sb[i] - '0')) % (MOD - 1); 
  
    // Now a and b are long long int. We 
    // calculate a^b using modulo exponentiation 
    return powerLL(a, b); 
} 
  
int main() 
{ 
    // As numbers are very large 
    // that is it may contains upto 
    // 10^6 digits. So, we use string. 
    ll t;
    cin>>t;
    while(t--){
    string sb;
    cin>>sb;
    int len=sb.length();
    //cout<<len<<endl; 
    //cout<<((sb[len-1]-'0')+1)<<endl;
    //cout<<sb<<endl;
    cout << powerStrings("2", sb)-2<< endl;
    } 
    return 0; 
} 