#include <iostream>
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
ll ipower(ll x, ll y) 
{ 
    ll res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = res*x; 
   
        // y must be even now 
        y = y>>1; // y = y/2 
        x = x*x;  // Change x to x^2 
    } 
    return res; 
}
void DSUinit(vector<ll>&a,vector<ll>&size,ll n)
{
    FOR(i,0,n)
    {
        a[i]=i;
        size[i]=1;
    }
    return;
}
ll root(vector<ll>&a,ll i)
{
    return (i==a[i])?i:a[i]=root(a,a[i]);
}
bool DSUfind(vector<ll>a,ll x,ll y)
{
    if(root(a,x)==root(a,y))
    {
        return true;
    }
    return false;
}
void DSUunion(vector<ll>&a,vector<ll>&size, ll x,ll y)
{
    x=root(a,x);
    y=root(a,y);
    if(x==y)
    {
        return;
    }
    if(size[x]<size[y]) swap(x,y);
    a[y]=x;
    size[x]+=size[y];
}
void dfs(vector<vector<ll> >&graph,vector<bool>&visited,ll start)
{
    visited[start]=true;
    FOR(i,0,graph[start].size())
    {
        if(!(visited[graph[start][i]]))
        {
            dfs(graph,visited,graph[start][i]);
        }
    }
    return;
}
ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;
    x = x % p;
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
} 
  
bool miillerTest(ll d, ll n) 
{ 
    ll a = 2 + rand() % (n - 4); 
  
    ll x = power(a, d, n); 
  
    if (x == 1  || x == n-1) 
       return true; 
    while (d != n-1) 
    { 
        x = (x * x) % n; 
        d *= 2; 
  
        if (x == 1)      return false; 
        if (x == n-1)    return true; 
    } 
  

    return false; 
} 
  

bool isPrime(ll n, ll k) 
{ 

    if (n <= 1 || n == 4)  return false; 
    if (n <= 3) return true; 
  

    int d = n - 1; 
    while (d % 2 == 0) 
        d /= 2; 
  

    for (ll i = 0; i < k; i++) 
         if (!miillerTest(d, n)) 
              return false; 
  
    return true; 
} 
double Square(double n, double i, double j) 
{ 
    double mid = (i + j) / 2; 
    double mul = mid * mid; 
  
    // If mid itself is the square root, 
    // return mid 
    if ((mul == n) || (abs(mul - n) < 0.00001)) 
        return mid; 
  
    // If mul is less than n, recur second half 
    else if (mul < n) 
        return Square(n, mid, j); 
  
    // Else recur first half 
    else
        return Square(n, i, mid); 
} 
  
// Function to find the square root of n 
ll findSqrt(double n) 
{ 
    double i = 1; 
  
    // While the square root is not found 
    bool found = false; 
    while (!found) { 
  
        // If n is a perfect square 
        if (i * i == n) { 
            //cout << fixed << setprecision(0) << i; 
            return (long long) i;
            found = true; 
        } 
        else if (i * i > n) { 
  
            // Square root will lie in the 
            // interval i-1 and i 
            double res = Square(n, i - 1, i); 
            //cout << fixed << setprecision(5) << res; 
            return -1;
            found = true; 
        } 
        i++; 
    } 
} 
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll>primes;
    FOR(i,2,1000006)
    {
        if(isPrime(i,6))
            primes.pb(i);
    }
    ll mod=ipower(2,30);
    //vector<ll>sqprimes(primes.size());
    // FOR(i,0,primes.size())
    // {
    //     sqprimes[i]=primes[i]*primes[i];
    // }
    // FOR(i,0,primes.size())
    // {
    //     cout<<primes[i]<<" ";
    // }
    // cout<<"\n";
    ll counts=0;
    ll a,b,c;
    cin>>a>>b>>c;
    unordered_map<ll,ll>sol;
    FOR(x,1,a+1)
    {
        FOR(y,1,b+1)
        {
            FOR(z,1,c+1)
            {
                ll n=x*y*z;
                // if(sol.count(n)>0)
                // {
                //     counts=(counts+sol[n])%mod;
                //     continue;
                // }
                //cout<<"starting "<<n<<"\n";
                ll ans=1;
                FOR(i,0,primes.size())
                {
                    ll p=primes[i];
                    if(p*p*p>n)
                    {
                        break;
                    }
                    //cout<<p<<"\n";
                    ll c=1;
                    while(n%p==0)
                    {
                        n/=p;
                        c+=1;
                    }
                    ans=(ans*c)%mod;
                }
                // cout<<ans<<"\n";
                ll q=findSqrt(n);
                if(isPrime(n,7))
                {
                    // cout<<"*"<<"\n";
                    ans=(ans*2)%mod;
                }
                else if(q!=1 and isPrime(q,7) )
                {
                    // cout<<"&"<<"\n";
                    ans=(ans*3)%mod;
                }
                else if(n!=1)
                {
                    // cout<<"%"<<"\n";
                    ans=(ans*4)%mod;
                }
                // cout<<n<<" "<<ans<<"\n";
                //sol[n]=ans;
                counts=(counts+ans)%mod;
            }
        }
    }
    cout<<counts<<"\n";
    return 0;
}