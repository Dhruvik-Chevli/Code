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
#define MOD 1000000007
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
void inToPost(string &s,string &post)
{
    stack<char>st;
    st.empty();
    //cout<<st.size();
    ll n=s.size();
    FOR(i,0,n)
    {
        //cout<<s[i];
        if(s[i]=='(')
        {
            st.push('(');
        }
        else if(s[i]==')')
        {
            while(st.top()!='(')
            {
                post+=st.top();
                st.pop();
            }
            st.pop();
        }
        else if(s[i]=='|' or s[i]=='&' or s[i]=='^')
        {
            if(st.top()=='(')
            {
                st.push(s[i]);
            }
            else{
                post+=st.top();
                st.pop();
                st.push(s[i]);
            }        
        }
        else
        {
            post+=s[i];
        }
    }
    //cout<<endl;
    // FOR(i,0,st.size())
    // {
    //     cout<<st.top()<<endl;
    //     st.pop();
    // }
    while(st.size()!=0)
    {
        post+=st.top();
        st.pop();
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
            p1.push(1);
            p0.push(1);
            pa.push(1);
            pA.push(1);
        }
        else if(s[i]=='&')
        {
            int p0t=p0.top();
            p0.pop();
            int p0st=p0.top();
            p0.pop();
            int p1t=p1.top();
            p1.pop();
            int p1st=p1.top();
            p1.pop();
            int pat=pa.top();
            pa.pop();
            int past=pa.top();
            pa.pop();
            int pAt=pA.top();
            pA.pop();
            int pAst=pA.top();
            pA.pop();
            ll ans0=((p0t*((p0st+p1st+past+pAst)%998244353))%998244353+(p0st*((p1t+pat+pAt)%998244353))%998244353+(pAt*past)%998244353+(pat*pAst)%998244353)%998244353;
            ll ans1=(p1t*p1st)%998244353;
            ll ansa=((past*p1t)%998244353+(past*pat)%998244353+(p1st*pat)%998244353)%998244353;
            ll ansA=((pAst*p1t)%998244353+(pAst*pAt)%998244353+(p1st*pAt)%998244353)%998244353;
            p0.push(ans0);
            p1.push(ans1);
            pa.push(ansa);
            pA.push(ansA);
        }
        else if(s[i]=='|')
        {
            int p0t=p0.top();
            p0.pop();
            int p0st=p0.top();
            p0.pop();
            int p1t=p1.top();
            p1.pop();
            int p1st=p1.top();
            p1.pop();
            int pat=pa.top();
            pa.pop();
            int past=pa.top();
            pa.pop();
            int pAt=pA.top();
            pA.pop();
            int pAst=pA.top();
            pA.pop();
            ll ans1=((p1t*(p1st+past+pAst+p0st))%998244353+(p1st*(pat+pAt+p0t))%998244353+(past*pAt)%998244353+(pAst*pat)%998244353)%998244353;
            ll ans0=(p0st*p0t)%998244353;
            ll ansa=((p0st*pat)%998244353+(p0t*past)%998244353+(pat*past)%998244353)%998244353;
            ll ansA=((p0st*pAt)%998244353+(p0t*pAst)%998244353+(pAt*pAst)%998244353)%998244353;
            p0.push(ans0);
            p1.push(ans1);
            pa.push(ansa);
            pA.push(ansA);
        }
        else if(s[i]=='^')
        {
            int p0t=p0.top();
            p0.pop();
            int p0st=p0.top();
            p0.pop();
            int p1t=p1.top();
            p1.pop();
            int p1st=p1.top();
            p1.pop();
            int pat=pa.top();
            pa.pop();
            int past=pa.top();
            pa.pop();
            int pAt=pA.top();
            pA.pop();
            int pAst=pA.top();
            pA.pop();
            ll ans0=((pat*past)%998244353+(p0t*p0st)%998244353+(p1t*p1st)%998244353+(pAst*pAt)%998244353)%998244353;
            ll ans1=((p0t*p1st)%998244353+(p1t*p0st)%998244353+(pat*pAst)%998244353+(pAt*past)%998244353)%998244353;
            ll ansa=((pat*p0st)%998244353+(past*p0t)%998244353+(p1t*pAst)%998244353+(p1st*pAt)%998244353)%998244353;
            ll ansA=((pat*p1st)%998244353+(past*p1t)%998244353+(p0st*pAt)%998244353+(pAst*p0t)%998244353)%998244353;
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
    ll ans0=((p0.top()%998244353)*modInverse(power(4,count),998244353))%998244353;
    ll ans1=((p1.top()%998244353)*modInverse(power(4,count),998244353))%998244353;
    ll ansa=((pa.top()%998244353)*modInverse(power(4,count),998244353))%998244353;
    ll ansA=((pA.top()%998244353)*modInverse(power(4,count),998244353))%998244353;
    cout<<ans0<<" "<<ans1<<" "<<ansa<<" "<<ansA<<endl;
    //cout<<p0.size()<<p1.size()<<pa.size()<<pA.size()<<endl;
    //cout<<p0.top()*power(4,count)<<" "<<p1.top()*power(4,count)<<" "<<pa.top()*power(4,count)<<" "<<pA.top()*power(4,count)<<endl;
    //cout<<modInverse(p0.top()*power(4,count),998244353)<<" "<<modInverse(p1.top()*power(4,count),998244353)<<" "<<modInverse(pa.top()*power(4,count),998244353)<<" "<<modInverse(pA.top()*power(4,count),998244353)<<endl;
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