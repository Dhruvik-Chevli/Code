#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<stack>
using namespace std;
typedef long long int ll;
#define EPS 1e-9
#define pb push_back
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define PI 3.1415926535897932384626433832795
#define MOD 998244353
ll gcdExtended(ll a, ll b, ll *x, ll *y); 
ll power(ll x,ll y) 
{ 
    ll res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x); 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = x*x;  // Change x to x^2 
    } 
    return res; 
}
  
// Function to find modulo inverse of a 
ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        //cout << "Inverse doesn't exist"; 
        return 0;
    else
    { 
        // m is added to handle negative x 
        ll res = (x%m + m) % m; 
        return res; 
    } 
} 
  
// C function for extended Euclidean Algorithm 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}
int prec(char x)
{
    if(x == '|' || x == '^' || x == '&')
        return 1;
    return -1;
}

void inToPost(string &s,string &p)
{
    stack<char>st;
    st.empty();
    //cout<<st.size();
    ll n=s.size();
    FOR(i,0,n)
    {
        if(s[i] == '#')
            p += s[i];
        else if(s[i] == '(')
        {
            st.push('(');
        }
        else if(s[i] == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                char c = st.top();
                st.pop();
                p += c;
            }
            if (!st.empty() && st.top() == '(')
            {
                char c = st.top();
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                char c = st.top();
                st.pop();
                p += c;
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        char c = st.top();
        st.pop();
        p += c;
    }
    return;
}
void solve(string s)
{
    stack<ll>p1,p0,pa,pA;
    p1.empty();
    p0.empty();
    pa.empty();
    pA.empty();
    ll n=s.length();
    FOR(i,0,n)
    {
        if(s[i]=='#')
        {
            p1.push(748683265);
            p0.push(748683265);
            pa.push(748683265);
            pA.push(748683265);
        }
        else if(s[i]=='&')
        {
            ll p0t=p0.top();
            p0.pop();
            ll p0st=p0.top();
            p0.pop();
            ll p1t=p1.top();
            p1.pop();
            ll p1st=p1.top();
            p1.pop();
            ll pat=pa.top();
            pa.pop();
            ll past=pa.top();
            pa.pop();
            ll pAt=pA.top();
            pA.pop();
            ll pAst=pA.top();
            pA.pop();
            ll ans0=((((((((p0t*p0st)%MOD+(p0t*p1st)%MOD)%MOD+(p0t*past)%MOD)%MOD+(p0t*pAst)%MOD)%MOD)+((((p0st*p1t)%MOD+(p0st*pat)%MOD)%MOD+(p0st*pAt)%MOD)%MOD))%MOD+(pAt*past)%MOD)%MOD+(pat*pAst)%MOD)%MOD;
            ll ans1=(p1t*p1st)%MOD;
            ll ansa=(((past*p1t)%MOD+(past*pat)%MOD)%MOD+(p1st*pat)%MOD)%MOD;
            ll ansA=(((pAst*p1t)%MOD+(pAst*pAt)%MOD)%MOD+(p1st*pAt)%MOD)%MOD;
            p0.push(ans0);
            p1.push(ans1);
            pa.push(ansa);
            pA.push(ansA);
        }
        else if(s[i]=='|')
        {
            ll p0t=p0.top();
            p0.pop();
            ll p0st=p0.top();
            p0.pop();
            ll p1t=p1.top();
            p1.pop();
            ll p1st=p1.top();
            p1.pop();
            ll pat=pa.top();
            pa.pop();
            ll past=pa.top();
            pa.pop();
            ll pAt=pA.top();
            pA.pop();
            ll pAst=pA.top();
            pA.pop();
            //ll ans1=((p1t*(p1st+past+pAst+p0st))%MOD+(p1st*(pat+pAt+p0t))%MOD+(past*pAt)%MOD+(pAst*pat)%MOD)%MOD;
            ll ans1=((((((((p1t*p1st)%MOD+(p1t*p0st)%MOD)%MOD+(p1t*past)%MOD)%MOD+(p1t*pAst)%MOD)%MOD)+((((p1st*p0t)%MOD+(p1st*pat)%MOD)%MOD+(p1st*pAt)%MOD)%MOD))%MOD+(pAt*past)%MOD)%MOD+(pat*pAst)%MOD)%MOD;
            ll ans0=(p0st*p0t)%MOD;
            ll ansa=(((p0st*pat)%MOD+(p0t*past)%MOD)%MOD+(pat*past)%MOD)%MOD;
            ll ansA=(((p0st*pAt)%MOD+(p0t*pAst)%MOD)%MOD+(pAt*pAst)%MOD)%MOD;
            p0.push(ans0);
            p1.push(ans1);
            pa.push(ansa);
            pA.push(ansA);
        }
        else if(s[i]=='^')
        {
            ll p0t=p0.top();
            p0.pop();
            ll p0st=p0.top();
            p0.pop();
            ll p1t=p1.top();
            p1.pop();
            ll p1st=p1.top();
            p1.pop();
            ll pat=pa.top();
            pa.pop();
            ll past=pa.top();
            pa.pop();
            ll pAt=pA.top();
            pA.pop();
            ll pAst=pA.top();
            pA.pop();
            ll ans0=((((pat*past)%MOD+(p0t*p0st)%MOD)%MOD+(p1t*p1st)%MOD)%MOD+(pAst*pAt)%MOD)%MOD;
            ll ans1=((((p0t*p1st)%MOD+(p1t*p0st)%MOD)%MOD+(pat*pAst)%MOD)%MOD+(pAt*past)%MOD)%MOD;
            ll ansa=((((pat*p0st)%MOD+(past*p0t)%MOD)%MOD+(p1t*pAst)%MOD)%MOD+(p1st*pAt)%MOD)%MOD;
            ll ansA=((((pat*p1st)%MOD+(past*p1t)%MOD)%MOD+(p0st*pAt)%MOD)%MOD+(pAst*p0t)%MOD)%MOD;
            p0.push(ans0);
            p1.push(ans1);
            pa.push(ansa);
            pA.push(ansA);
        }
    }
    ll count=0;
    FOR(i,0,n)
    {
        if(s[i]=='#')
        {
            count+=1;
        }
    }
    ll ans0=((p0.top()%MOD));
    ll ans1=((p1.top()%MOD));
    ll ansa=((pa.top()%MOD));
    ll ansA=((pA.top()%MOD));
    cout<<ans0<<" "<<ans1<<" "<<ansa<<" "<<ansA<<endl;
    //cout<<p0.size()<<p1.size()<<pa.size()<<pA.size()<<endl;
    //cout<<p0.top()*power(4,count)<<" "<<p1.top()*power(4,count)<<" "<<pa.top()*power(4,count)<<" "<<pA.top()*power(4,count)<<endl;
    //cout<<modInverse(p0.top()*power(4,count),MOD)<<" "<<modInverse(p1.top()*power(4,count),MOD)<<" "<<modInverse(pa.top()*power(4,count),MOD)<<" "<<modInverse(pA.top()*power(4,count),MOD)<<endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string post="";
        inToPost(s,post);
        //cout<<post<<endl;
        solve(post);
    }
    return 0;
}